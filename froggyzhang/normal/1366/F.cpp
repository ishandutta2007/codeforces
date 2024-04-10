#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 2020
const int mod=1e9+7;
const ll inf=0x3f3f3f3f3f3fll;
const int inv2=(mod+1)/2;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,Q,ans;
ll dp[N][N],mx[N];
vector<pair<int,int> > G[N];
int Jiao(pair<int,ll> a,pair<int,ll> b){
	return (a.second-b.second)/(b.first-a.first);
}
int top;
pair<int,ll> st[N],p[N];
ll Val(pair<int,ll> qwq,int x){
	return 1LL*qwq.first*x+qwq.second;
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		ll w=read();
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
		mx[u]=max(mx[u],w);
		mx[v]=max(mx[v],w);
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[1][0]=0;
	for(int j=1;j<=n;++j){
		for(int u=1;u<=n;++u){
			for(auto qwq:G[u]){
				int v=qwq.first;
				ll w=qwq.second;
				dp[v][j]=max(dp[v][j],dp[u][j-1]+w);
			}
		}
	}
	for(int u=1;u<=n;++u){
		ll b=-inf;
		for(int j=0;j<=n;++j){
			if(dp[u][j]>-inf){
				b=max(b,dp[u][j]-j*mx[u]);
			}
		}
		p[u]=make_pair(mx[u],b);
	}
	for(int j=1;j<=min(n,Q);++j){
		ll mx=0;
		for(int u=1;u<=n;++u){
			mx=max(mx,dp[u][j]);
		}
		ans=(ans+mx)%mod;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		while(top&&p[i].second>=st[top].second)--top;
		while(top>1&&Jiao(st[top],p[i])<=Jiao(st[top],st[top-1]))--top;
		st[++top]=p[i];
	}
	for(int i=1;i<=top;++i){
		int l=(i==1?n:max(n,Jiao(st[i-1],st[i]))),r=(i==top?Q:min(Q,Jiao(st[i],st[i+1])));
		if(l>=r)continue;
		ans=(ans+1LL*(r-l)*(Val(st[i],l+1)%mod+Val(st[i],r)%mod)%mod*inv2%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}