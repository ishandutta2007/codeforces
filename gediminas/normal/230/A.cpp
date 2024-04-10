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
2 2
1 99
100 0
*/
/*input
10 1
100 100
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long s, n;
	cin >> s >> n;
	vector<pair<long long, long long>> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());
	int i = 0;

	for (; i < n; ++i) {
		if (a[i].first < s) {
			s += a[i].second;
		}
		else {
			break;
		}
	}

	cout << (i == n ? "YES" : "NO") << "\n";
}