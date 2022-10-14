#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define ll long long int
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1,INF=0x3f3f3f3f;
int n,k,ans,fa[N];
int a[N],b[N],tag[N];
char st[N];
ll siz[N];
V input(){
	n=getint(),k=getint();
	char ch=gc;
	while(ch!='0'&&ch!='1')ch=gc;
	FOR(i,1,n)st[i]=ch,ch=gc;
	FOR(i,1,k){
		int cnt,x;
		cnt=getint();
		while(cnt--){
			x=getint();
			if(!a[x])a[x]=i;
			else b[x]=i;
		}
	}
}
V init(){
	FOR(i,1,k+k)fa[i]=i;
	FOR(i,k+1,k+k)siz[i]=1;
}
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll val(int p){
	return min(siz[find(p)],siz[find(p+k)]);
}
V merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y,siz[y]+=siz[x];
}
V work(){
	FOR(i,1,n){
		if(!a[i])goto end;
		if(!b[i]){
			ans-=val(a[i]);
			if(st[i]=='1')
				siz[find(a[i]+k)]+=INF;
			else
				siz[find(a[i])]+=INF;
			ans+=val(a[i]);
			goto end;
		}
		if(st[i]=='0'){
			if(find(a[i])!=find(b[i]+k)){
				ans-=val(a[i])+val(b[i]);
				merge(a[i],b[i]+k),merge(a[i]+k,b[i]);
				ans+=val(a[i]);
			}
		}
		else if(find(a[i])!=find(b[i])){
			ans-=val(a[i])+val(b[i]);
			merge(a[i],b[i]),merge(a[i]+k,b[i]+k);
			ans+=val(a[i]);
		}
		end:cout<<ans<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}