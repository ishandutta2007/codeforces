#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll mod(ll m){
	return m%1000000007;
}
int n;
ll m,kk;
int x;
int u,v;
vector<int>adj[100001];
vector<int>c[100001];
bool vis[100001];
ll dp4[100001][11][3];
ll dp[2][11],dp2[2][11],dp3[2][11];
void dfs(int id){
	vis[id]=true;
	c[id].push_back(0);
	for(int i=0; i<adj[id].size() ;i++){
		int newi=adj[id][i];
		if(vis[newi]) continue;
		c[id].push_back(newi);
		dfs(newi);
	}
}
void cal(int id){
	int s=c[id].size()-1;
	for(int i=1; i<=s ;i++){
		cal(c[id][i]);
	}
	for(int i=0; i<2 ;i++){
		for(int j=0; j<=x ;j++){
			dp[i][j]=dp2[i][j]=dp3[i][j]=0;
		}
	}
	dp[0][0]=dp2[0][0]=dp3[0][0]=1;
	for(int i=1; i<=s ;i++){
		int cur=i&1,last=(i&1)^1;
		for(int j=0; j<=x ;j++) dp[cur][j]=dp2[cur][j]=dp3[cur][j]=0;
		for(int j=0; j<=x ;j++){
			for(int k=0; k<=j ;k++){
				dp[cur][j]=mod(dp[cur][j]+dp[last][k]*(dp4[c[id][i]][j-k][0]+dp4[c[id][i]][j-k][1]+dp4[c[id][i]][j-k][2]));//1 to k-1
				dp2[cur][j]=mod(dp2[cur][j]+dp2[last][k]*(dp4[c[id][i]][j-k][0]));//k
				dp3[cur][j]=mod(dp3[cur][j]+dp3[last][k]*(dp4[c[id][i]][j-k][0]+dp4[c[id][i]][j-k][2]));
			}
			//cout << i << ' ' << j << ' ' << dp[cur][j] << ' ' << dp2[cur][j] << ' ' << dp3[cur][j] << endl;
		}
	}
	int cur=s&1;
	for(int j=0; j<=x ;j++){
		dp4[id][j][0]=mod((kk-1)*dp[cur][j]);
		if(j!=0) dp4[id][j][1]=dp2[cur][j-1];
		dp4[id][j][2]=mod((m-kk)*dp3[cur][j]);
		//cout << id << ' ' << j << ' ' << dp4[id][j][0] << ' ' << dp4[id][j][1] << ' ' << dp4[id][j][2] << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<n ;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> kk >> x;
	dfs(1);
	cal(1);
	ll ans=0;
	for(int i=0; i<=x ;i++){
		ans+=dp4[1][i][0]+dp4[1][i][1]+dp4[1][i][2];
		ans=mod(ans);
	}
	cout << ans << endl;
}