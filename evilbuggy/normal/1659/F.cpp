#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

vector<int> g[maxn];
int p[maxn], q[maxn], vis[maxn];

inline int parity(int n){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		int v = i;
		while(!vis[v]){
			ans ^= 1;
			vis[v] = 1;
			v = p[v];
		}
		ans ^= 1;
	}
	return ans;
}

inline bool identity(int n){
	for(int i = 1; i <= n; i++){
		if(p[i] != i)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int x; cin >> x;
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		for(int i = 2; i <= n; i++){
			int u; cin >> u;
			int v; cin >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		for(int i = 1; i <= n; i++){
			cin >> q[i]; p[q[i]] = i;
		}
		if(identity(n)){
			cout << "Alice" << '\n';
			continue;
		}
		int root1 = -1;
		int root2 = -1;
		for(int i = 1; i <= n; i++){
			if(g[i].size() > 1){
				if(root1 == -1){
					root1 = i;
				}else{
					root2 = i;
				}
			}
		}
		if(root2 != -1){
			cout << "Alice" << '\n';
			continue;
		}
		if(p[root1] != root1){
			if(x == root1 || p[x] == root1){
				cout << "Bob" << '\n';
				continue;
			}
			for(int i = 1; i <= n; i++){
				if(p[i] == root1){
					swap(p[i], p[root1]);
					break;
				}
			}
			if(identity(n)){
				cout << "Alice" << '\n';
				continue;
			}
			x = root1;
		}
		if(x == root1){
			if(parity(n)){
				cout << "Alice" << '\n';
			}else{
				cout << "Bob" << '\n';
			}
		}else{
			int fixed = 0;
			for(int i = 1; i <= n; i++){
				if(p[i] == i)fixed++;
			}
			if(p[x] == x && fixed == n - 2){
				cout << "Alice" << '\n';
			}else if(parity(n)){
				cout << "Bob" << '\n';
			}else{
				cout << "Alice" << '\n';
			}
		}
	}

	return 0;
}