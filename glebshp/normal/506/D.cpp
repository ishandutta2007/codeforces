#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_d"

const double pi = acos(-1.0);
const int size = 100 * 1000 + 100;
const int ssize = 1000;
const int magic = 300;

int n, m;
vector <pair <int, int> > edges[size];
vector <int> vertex[size];

vector <int> vers[size];
bool mask[ssize][size];
int cnt = 0;
vector <int> cur;
bool used[size];
int q;
int vq[size], uq[size];
int ans[size];
int pcnt = 0;
pair <int, int> toadd[size]; 
pair <int, int> h[size];

vector <pair <pair <int, int>, int> > prs;


void dfs(int v) {
	used[v] = true;
	cur.pb(v);

	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (!used[vertex[v][i]])
			dfs(vertex[v][i]);
	}
}

int scnt[size];
int pst[size];

void sortpairs() {
	for (int i = 0; i < n; i++)
		scnt[i] = 0;
	for (int i = 0; i < pcnt; i++)
		scnt[toadd[i].sc]++;
	pst[0] = 0;
	for (int i = 1; i < n; i++) {
		pst[i] = pst[i - 1] + scnt[i - 1];
	}
	for (int i = 0; i < pcnt; i++)
		h[pst[toadd[i].sc]++] = toadd[i];
	for (int i = 0; i < pcnt; i++)
		toadd[i] = h[i];

	for (int i = 0; i < n; i++)
		scnt[i] = 0;
	for (int i = 0; i < pcnt; i++)
		scnt[toadd[i].fs]++;
	pst[0] = 0;
	for (int i = 1; i < n; i++) {
		pst[i] = pst[i - 1] + scnt[i - 1];
	}
	for (int i = 0; i < pcnt; i++)
		h[pst[toadd[i].fs]++] = toadd[i];
	for (int i = 0; i < pcnt; i++)
		toadd[i] = h[i];
}

void relaxpairs() {
	sortpairs();

	int p1 = 0;
	int p2 = 0;

	for (int i = 0; i < q; i++) {
		while (p1 < pcnt && toadd[p1] < prs[i].fs)
			p1++;
		while (p2 < pcnt && toadd[p2] <= prs[i].fs)
			p2++;
		ans[prs[i].sc] += p2 - p1;
	}

	pcnt = 0;
}

void addpair(int p, int q) {
	toadd[pcnt++] = mp(p, q);
	if (pcnt == n) {
		relaxpairs();
	}
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);

		v--, u--, c--;
		vers[c].pb(v);
		vers[c].pb(u);
		edges[c].pb(mp(v, u));
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &vq[i], &uq[i]);
		vq[i]--, uq[i]--;
		if (vq[i] > uq[i])
			swap(vq[i], uq[i]);
		prs.pb(mp(mp(vq[i], uq[i]), i));
	}

	sort(prs.begin(), prs.end());

	for (int i = 0; i < m; i++) {
		sort(vers[i].begin(), vers[i].end());
		vers[i].resize(unique(vers[i].begin(), vers[i].end()) - vers[i].begin());
	
		for (int j = 0; j < (int) edges[i].size(); j++) {
			vertex[edges[i][j].fs].pb(edges[i][j].sc);
			vertex[edges[i][j].sc].pb(edges[i][j].fs);
		}
		for (int j = 0; j < (int) vers[i].size(); j++) {
			if (!used[vers[i][j]]) {
				cur.clear();
				dfs(vers[i][j]);

				sort(cur.begin(), cur.end());

				if ((int) cur.size() > magic) {
					for (int k = 0; k < (int) cur.size(); k++)
						mask[cnt][cur[k]] = true;
					cnt++;
				} else {
					for (int p = 0; p < (int) cur.size(); p++)
						for (int q = p + 1; q < (int) cur.size(); q++)
							addpair(cur[p], cur[q]);
				}
			}
		}

		for (int j = 0; j < (int) vers[i].size(); j++) {
			used[vers[i][j]] = false;
			vertex[vers[i][j]].clear();
		}
	}

	relaxpairs();
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < cnt; j++)
			ans[i] += (mask[j][vq[i]] && mask[j][uq[i]]);
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}