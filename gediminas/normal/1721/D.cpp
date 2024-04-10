
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "../includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

//CF_LINK: https://codeforces.com/contest/1721/problem/D
/*input
3

5
1 0 0 3 3
2 3 2 1 0

3
1 1 1
0 0 3

8
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0
*//*output
2
0
7
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		int a[n], b[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		long long maxv = 0;

		for (int j = 29; j >= 0; --j) {
			long long val = (1ll << j);
			bool ok = true;
			map<int, pair<vector<int>, vector<int>>>xx;

			for (int i = 0; i < n; ++i) {
				xx[(a[i])&maxv].first.push_back(a[i]);
				xx[(b[i]^maxv)&maxv].second.push_back(b[i]);
			}

			for (auto &&[x, y] : xx) {
				int va = 0, vb = 0;

				if (y.first.size() != y.second.size()) {
					ok = false;
					break;
				}

				for (auto &&t : y.first) {
					if (t & val) {
						va++;
					}
				}

				for (auto &&t : y.second) {
					if (t & val) {
						vb++;
					}
				}

				if (va + vb != y.first.size()) {
					ok = false;
					break;
				}
			}

			if (ok) {
				maxv ^= val;
			}
		}

		cout << maxv << "\n";
	}
}