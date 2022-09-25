#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline ll read(){
	ll x=0,f=1;
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
int n,a[N],b[N];
ll dp[N][2],ans;
vector<int> G[N];
void dfs(int u,int fa){
	int ta=0,tb=0;
	ll s=0;
	vector<ll> A;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(b[u]<b[v])s+=dp[v][0],++ta;
		else if(b[u]>b[v])s+=dp[v][1],++tb;
		else{
			++ta;
			s+=dp[v][0];
			A.push_back(dp[v][1]-dp[v][0]);
		}
	}
	sort(A.begin(),A.end());
	for(int i=-1;i<(int)A.size();++i){
		if(~i){
			s+=A[i],--ta,++tb;
		}
		if(u==1){
			ans=min(ans,s+1LL*max(ta,tb)*a[1]);
		}
		else{
			dp[u][0]=min(dp[u][0],s+1LL*max(ta,tb+1)*a[u]);
			dp[u][1]=min(dp[u][1],s+1LL*max(ta+1,tb)*a[u]);
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ans=inf;
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}