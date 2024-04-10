#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,INF=0x3f3f3f3f;
P t[N*6];
int n,tot,cnt,ans;
int a[6],b[N],c[N];
V input(){
	FOR(i,0,5)a[i]=getint();
	n=getint();
	FOR(i,1,n)b[i]=getint();
}
V init(){
	FOR(i,1,n)FOR(j,0,5)t[++tot]=P(b[i]-a[j],i);
	sort(t+1,t+1+tot),ans=INF;
}
V ins(int x){cnt+=!c[x]++;}
V del(int x){cnt-=!--c[x];}
V work(int p=1){
	FOR(i,1,tot){
		ins(t[i].second);
		while(cnt==n){
			ans=min(ans,t[i].first-t[p].first);
			del(t[p++].second);
		}
	}
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}