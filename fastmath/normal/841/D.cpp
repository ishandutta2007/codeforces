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

#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 3e5 + 7;

vector <pair <int, int> > g[MAXN];
int d[MAXN];
vector <int> ans;
bool used[MAXN];

bool dfs(int u, int last){
	used[u] = true;
	int _xor = 0;
	for (pair <int, int> v : g[u]){
		if (!used[v.x]){
			_xor ^= dfs(v.x, v.y);
		}
	}

	if (last != -1 && _xor != d[u]){
		ans.push_back(last);
	}

	return _xor != d[u];
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	bool good = false;
	int _xor = 0;

	for (int i = 0; i < n; ++i){
		cin >> d[i];

		if (d[i] == -1){
			good = true;
		}
		else{
			_xor ^= d[i];
		}
	}

	if (!good && _xor){
		cout << "-1\n";
		return 0;
	}

	if (good && _xor){
		for (int i = 0; i < n; ++i){
			if (d[i] == -1){
				d[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i){
		if (d[i] == -1){
			d[i] = 0;
		}
	}

	int u, v;
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		g[u - 1].push_back({ v - 1, i });
		g[v - 1].push_back({ u - 1, i });
	}

	dfs(0, -1);

	cout << ans.size() << '\n';
	for (int elem : ans){
		cout << elem + 1 << ' ';
	}

	return 0;
}