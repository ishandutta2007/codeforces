#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
5
3
0 1 3
7
0 1 2 3 4 3 2
4
3 0 0 0
7
4 6 2 3 5 0 5
5
4 0 1 0 4
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (auto &&x : a) {
			cin >> x;
		}

		sort(a.begin(), a.end());
		int j = 0;
		stack<int> inc;
		long long o = 0;
		int cc = 1;
		bool ok = true;

		for (int i = 0; i <= n; ++i) {
			if (!ok) {
				cout << -1 << " ";
				continue;
			}

			int c = 0;

			while (j < n and a[j] == i) {
				c++;
				j++;
			}

			if (cc == 0) {
				if (inc.size()) {
					o += i - 1 - inc.top();
					inc.pop();
				}
				else {
					ok = false;
				}
			}

			cc = c;

			cout << (ok ? c + o : -1) << " ";
			c--;

			while (c-- > 0) {
				inc.push(i);
			}
		}

		cout << "\n";
	}

}