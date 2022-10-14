#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=3e6+1;
int n,k,m,maxn,sum,tot;
int p[N],d[N],tmp[N],c[N],t[N];
char a[N];
V input(){
	scanf("%d%d%s",&n,&k,a+1);
}
V init(){
	FOR(i,1,n)FOR(j,i+1,n)
		sum+=a[i]=='R'&&a[j]=='L';
	FOR(i,1,n)if(a[i]=='R')p[++m]=i;
	FOR(i,1,m)maxn=max(d[i]=n-(m-i)-p[i]+(p[i]==p[i+1]),maxn);
}
V work(){
	if(sum<k)return void(cout<<"-1\n");
	int x=m;
	FOR(i,1,k){
		while(m&&p[m]==n)n--,m--;
		for(x=m;x>0;x--){
			c[++tot]=p[x];
			swap(a[p[x]],a[p[x]+1]),p[x]++;
			if(--sum==k-i)break;
			if(x&&p[x]==p[x-1]+2){
				x--;
				while(x&&p[x]==p[x-1]+1)x--;
			}
		}
		t[i]=tot;
	}
	if(sum)return void(cout<<"-1\n");
	FOR(i,1,k){
		cout<<t[i]-t[i-1]<<' ';
		FOR(j,t[i-1]+1,t[i])cout<<c[j]<<" \n"[j==t[i]];
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}