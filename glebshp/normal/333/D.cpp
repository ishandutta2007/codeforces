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
const int size = 1000;

int n, m;
bool wash[size][size];
bool wasv[size][size];

vector <int> activeh[size], activev[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int c;

	scanf("%d%d", &n, &m);
	vector <pair <int, pair <int, int> > > allc;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &c);
			allc.pb(mp(c, mp(i, j)));
		}

	sort(allc.rbegin(), allc.rend());
	int v, u;
	for (int i = 0; i < n * m; i++) {
		for (int j = 0; j < (int) activeh[allc[i].sc.fs].size(); j++) {
			v = allc[i].sc.sc;
			u = activeh[allc[i].sc.fs][j];
			if (wash[v][u] || wash[u][v]) {
				cout << allc[i].fs << endl;
				return 0;
			}
			wash[v][u] = true;
			wash[u][v] = true;
		}
		for (int j = 0; j < (int) activev[allc[i].sc.sc].size(); j++) {
			v = allc[i].sc.fs;
			u = activev[allc[i].sc.sc][j];
			if (wasv[v][u] || wasv[u][v]) {
				cout << allc[i].fs << endl;
				return 0;
			}
			wasv[v][u] = true;
			wasv[u][v] = true;
		}
		activeh[allc[i].sc.fs].pb(allc[i].sc.sc);
		activev[allc[i].sc.sc].pb(allc[i].sc.fs);
	}

	return 0;
}