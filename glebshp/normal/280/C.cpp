#pragma comment(linker, "/STACK:1000000000")
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
const int size = 100 * 1000 + 100;

vector <int> vertex[size];
int n;
int deg[size];
double ans;

void dfs(int v, int fr, int d) {
	ans += 1.0 / d;

	for (int i = 0; i < vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			dfs(vertex[v][i], v, d + 1);

		}
	}
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		vertex[a].pb(b);
		vertex[b].pb(a);
	}

	ans = 0;

	dfs(0, 0, 1);

	cout.precision(20);

	cout << ans << endl;

	return 0;
}