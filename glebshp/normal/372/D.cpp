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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int size = 200 * 1000  + 100;
const int jump = 20;

int n, k;
int jmp[jump][size];
int deep[size];
int ltr[size];
int intime[size];
int outtime[size];
int backmap[size];

int isanc(int v, int u) {
	return (intime[v] <= intime[u]) && (outtime[v] >= outtime[u]);
}

int liftup(int v, int d) {
	for (int i = jump - 1; i >= 0; i--) {
		if (deep[jmp[i][v]] >= d)
			v = jmp[i][v];
	}

	return v;
}

int getlca(int v, int u) {
	if (deep[v] > deep[u])
		swap(v, u);
	u = liftup(u, deep[v]);
	if (v == u)
		return v;
	for (int i = jump - 1; i >= 0; i--)
		if (jmp[i][v] != jmp[i][u]) {
			v = jmp[i][v];
			u = jmp[i][u];
		}
	return jmp[0][v];
}

vector <int> vertex[size];

int gltm = 0;

void dfs(int v, int fr) {
	jmp[0][v] = fr;
	if (v != fr)
		deep[v] = deep[fr] + 1;
	for (int i = 1; i < jump; i++)
		jmp[i][v] = jmp[i - 1][jmp[i - 1][v]];
	//backmap[gltm] = v;
	intime[v] = gltm++;

	for (int j = 0; j < (int) vertex[v].size(); j++)
		if (vertex[v][j] != fr)
			dfs(vertex[v][j], v);

	outtime[v] = gltm++;
}

int getsetdist(int v, set <pair <int, int> >& myset) {
	if (myset.find(mp(intime[v], v)) != myset.end())
		return 0;

	if (myset.empty())
		return 1;
	int root = getlca(myset.begin()->sc, myset.rbegin()->sc);
	if (isanc(v, root))
		return deep[root] - deep[v];
	if (!isanc(root, v)) {
		int lc = getlca(root, v);
		return deep[root] + deep[v] - deep[lc] * 2;
	} else {
		set <pair <int, int> >::iterator it = myset.lower_bound(mp(intime[v], v));
		if (it != myset.end() && isanc(v, it->sc)) {
			return 0;
		}
		int bst = n;
		if (it != myset.end()) {
			bst = min(bst, deep[v] - deep[getlca(v, it->sc)]);
		}
		if (it != myset.begin()) {
			it--;
			bst = min(bst, deep[v] - deep[getlca(v, it->sc)]);
		}

		return bst;
	}
}

int curs = 0;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int v, u;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;

		vertex[v].pb(u);
		vertex[u].pb(v);
	}

	dfs(0, 0);
	int mx = 1;
	int p = 0;
	set <pair <int, int> > myset;
	
	for (int i = 0; i < n; i++) {
		while (p < n) {
			int dst = getsetdist(p, myset);
			if (curs + dst <= k) {
				curs += dst;
				myset.insert(mp(intime[p], p));
				p++;
			} else {
				break;
			}
		}
		mx = max(mx, p - i);

		myset.erase(mp(intime[i], i));
		curs -= getsetdist(i, myset);
	}

	cout << mx << endl;

	return 0;
}