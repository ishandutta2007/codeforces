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
const int rms = (1 << 20) - 1;
const int hrms = rms / 2;
const int size = 500 * 1000;

int lv[size], rv[size], sv[size];
int n;
vector <int> toadd[size];
vector <int> todelete[size];
int rmq[rms + 1];
int md[rms + 1];

void rsupdate(int v, int i, int j, int lb, int rb, int d) {
	if (i > rb || j < lb)
		return;
	if (lb >= i && rb <= j) {
		md[v] += d;
		return;
	}
	rsupdate(v * 2, i, j, lb, (lb + rb) / 2, d);
	rsupdate(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb, d);

	rmq[v] = max(rmq[v * 2] + md[v * 2], rmq[v * 2 + 1] + md[v * 2 + 1]);
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &lv[i], &sv[i], &rv[i]);
	}

	for (int i = 0; i < n; i++) {
		toadd[sv[i]].pb(i);
		todelete[rv[i]].pb(i);
	}

	int ans = 0;
	int ansl = -1, ansr = -1;
	int lb, rb;

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < (int) toadd[i].size(); j++) {
			int nm = toadd[i][j];
			rsupdate(1, lv[nm], sv[nm], 1, hrms + 1, 1);
		}

		if (rmq[1] + md[1] > ans) {
			ans = rmq[1] + md[1];
			ansr = i;
			ansl = 1;
			lb = 1;
			rb = hrms + 1;
			while (ansl <= hrms) {
				if (rmq[ansl] == (rmq[ansl * 2] + md[ansl * 2])) {
					ansl = ansl * 2;
					rb = (lb + rb) / 2;
				} else {
					lb = (lb + rb) / 2 + 1;
					ansl = ansl * 2 + 1;
				}
			}
			ansl = lb;
		}
		
		for (int j = 0; j < (int) todelete[i].size(); j++) {
			int nm = todelete[i][j];
			rsupdate(1, lv[nm], sv[nm], 1, hrms + 1, -1);
		}
	}

	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		if (lv[i] <= ansl && rv[i] >= ansr && sv[i] >= ansl && sv[i] <= ansr)
			printf("%d ", i + 1);

	return 0;
}