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
#define taskname "problem_c"

const double pi = acos(-1.0);
const int size = 200;
const int ssize = 20;
const int inf = 1000 * 1000 * 1000;

int n, m;
int w[size];
int ans[ssize + 2][1 << ssize];
int bc[1 << ssize];

char tp[size];
int team[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}

	sort(w, w + n);
	reverse(w, w + n);

	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		scanf("%c%d\n", &tp[i], &team[i]);
	}
	n = m;

	for (int i = 0; i < (1 << m); i++) {
		int h = i;
		int c = 0;
		while (h > 0) {
			c += h & 1;
			h /= 2;
		}

		bc[i] = c;
	}

	ans[m][(1 << m) - 1] = 0;
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << m); j++)
			if (bc[j] == i) {
				if (team[i] == 1) {
					ans[i][j] = -inf;
					for (int k = 0; k < m; k++)
						if (!((j >> k) & 1))
							ans[i][j] = max(ans[i][j], ans[i + 1][j | (1 << k)] + (tp[i] == 'p') * w[k]);
				} else {
					ans[i][j] = inf;
					for (int k = 0; k < m; k++)
						if (!((j >> k) & 1))
							ans[i][j] = min(ans[i][j], ans[i + 1][j | (1 << k)] - (tp[i] == 'p') * w[k]);
				}
			}
	}

	cout << ans[0][0] << endl;

	return 0;
}