#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
int n,m,k,x;
ll dp[100005][11][3];
vector<int>edge[100005];
void dfs(int v,int u){
	ll DP[2][11][3]={};
	DP[0][0][0] = k-1;
	DP[0][1][1] = 1;
	DP[0][0][2] = m-k;
	int cur = 0,nxt = 1;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
		rep(j,11)rep(k,3)DP[nxt][j][k]=0;
		for(int a=0;a<=x;a++){
			if(dp[edge[v][i]][a][0]){
				for(int f=a;f<=x;f++)
					rep(e,3){
						DP[nxt][f][e]+=dp[edge[v][i]][a][0]*DP[cur][f-a][e]%mod;
						DP[nxt][f][e]%=mod;
					}
			}
			if(dp[edge[v][i]][a][1]){
				for(int f=a;f<=x;f++)
					rep(e,1){
						DP[nxt][f][e]+=dp[edge[v][i]][a][1]*DP[cur][f-a][e]%mod;
						DP[nxt][f][e]%=mod;
					}
			}
			if(dp[edge[v][i]][a][2]){
				for(int f=a;f<=x;f++)
					for(int e=0;e<=2;e+=2){
						DP[nxt][f][e]+=dp[edge[v][i]][a][2]*DP[cur][f-a][e]%mod;
						DP[nxt][f][e]%=mod;
					}
			}
		}
		swap(cur,nxt);
	}
	rep(i,11)rep(k,3)dp[v][i][k] = DP[cur][i][k];
}
int main(){
	cin>>n>>m;
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	cin>>k>>x;
	dfs(1,-1);ll ret = 0;
	rep(i,x+1)rep(j,3) ret+=dp[1][i][j];
	cout<<ret%mod<<endl;
}