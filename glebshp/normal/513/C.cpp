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
#define taskname "task_c"

const double pi = acos(-1.0);
const int size = 100;
const int inf = 1000 * 1000;

int n;
int lb[size], rb[size];

double could(int ps, int lc, int rc) {
	lc = max(lc, lb[ps]);
	rc = min(rc, rb[ps]);
	if (lc > rc)
		return 0.0;
	else
		return (rc - lc + 1.0) / (rb[ps] - lb[ps] + 1.0);
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> lb[i] >> rb[i];

	if (n == 1) {
		printf("%.10lf\n", (lb[0] + rb[0]) / 2.0);
		return 0;
	}

	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = lb[i]; j <= rb[i]; j++) {
			double cur = could(i, j, j);
			double h1 = 0.0, h2 = 0.0;
			for (int k = 0; k < n; k++) {
				if (k != i) {
					if (k < i)
						h1 = could(k, j, inf);
					else
						h1 = could(k, j + 1, inf);
			
					h2 = 1.0;
					for (int p = 0; p < n; p++) {
						if (p != i && p != k) {
							if (p < i) {
								h2 = h2 * could(p, -inf, j - 1);
							} else {
								h2 = h2 * could(p, -inf, j);
							}
						}
					}
//					cout << ans << ' ' << cur << ' ' << h1 << ' ' << h2 << endl;
					ans += cur * h1 * h2 * j;
		
				}
			}

			//ans += cur * j;
		}
	}

	printf("%.20lf\n", ans);

	return 0;
}