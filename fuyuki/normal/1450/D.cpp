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
const int N=3e5+3,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,k,now,a[N],d[N],pre[N],nxt[N],op[N],ed[N];
V input(){
	n=getint(),a[0]=a[n+1]=-INF;
	FOR(i,1,n)a[i]=getint(),op[i]=INF,ed[i]=-INF,d[i]=0;
}
V init(){
	FOR(i,1,n)for(pre[i]=i-1;a[pre[i]]>=a[i];pre[i]=pre[pre[i]]);
	ROF(i,n,1)for(nxt[i]=i+1;a[nxt[i]]>=a[i];nxt[i]=nxt[nxt[i]]);
	FOR(i,1,n)cmin(op[a[i]],i),cmax(ed[a[i]],i);
}
V add(int l,int r){if(r=min(r,now),l<=r)d[l]++,d[r+1]--;}
V work(){
	FOR(i,1,n)if(op[i]<=ed[i]){
		int l=pre[op[i]]+1,r=nxt[ed[i]]-1,L=op[i],R=ed[i];
		now=n-i+1;
		if(L==R){
			if(l==L)add(R-L+1,r-L+1);
			else if(R==r)add(R-L+1,R-l+1);
			else{
				if(r-l+1!=1)add(1,1);
				add(r-l+1,r-l+1);
			}
		}
		else add(r-l+1,r-l+1);
	}
	FOR(i,1,n)d[i]+=d[i-1];
	FOR(i,1,n)cout<<(d[i]==n-i+1);
	cout<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}