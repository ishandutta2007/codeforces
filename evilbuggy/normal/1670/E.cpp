#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;

vector<int> g[maxn];
vector<pair<int, int> > arr;
int a[maxn], b[maxn], c[maxn], d[maxn];

void dfs(int v, int p, int flg){
	for(int i : g[v]){
		int u = a[i]^b[i]^v;
		if(u == p)continue;
		if(flg){
			c[u] = arr.back().first;
			d[i] = arr.back().second;
		}else{
			c[u] = arr.back().second;
			d[i] = arr.back().first;
		}
		arr.pop_back();
		dfs(u, v, flg^1);
	}
}

void solve(){
	int p;
	cin >> p;
	int n = 1 << p;
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	for(int i = 2; i <= n; i++){
		cin >> a[i] >> b[i];
		g[a[i]].emplace_back(i);
		g[b[i]].emplace_back(i);
	}
	arr.clear();
	for(int i = 1; i < n; i++){
		arr.emplace_back(i, i + n);
	}
	c[1] = n;
	dfs(1, 0, 1);
	cout << 1 << '\n';
	for(int i = 1; i <= n; i++){
		cout << c[i] << ' ';
	}
	cout << '\n';
	for(int i = 2; i <= n; i++){
		cout << d[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}