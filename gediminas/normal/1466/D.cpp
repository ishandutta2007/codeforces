#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*input
4
4
3 5 4 6
2 1
3 1
4 3
2
21 32
2 1
6
20 13 17 13 13 11
2 1
3 1
4 1
5 1
6 1
4
10 6 6 6
1 2
2 3
4 1
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<long long> w(n);
		vector<pair<long long, int>> ww(n);

		for (int i = 0; i < n; ++i) {
			cin >> w[i];
			ww[i].first = w[i];
			ww[i].second = i;
		}

		sort(ww.rbegin(), ww.rend());

		vector<int> laip(n);

		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			laip[a]++;
			laip[b]++;
		}

		vector<long long> ans;
		long long cur = 0;

		for (int i = 0; i < n; ++i) {
			cur += laip[i] * w[i];
		}

		ans.push_back(cur);

		for (int i = 1; i < n - 1; ++i) {
			while (laip[ww.back().second] <= 1) {
				ww.pop_back();
			}

			laip[ww.back().second]--;
			cur -= ww.back().first;
			ans.push_back(cur);
		}

		reverse(ans.begin(), ans.end());

		for (auto &&i : ans) {
			cout << i << " ";
		}

		cout << "\n";
	}

}