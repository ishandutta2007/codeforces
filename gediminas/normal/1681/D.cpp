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
2 1
*/
/*input
3 2
*/
/*input
13 42
*/
/*input
19 9
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, x;
	cin >> n >> x;
	long long goal = 1;

	for (int i = 1; i < n; ++i) {
		goal *= 10;
	}

	vector<long long> a = {x};
	const int sz = 50000;

	int ans = -1;

	for (int i = 0; i < 100; ++i) {
		vector<long long> b;

		for (auto &&x : a) {
			string o = to_string(x);

			for (int i = 2; i <= 9; ++i) {
				if (o.find('0' + i) != string::npos) {
					b.push_back(i * x);
				}
			}
		}

		if (b.empty()) {
			break;
		}

		sort(b.rbegin(), b.rend());

		if (b[0] >= goal) {
			ans = i + 1;
			break;
		}

		a = vector<long long> (b.begin(), b.begin() + min(b.size(), (size_t)sz));
	}

	cout << ans << endl;
}