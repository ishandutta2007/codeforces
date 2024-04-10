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
#define taskname "task_f"

const double pi = acos(-1.0);
const int size = 25 * 1000 + 100;
const int mxc = 20 * 1000;
const int mxmoney = 4 * 1000 + 100;
const int mxitems = 4 * 1000 + 100;

vector <int> marks;
vector <pair <int, int> > before[size];
vector <pair <int, int> > after[size];
int n, p, m, q;
int cost[size], hap[size], tm[size];
int a[size], b[size];
int ans[size];
vector <int> qs[size];

int rukbef[mxitems][mxmoney];
int rukaft[mxitems][mxmoney];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &cost[i], &hap[i], &tm[i]);
	}
	
	for (int i = 1; i <= mxc; i += p)
		marks.pb(i);
	m = marks.size();

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a[i], &b[i]);
		vector <int>::iterator it = upper_bound(marks.begin(), marks.end(), a[i]);
		it--;
		qs[it - marks.begin()].pb(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tm[i] >= marks[j] && marks[j] + p >= tm[i])
				after[j].pb(mp(tm[i], i));
			if (tm[i] < marks[j] && tm[i] + p >= marks[j])
				before[j].pb(mp(tm[i], i));
		}
	}

	for (int i = 0; i < m; i++) {
		sort(after[i].begin(), after[i].end());
		sort(before[i].rbegin(), before[i].rend());

		int sa = after[i].size();
		int sb = before[i].size();
		for (int j = 0; j < mxmoney; j++) {
			rukaft[0][j] = 0;
			rukbef[0][j] = 0;
		}
		for (int j = 0; j < sa; j++) {
			int cst = cost[after[i][j].sc];
			int happines = hap[after[i][j].sc];
			for (int hp = 0; hp < mxmoney; hp++) {
				rukaft[j + 1][hp] = rukaft[j][hp];
				if (hp >= cst)
					rukaft[j + 1][hp] = max(rukaft[j + 1][hp], rukaft[j][hp - cst] + happines);
			}
		}
		for (int j = 0; j < sb; j++) {
			int cst = cost[before[i][j].sc];
			int happines = hap[before[i][j].sc];
			for (int hp = 0; hp < mxmoney; hp++) {
				rukbef[j + 1][hp] = rukbef[j][hp];
				if (hp >= cst)
					rukbef[j + 1][hp] = max(rukbef[j + 1][hp], rukbef[j][hp - cst] + happines);
			}
		}

		for (int j = 0; j < qs[i].size(); j++) {
			int p1 = 0, p2 = 0;
			int num = qs[i][j];
			while (p1 < sa && after[i][p1].fs <= a[num])
				p1++;
			while (p2 < sb && before[i][p2].fs >= a[num] - p + 1)
				p2++;

			ans[num] = 0;
			for (int hp = 0; hp <= b[num]; hp++)
				ans[num] = max(ans[num], rukaft[p1][hp] + rukbef[p2][b[num] - hp]);
		}
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}