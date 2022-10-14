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
const int N=2e5+1,mod=998244353,INF=0x3f3f3f3f;
V cmax(ll&x,ll y){if(x-y>>63)x=y;}
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
ll dp[N];
vector<int>t[N],e[N];
int n,T,x,y,a[N],lim,d,dep[N],tmp[N],pre[N];
ll val[N];
I cmp(int x,int y){return a[x]<a[y];}
V dfs(int u){
	t[dep[u]].push_back(u),cmax(d,dep[u]);
	for(int v:e[u])
		dep[v]=dep[u]+1,dfs(v);
}
V input(){
	int minn=INF,maxn=0;
	ll w,v;
	n=getint(),d=0;
	FOR(i,1,n)t[i].clear(),dp[i]=0,e[i].clear();
	FOR(i,2,n)e[pre[i]=getint()].push_back(i);
	dfs(1);
	FOR(i,2,n)a[i]=getint();
	for(int v:t[d])dp[v]=0;
	ROF(i,d,1){
		sort(t[i].begin(),t[i].end(),cmp);
//		cout<<"a: ";for(int v:t[i])cout<<a[v]<<' ';cout<<'\n';
//		cout<<"dp: ";for(int v:t[i])cout<<dp[v]<<' ';cout<<'\n';
		minn=a[t[i].front()],maxn=a[t[i].back()];
		for(int u:t[i])
			cmax(dp[pre[u]],dp[u]+max(maxn-a[u],a[u]-minn));
		w=-INF,reverse(t[i].begin(),t[i].end());
		for(int u:t[i])cmax(w,dp[u]+a[u]),val[u]=w;
		w=-INF,v=0,reverse(t[i].begin(),t[i].end());
		for(int u:t[i]){
			cmax(w,dp[u]-a[u]);
			cmax(dp[pre[u]],max(a[u]+w,val[u]-a[u]));
		}
	}
	cout<<dp[1]<<'\n';
}
V init(){
	
}
V work(){
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}