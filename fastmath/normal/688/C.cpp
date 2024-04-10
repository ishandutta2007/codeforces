#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define x first
#define y second
#define prev _prev
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

vector <int> g[MAXN];
int color[MAXN];
bool used[MAXN];

void dfs(int u, int c){
	color[u] = c;
	used[u] = true;

	for (int v : g[u]){
		if (!used[v]){
			dfs(v, color[u] ^ 1);
		}
		else if (color[v] == color[u]){
			cout << "-1\n";
			exit(0);
		}
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	vector <int> ans1, ans2;
	for (int i = 0; i < n; ++i){
		if (!used[i]){
			dfs(i, 0);
		}

		if (!color[i]){
			ans1.push_back(i);
		}
		else{
			ans2.push_back(i);
		}
	}


	cout << ans1.size() << '\n';
	for (int elem : ans1){
		cout << elem + 1 << ' ';
	}

	cout << '\n';

	cout << ans2.size() << '\n';
	for (int elem : ans2){
		cout << elem + 1 << ' ';
	}

	return 0;
}