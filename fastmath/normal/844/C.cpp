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
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 2e5 + 7;

vector <int> g[MAXN];
vector <int> comp[MAXN];
bool used[MAXN];
int k = 0;

void dfs(int u){
	used[u] = true;
	comp[k].push_back(u);

	for (int v : g[u]){
		if (!used[v]){
			dfs(v);
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
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a.begin(), a.end());

	for (int i = 0; i < n; ++i){
		int u = a[i].second;
		int v = i;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; ++i){
		if (!used[i]){
			dfs(i);
			++k;
		}
	}

	cout << k << '\n';
	for (int i = 0; i < k; ++i){
		cout << comp[i].size() << ' ';
		for (int elem: comp[i]){
			cout << elem + 1 << ' ';
		}

		cout << '\n';
	}

	return 0;
}