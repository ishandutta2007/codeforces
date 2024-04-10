/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 20; 
const int inf = 1e9;
const int MASK = 1<<18;
int n,m,w[MAXN][MAXN],u,v,in[MAXN],ans[MAXN];
int dp[MASK],last[MASK],pre[MASK],sub[MASK];
inl void print(int s,int val){
	if(!s) return ;
	int nw=s^last[s];
	rep(i,1,n) if((s>>i-1)&1) ans[i]=val;
	print(last[s],val+1);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),read(w[u][v]),in[v]|=(1<<u-1);
	int all=(1<<n)-1;
	rep(s,1,all) {
		int u=log2(lb(s))+1,last=s^lb(s);
		sub[s]=sub[last];
		rep(i,1,n) if((s>>i-1)&1) pre[s]|=in[i];
		rep(i,1,n) 
			if((s>>i-1)&1) sub[s]-=w[i][u];
			else sub[s]+=w[u][i];
	}
	rep(s,1,all) dp[s]=inf;
	rep(s,0,all) {
		if(dp[s]==inf) continue;
		int nw=all^s;
		for(int t=nw;t;t=(nw&(t-1))){
			if((pre[t]&s)==pre[t]){
				if(ylmin(dp[s|t],dp[s]+sub[s])) last[s|t]=s;
			}
		}
	}
	print(all,0);
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}