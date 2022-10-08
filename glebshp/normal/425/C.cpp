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
const int inf = 1000 * 1000 * 1000;

int best[size];
int help[size];
int a[size], b[size];
vector <int> ps[size];
int cura[size];
int n, m, s, e;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &s, &e);
    int mx = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		mx = max(mx, b[i]);
		ps[b[i]].pb(i);
	}
	for (int i = 0; i <= mx; i++)
		ps[i].pb(inf + 1);
	for (int i = 0; i < n; i++)
		best[i] = -1;
	int ans = 0;
	for (int i = 1; i <= s / e; i++) {
		int curmn = inf;
		if (i == 1)
			curmn = -1;
		for (int j = 0; j <= mx; j++)
			cura[j] = (int) ps[j].size() - 1; 
		for (int j = 0; j < n; j++) {
			while (cura[a[j]] > 0 && ps[a[j]][cura[a[j]] - 1] > curmn)
				cura[a[j]]--;
			help[j] = ps[a[j]][cura[a[j]]];
			if (help[j] > inf)
				help[j] = inf;
			if (help[j] < inf) {
				if (j + 1 + help[j] + 1 + i * e <= s)
					ans = i;
			}
			curmn = min(curmn, best[j]);	
		}
		for (int j = 0; j < n; j++)
			best[j] = help[j];
	}

	cout << ans << endl;

    return 0;
}