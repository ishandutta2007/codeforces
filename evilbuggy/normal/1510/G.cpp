#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 105;
vector<int> g[N];
int p[N], dep[N], col[N];

void dfs(int v){
	for(int u : g[v]){
		dep[u] = dep[v] + 1;
		dfs(u);
	}
}

void dfs2(int v, int &k, vector<int> &ans){
	if(col[v] != 0){
		ans.push_back(v);
	}else{
		assert(k > 0);
		ans.push_back(v);
		k -= 1;
	}
	for(int u : g[v]){
		if(col[u] == 0){
			if(k > 0){
				dfs2(u, k, ans);
				ans.push_back(v);
			}
		}
	}
	for(int u : g[v]){
		if(col[u] != 0){
			dfs2(u, k, ans);
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		p[1] = -1;
		for(int i = 2; i <= n; i++){
			cin >> p[i];
			g[p[i]].push_back(i);
		}
		dep[1] = 1; dfs(1);
		int ind = 1;
		for(int i = 1; i <= n; i++){
			if(dep[i] == k){
				ind = i;
				break;
			}else if(dep[i] > dep[ind]){
				ind = i;
			}
		}
		memset(col, 0, sizeof(col));
		col[ind] = 2; k -= 1;
		while(ind != 1){
			ind = p[ind];
			col[ind] = 1;
			k -= 1;
		}
		vector<int> ans;
		dfs2(1, k, ans);
		cout << int(ans.size()) - 1 << '\n';
		for(int x : ans){
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}