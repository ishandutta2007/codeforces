#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> g[200000];
vector <int> color;
vector <bool> used;


void dfs(int u, int prev_color){
	used[u] = true;
	int now_color = 1;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if (!used[v]){
			while (now_color == color[u] || now_color == prev_color){
				++now_color;
			}
			color[v] = now_color++;
			dfs(v, color[u]);
		}
	}
}


int main(){
	int n; 
	cin >> n;

	int u, v;
	for (int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans = max(ans, (int)g[i].size());
	}

	cout << ans + 1 << endl;
	color.resize(n);
	used.resize(n);
	color[0] = 1;
	dfs(0, -1);
	for (int i = 0; i < n; i++){
		cout << color[i] << ' ';
	}

	return 0;
}