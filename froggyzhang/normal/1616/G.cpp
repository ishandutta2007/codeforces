//https://www.luogu.com.cn/blog/173660/solution-cf1616g
// 
#include<bits/stdc++.h>
using namespace std;
#define N 150050
typedef long long ll;
int n,m,nxt[N];
int dp[N][2];
bool ok[N];
vector<int> G[N];
void Solve(){
	cin>>n>>m;
	for(int i=0;i<=n+1;++i)ok[i]=0,G[i].clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if(v==u+1)ok[u]=1;
		else G[v].push_back(u);
	}
	for(int i=2;i<=n;++i)G[i].push_back(0);
	for(int i=1;i<n;++i)G[n+1].push_back(i);
	ok[n]=ok[0]=1;
	nxt[n+1]=n+1;
	for(int i=n;i>=1;--i){
		nxt[i]=ok[i]?nxt[i+1]:i;
	}
	if(nxt[1]==n+1){
		cout<<1LL*n*(n-1)/2<<'\n';
		return;
	}
	memset(dp,0,sizeof(dp));
	ll ans=0;
	dp[nxt[1]+1][0]=1;
	dp[nxt[1]+1][1]=2;
	for(int i=nxt[1]+2;i<=n+1;++i){
		for(int c=0;c<2;++c){
			for(auto v:G[i]){
				if(i<=nxt[v+1]+1){
					dp[i][c]|=dp[v+1][c^1];
				}
			}
		}
	}
	for(int i=nxt[1]+1;i>=1;--i){
		for(int c=0;c<2;++c){
			for(auto v:G[i]){
				if(i<=nxt[v+1]+1){
					dp[v+1][c^1]|=dp[i][c];
				}
			}
		}
	}
	int lc[4]={},rc[4]={};
	for(int i=1;i<=nxt[1]+1;++i)++lc[dp[i][0]];
	for(int i=1;i<=n+1;++i)if(nxt[i]==n+1)++rc[dp[i][0]];
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(i&j)ans+=1LL*lc[i]*rc[j];
	if(nxt[nxt[1]+1]==n+1)--ans;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}