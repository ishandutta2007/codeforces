#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 100 * 1000;

int n, a, b;
vector <int> vertex[size];

unsigned long long la[size];
unsigned long long ans = 0;
unsigned long long sz[size];

void dfs(int v, int fr) {
	sz[v] = 1;
	unsigned long long cur = 0;

	for (int i = 0; i < vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			dfs(vertex[v][i], v);
			sz[v] += sz[vertex[v][i]];
		}
	}

	la[v] += n - sz[v];
	cur = n - sz[v] + 1;

	for (int i = 0; i < vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			la[v] += sz[vertex[v][i]] * 1ll * cur;
			cur += sz[vertex[v][i]];
		}
	}

	for (int i = 0; i < vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			ans += (sz[vertex[v][i]] * (sz[vertex[v][i]] - 1) / 2) * (la[v] - sz[vertex[v][i]] * (n - sz[vertex[v][i]]));
			ans += (la[vertex[v][i]] - sz[vertex[v][i]] * (n - sz[vertex[v][i]])) * (n - sz[vertex[v][i]]) * (n - sz[vertex[v][i]] - 1) / 2;
		}
	}
}

int main() {
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		vertex[a].pb(b);
		vertex[b].pb(a);
	}

	dfs(0, 0);
	cout << ans << endl;


	return 0;
}