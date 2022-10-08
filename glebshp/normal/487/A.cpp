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
#define taskname "task_a"

const double pi = acos(-1.0);
const int mx = 210;
const int mxh = 40 * 1000 + 100;
const int inf = 1000 * 1000 * 1000 + 100;

int hy, ay, dy, hm, am, dm;
int costh, costa, costd;

bool could(int mdh, int mda, int mdd) {
	int s1, s2;
	int damy = max(0, ay + mda - dm);
	int damm = max(0, am - dy - mdd);

	if (damy == 0)
		s1 = inf;
	else
		s1 = (hm + damy - 1) / damy;

	if (damm == 0)
		s2 = inf;
	else
		s2 = (hy + mdh + damm - 1) / damm;

	return s1 < s2;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> hy >> ay >> dy;
	cin >> hm >> am >> dm;
	cin >> costh >> costa >> costd;

	int ans = inf;

	for (int i = 0; i <= mx; i++)
		for (int j = 0; j <= mx; j++) {
			int lb = 0;
			int rb = mxh;

			while (lb < rb) {
				int mid = (lb + rb) / 2;
				if (could(mid, i, j))
					rb = mid;
				else
					lb = mid + 1;
			}

			if (could(lb, i, j)) {
				ans = min(ans, i * costa + j * costd + lb * costh);
			}
		}

	cout << ans << endl;
	
	return 0;
}