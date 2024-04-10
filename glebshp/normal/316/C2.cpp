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
const int size = 100;
const int inf = 1000 * 1000;
const int qsize = size * size;

int n, m;
int field[size][size];
bool used[size * size];
int q[size * size];
int dist[qsize];
int from[qsize];
int path[qsize];
int sz;
vector <pair <int, int> > g[2];

vector <pair <int, int> > vertex[qsize];

void add_edges(int v, int u) {
	vertex[v + 1].pb(mp(u + sz + 1, (field[g[0][v].fs][g[0][v].sc] != field[g[1][u].fs][g[1][u].sc])));
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &field[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			g[(i + j) % 2].pb(mp(i, j));
	sz = n * m / 2;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			if ((abs(g[0][i].fs - g[1][j].fs) + abs(g[0][i].sc - g[1][j].sc)) == 1)
				add_edges(i, j);
	for (int i = 0; i < sz; i++)
		vertex[0].pb(mp(i + 1, 0));
	for (int i = 0; i < sz; i++)
		vertex[sz + 1 + i].pb(mp(2 * sz + 1, 0));
	int ans = 0;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j <= 2 * sz + 1; j++) {
			dist[j] = inf;
			from[j] = -1;
		}
		q[0] = 0;
		dist[0] = 0;
		int qs = 0, qf = 1, v;
		while (qs != qf) {
			v = q[qs];
			used[v] = false;
			qs++;
			if (qs == qsize)
				qs = 0;
			for (int j = 0; j < vertex[v].size(); j++)
				if (dist[vertex[v][j].fs] > dist[v] + vertex[v][j].sc) {
					dist[vertex[v][j].fs] = dist[v] + vertex[v][j].sc;
					from[vertex[v][j].fs] = v;
					if (!used[vertex[v][j].fs]) {
						used[vertex[v][j].fs] = true;
						q[qf] = vertex[v][j].fs;
						qf++;
						if (qf == qsize)
							qf = 0;
					}
				}
		}
		ans += dist[sz * 2 + 1];
		int p = sz * 2 + 1;
		int pv;
		while (p != 0) {
			pv = from[p];
			for (int j = 0; j < vertex[pv].size(); j++) 
				if (vertex[pv][j].fs == p) {
					swap(vertex[pv][j], vertex[pv].back());
					vertex[p].pb(mp(pv, vertex[pv].back().sc * -1));
					vertex[pv].pop_back();
					break;
				}
			p = pv;
		}
	}

	cout << ans << endl;

	return 0;
}