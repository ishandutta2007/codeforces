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
4
2
1 7
3
1 5 4
4
12345678 87654321 20211218 23571113
9
1 2 3 4 18 19 5 6 7
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		long long a[n];
		multiset<long long> t;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			t.insert(a[i]);
		}

		bool o = true;
		long long u = 0;

		for (int i = n; i > 0; --i) {
			if (t.count(i)) {
				t.erase(t.lower_bound(i));
			}
			else {
				auto f = t.lower_bound(2 * i + 1);

				if (f == t.end()) {
					o = false;
					break;
				}

				t.erase(f);
				u++;
			}
		}

		cout << ( o ? u : -1) << "\n";
	}
}