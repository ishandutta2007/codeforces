#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
int n;
ll dp[200001],dp2[200001],dp3[200001],dp4[200001];//killed dad, dad was dead, dad killed you,someone killed you before dad
vector<pair<int,int> >adj[200001];
void dfs(int id,int p){
	sort(adj[id].begin(),adj[id].end());
	int pw=0;
	for(auto cur:adj[id]){
		if(cur.se==p){
			pw=cur.fi;continue;
		}
		dfs(cur.se,id);
	}
	//case 1: killed dad
	ll z1=1,z2=0;
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		if(cur.fi<pw){
			z2=0;
			z1=(z1*(dp4[cur.se]+dp3[cur.se]))%mod;
		}
		else{
			z2=(z2*(dp2[cur.se])+z1*(dp[cur.se]))%mod;
			z1=(z1*(dp3[cur.se]+dp4[cur.se]))%mod;
		}
	}
	dp[id]=(z1+z2)%mod;
	z1=1,z2=0;
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		z2=(z2*(dp2[cur.se])+z1*(dp[cur.se]))%mod;
		z1=(z1*(dp3[cur.se]+dp4[cur.se]))%mod;
	}
	dp2[id]=(z1+z2)%mod;
	z1=1,z2=0;
	for(auto cur:adj[id]){
		if(cur.se==p){
			z2=z1;z1=0;continue;
		}
		if(cur.fi<pw){
			z2=0;
			z1=(z1*(dp4[cur.se]+dp3[cur.se]))%mod;
		}
		else z2=(z2*dp2[cur.se])%mod;
	}
	dp3[id]=z2;
	z1=1,z2=0;
	for(auto cur:adj[id]){
		if(cur.se==p){
			z1=0;continue;
		}
		if(cur.fi<pw){
			z2=(z2*(dp2[cur.se])+z1*(dp[cur.se]))%mod;
			z1=(z1*(dp3[cur.se]+dp4[cur.se]))%mod;
		}
		else z2=(z2*dp2[cur.se])%mod;
	}
	dp4[id]=z2;
	//cout << id << ' ' << dp[id] << ' ' << dp2[id] << ' ' << dp3[id] << ' ' << dp4[id] << endl;
}
int u[200001],v[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back({i,v});
		adj[v].push_back({i,u});
	}
	dfs(1,0);
	cout << dp2[1] << endl;
}