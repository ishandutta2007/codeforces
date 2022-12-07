#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100], _b[101], *b, ans[100], ord[100], r[100], best = -1, ccur = 0, cc;
int pr[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
bool used[17] = {};

bool cmp(const int &lhs, const int &rhs) {
	return a[lhs] < a[rhs];
}

void go(int x) {
	if (x == n) {
		int cur = ccur;
		for (int i = cc; i < n; ++i) cur += abs(a[i] - b[i]);
		if (best == -1 || cur < best) {
			best = cur;
			REP(i, n) ans[i] = b[i];
		}
		return;
	}
	REP(i, 16) if (!used[i]) {
		used[i] = true;
		int val = 1;
		while (true) {
			val *= pr[i];
			if (val >= 60) break;
			if (abs(val - a[x]) < 30 && val >= b[x - 1]) {
				b[x] = val;
				go(x + 1);
			}
			for (int j = i + 1; val * pr[j] < 60; ++j) if (!used[j]) {
				used[j] = true;
				int val2 = val;
				while (true) {
					val2 *= pr[j];
					if (val2 >= 60) break;
					if (abs(val2 - a[x]) < 30 && val2 >= b[x - 1]) {
						b[x] = val2;
						go(x + 1);
					}
					for (int k = j + 1; val2 * pr[k] < 60; ++k) if (!used[k]) {
						used[k] = true;
						int val3 = val2 * pr[k];
						if (abs(val3 - a[x]) < 30 && val3 >= b[x - 1]) {
							b[x] = val3;
							go(x + 1);
						}
						used[k] = false;
					}
				}
				used[j] = false;
			}
		}
		used[i] = false;
	}
}

int main() {
	b = _b + 1;
	b[-1] = 1;
	cin >> n;
	REP(i, n) cin >> a[i], ord[i] = i;
	sort(ord, ord + n, cmp);
	sort(a, a + n);
	REP(i, n) r[ord[i]] = i;
	REP(i, n) {
		cc = i;
		if (n - i < 17)
			go(i);
		b[i] = 1;
		ccur += a[i] - 1;
		if (best != -1 && ccur >= best) break;
	}
	if (best == -1 || ccur < best) {
		REP(i, n) cout << 1 << ' ';
		cout << endl;
		return 0;
	}
	REP(i, n) cout << ans[r[i]] << ' ';
	cout << endl;
	return 0;
}