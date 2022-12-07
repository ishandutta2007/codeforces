#include <cstdio>
#include <cmath>
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

int n, a[200000];
const int INF = 2e9 + 9;

int main() {
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", a + i);
	int ans = 1, prev = -1, d = INF, pos = -1, left = 0, right = 0;
	REP(i, n)
		if (a[i] != -1) {
			if (prev == -1) {
				prev = a[i];
				pos = i;
			} else if (d == INF) {
				if ((a[i] - prev) % (i - pos) == 0) {
					d = (a[i] - prev) / (i - pos);
					if (left && a[i] - (LL)d * (right + left + 1) <= 0) {
						++ans;
						d = INF;
					}
					left = right = 0;
				} else {
					++ans;
					left = right = 0;
				}
				prev = a[i];
				pos = i;
			} else {
				if (((a[i] - prev) % (i - pos) != 0) || ((a[i] - prev) / (i - pos) != d)) {
					++ans;
					if (prev + (LL)d * right <= 0) {
						while (prev + d > 0) {
							prev += d;
							--right;
						}
						left = right;
						right = 0;
					}
					d = INF;
				} else
					left = right = 0;
				prev = a[i];
				pos = i;
			}
		} else if (prev == -1) {
			++left;
		} else
			++right;
	if (d != INF && prev + (LL)d * right <= 0)
		++ans;
	cout << ans << endl;
	return 0;
}