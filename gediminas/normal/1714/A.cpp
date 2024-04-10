#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
3
1 6 13
8 0
3 6 0
12 30
14 45
6 0
2 23 35
20 15
10 30

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, H, M;
		cin >> n >> H >> M;
		int T = H * 60 + M;
		int ats = 10000000;

		for (int i = 0; i < n; ++i) {
			int h, m;
			cin >> h >> m;
			int t = 60 * h + m;

			if (T <= t) {
				ats = min(ats, t - T);
			}
			else {
				ats = min(ats, t - T + 60 * 24);
			}
		}

		cout << ats / 60 << " " << ats % 60 << "\n";
	}

}