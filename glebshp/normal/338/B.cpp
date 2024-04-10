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
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;
const int inf = 1000 * 1000 * 1000;

bool bad[size];
int n, m, d;
int p[size];
bool ans[size];
int inst[size];
vector <int> vertex[size];
int glans = 0;

void dfs1(int v, int f) {
	inst[v] = -inf;
	if (bad[v])
		inst[v] = 0;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i] != f) {
			dfs1(vertex[v][i], v);
			inst[v] = max(inst[v], inst[vertex[v][i]] + 1);
		}
	}
}

void dfs2(int v, int f, int a) {
	if (max(a, inst[v]) <= d)
		glans++;
	int m1 = -inf, m2 = -inf;
	if (bad[v])
		m1 = 1;
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (vertex[v][i] != f) {
			int val = inst[vertex[v][i]] + 2;
			if (val >= m1) {
				m2 = m1;
				m1 = val;
			} else {
				if (val > m2)
					m2 = val;
			}
		}
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (vertex[v][i] != f) {
			if (inst[vertex[v][i]] + 2 == m1)
				dfs2(vertex[v][i], v, max(a + 1, m2));
			else
				dfs2(vertex[v][i], v, max(a + 1, m1));
		}
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		bad[p[i]] = true;
	}

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &u, &v);
		u--, v--;
		vertex[v].pb(u);
		vertex[u].pb(v);
	}
	dfs1(0, -1);
	dfs2(0, -1, -inf);

	cout << glans << endl;

	return 0;
}