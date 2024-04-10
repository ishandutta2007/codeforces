#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int n,k,a[N],b[N],s[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
I check(int x){
	FOR(i,1,n)
		if(a[i]>=x)b[i]=1;
		else b[i]=-1;
	FOR(i,1,n)s[i]=s[i-1]+b[i];
	int w=0;
	FOR(i,k,n){
		cmin(w,s[i-k]);
		if(s[i]-w>0)return 1;
	}
	return 0;
}
V work(){
	int l=1,r=n,mid;
	while(mid=l+r>>1,l^r)
		if(check(mid+1))l=mid+1;
		else r=mid;
	cout<<mid<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}