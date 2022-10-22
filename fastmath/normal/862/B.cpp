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

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int color[MAXN];
bool used[MAXN];
vector <int> g[MAXN];

void dfs(int u, int c){
	color[u] = c;
	used[u] = true;

	for (int v : g[u]){
		if (!used[v]){
			dfs(v, c ^ 1);
		}
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int u, v;
	for (int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	dfs(0, 0);
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i){
		if (!color[i]){
			++a;
		}
		else{
			++b;
		}
	}

	cout << a * b - (n - 1);
	return 0;
}