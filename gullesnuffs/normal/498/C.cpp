#include <bits/stdc++.h>

using namespace std;

int a[105];
set<int> primes;
int from[105], to[105];
int times[105];
int n, m;
int offs[105];
vector<int> adj[2][5000];
int conn[2][100005];
bool vis[2][100005];

bool dfs(int node){
	if(vis[0][node])
		return 0;
	vis[0][node]=1;
	for(int i=0; i < adj[0][node].size(); ++i){
		int t=adj[0][node][i];
		if(conn[1][t] == -1){
			conn[1][t]=node;
			conn[0][node]=t;
			return 1;
		}
		if(dfs(conn[1][t])){
			conn[1][t]=node;
			conn[0][node]=t;
			return 1;
		}
	}
	return 0;
}

int solve(int p){
	int nodes[2]={0,0};
	for(int i=0; i < n; ++i){
		int x=a[i];
		times[i]=0;
		offs[i]=nodes[i%2];
		while(x%p == 0){
			++times[i];
			conn[i%2][nodes[i%2]]=-1;
			adj[i%2][nodes[i%2]].clear();
			++nodes[i%2];
			x/=p;
		}
	}
	for(int i=0; i < m; ++i){
		int f=from[i], t=to[i];
		for(int j=0; j < times[f]; ++j)
			for(int k=0; k < times[t]; ++k){
				adj[f%2][offs[f]+j].push_back(offs[t]+k);
				adj[t%2][offs[t]+k].push_back(offs[f]+j);
			}
	}
	int ans=0;
	while(true){
		bool any=0;
		for(int j=0; j < 2; ++j)
		for(int i=0; i < nodes[j]; ++i)
			vis[j][i]=0;
		for(int i=0; i < nodes[0]; ++i){
			if(conn[0][i] != -1)
				continue;
			if(dfs(i)){
				any=1;
				++ans;
			}
		}
		if(!any)
			break;
	}
	return ans;
}

int main(){
	cin >> n >> m;
	for(int i=0; i < n; ++i){
		cin >> a[i];
		int x=a[i];
		for(int j=2; j*j <= x; ++j){
			while(x%j == 0){
				primes.insert(j);
				x/=j;
			}
		}
		if(x > 1)
			primes.insert(x);
	}
	for(int i=0; i < m; ++i){
		cin >> from[i] >> to[i];
		--from[i];
		--to[i];
	}
	int ans=0;
	for(auto it=primes.begin(); it != primes.end(); ++it)
		ans += solve(*it);
	cout << ans << endl;
}