#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

vector<vector<int>> a;
vector<char> used;
vector<int> color;
vector<int> p;

void dfs(int v){
	used[v] = 1;

	int i = 0;
	for (auto x : a[v]){
		if (used[x])
			continue;
		while (i == color[v])
			i++;
		color[x] = i;
		p[x] = v;
		dfs(x);
		i++;
	}
}

void solve(){
	int n = nxt();
	a.resize(n);
	map<pair<int, int>, int> ed;
	for (int i = 0; i < n - 1; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
		if (u > v)
			swap(u, v);
		ed[make_pair(u, v)] = i + 1;
	}

	used.resize(n);
	color.resize(n, -1);
	p.resize(n);
	dfs(0);

	int d = *max_element(all(color)) + 1;
	vector<vector<pair<int, int>>> ans(d);
	for (int i = 0; i < n; i++){
		if (color[i] > -1){
			ans[color[i]].push_back({i, p[i]});
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < d; i++){
		printf("%d", (int)ans[i].size());
		for (auto p : ans[i]){
			if (p.second < p.first)
				swap(p.first, p.second);
			printf(" %d", ed[p]);
		}
		puts("");
	}
}

int main(){

	solve();

	return 0;
}