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
const int size = 5 * 1000 + 10;

int n;
int ans;
int sum;
int mxdif;

int f[size], g[size], h[size];
vector <pair <int, int> > vertex[size];

void calc_all(int v, int fr) {
	h[v] = 0;
	for (int i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != fr) {
			calc_all(vertex[v][i].fs, v);

			h[v] += h[vertex[v][i].fs] + vertex[v][i].sc;
		}

	g[v] = h[v];
	for (int i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != fr) {
			g[v] = min(g[v], h[v] - h[vertex[v][i].fs] - vertex[v][i].sc + g[vertex[v][i].fs] + (1 - vertex[v][i].sc));
		}

	f[v] = g[v];
	for (int i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != fr) {
			if (vertex[v][i].sc == 0)
				f[v] = min(f[v], h[v] - h[vertex[v][i].fs] + f[vertex[v][i].fs]);
			else {
				f[v] = min(f[v], h[v] - h[vertex[v][i].fs] - 1 + g[vertex[v][i].fs]);
				f[v] = min(f[v], h[v] - h[vertex[v][i].fs] + f[vertex[v][i].fs]);
			}
		}
}

void dfs(int v, int fr) {
	for (int i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != fr)
			if (vertex[v][i].sc == 0) {
				dfs(vertex[v][i].fs, v);
			} else {
				calc_all(vertex[v][i].fs, v);

				sum += 1 + h[vertex[v][i].fs];
				mxdif = max(mxdif, h[vertex[v][i].fs] - f[vertex[v][i].fs]);
				mxdif = max(mxdif, h[vertex[v][i].fs] + 1 - g[vertex[v][i].fs]);
			}
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	cin >> n;
	ans = n - 1;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		vertex[a].pb(mp(b, 0));
		vertex[b].pb(mp(a, 1));
	}

	for (int i = 0; i < n; i++) {
		sum = 0;
		mxdif = 0;
		dfs(i, -1);

		ans = min(ans, sum - mxdif);
	}

	cout << ans << endl;

	return 0;
}