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
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;

set <pair <int, int> > oldedges;
set <pair <int, int> > newedges;

int n, m;
int deg[size];
vector <int> perm;

bool rec(int ps) {
	if (ps == n)
		return ((int) newedges.size() == m);
	for (int i = min(m - (int) newedges.size(), 2 - deg[ps]); i >= 0; i--) {
		if (i == 2) {
			for (int e1 = ps + 1; e1 < n; e1++)
				if (deg[e1] < 2 && oldedges.find(mp(ps, e1)) == oldedges.end()) {
					newedges.insert(mp(ps, e1));
					deg[ps]++;
					deg[e1]++;
					for (int e2 = e1 + 1; e2 < n; e2++) {
						if (deg[e2] < 2 && oldedges.find(mp(ps, e2)) == oldedges.end()) {
							newedges.insert(mp(ps, e2));
							deg[ps]++;
							deg[e2]++;
							if (rec(ps + 1)) {
								return true;
							}
							deg[ps]--;
							deg[e2]--;
							newedges.erase(mp(ps, e2));
						}
					}
					deg[ps]--;
					deg[e1]--;
					newedges.erase(mp(ps, e1));
				}
		}
		if (i == 1) {
			for (int e2 = ps + 1; e2 < n; e2++) {
				if (deg[e2] < 2 && oldedges.find(mp(ps, e2)) == oldedges.end()) {
					newedges.insert(mp(ps, e2));
					deg[ps]++;
					deg[e2]++;
					if (rec(ps + 1)) {
						return true;
					}
					deg[ps]--;
					deg[e2]--;
					newedges.erase(mp(ps, e2));
				}
			}
		}
		if (i == 0)
			if (rec(ps + 1))
				return true;
	}

	return false;
}

int main() {
	/*
	const int n = 100000;
	
	freopen("input.txt", "w", stdout);
	cout << n << ' ' << n << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ' ' << (i + 1) % n + 1 << endl;
	}
	return 0;
	*/
	double sttm = clock();

	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	/*
	for (int i = 0; i < n; i++)
		perm.pb(i);
	srand(23);
	random_shuffle(perm.begin(), perm.end());
	vector <int> back(n);
	
	for (int i = 0; i < n; i++)
		back[perm[i]] = i;
	*/
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v, &u);
		v--, u--;
		oldedges.insert(mp(min(v, u), max(v, u)));
	}

	if (rec(0)) {
		for (set <pair <int, int> >::iterator it = newedges.begin(); it != newedges.end(); ++it) {
			printf("%d %d\n", it->fs + 1, it->sc + 1);
		}
	} else {
		printf("-1\n");
	}
	//printf("%.2lf\n", (clock() - sttm) / CLOCKS_PER_SEC);

    return 0;
}