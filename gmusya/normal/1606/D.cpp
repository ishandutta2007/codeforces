#pragma GCC optimize("O3","unroll-loops")

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		vector<vector<int>> pref_min(n, vector<int>(m));
		vector<vector<int>> pref_max = pref_min;
		vector<vector<int>> suf_min = pref_max;
		vector<vector<int>> suf_max = suf_min;
		for (int i = 0; i < n; ++i) {
			pref_min[i][0] = pref_max[i][0] = a[i][0];
			for (int j = 1; j < m; ++j) {
				pref_min[i][j] = min(pref_min[i][j - 1], a[i][j]);
				pref_max[i][j] = max(pref_max[i][j - 1], a[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			suf_min[i][m - 1] = suf_max[i][m - 1] = a[i][m - 1];
			for (int j = m - 2; j >= 0; --j) {
				suf_min[i][j] = min(suf_min[i][j + 1], a[i][j]);
				suf_max[i][j] = max(suf_max[i][j + 1], a[i][j]);
			}
		}
		bool solved = false;
		for (int cut = 0; cut + 1 < m && !solved; ++cut) {
			vector<int> p(n);
			iota(p.begin(), p.end(), 0);
			sort(p.begin(), p.end(), [&](int i, int j) {
				return pref_max[i][cut] > pref_max[j][cut];
			});
			multiset<int> left_red;
			multiset<int> left_blue;
			multiset<int> right_red;
			multiset<int> right_blue;
			function<bool()> Check = [&]() {
				bool left_correct = *left_red.begin() > *left_blue.rbegin();
				bool right_correct = *right_blue.begin() > *right_red.rbegin();
				return left_correct && right_correct;
			};
			left_red.insert(pref_min[p[0]][cut]);
			for (int i = 1; i < n; ++i) {
				left_blue.insert(pref_max[p[i]][cut]);
			}
			right_red.insert(suf_max[p[0]][cut + 1]);
			for (int i = 1; i < n; ++i) {
				right_blue.insert(suf_min[p[i]][cut + 1]);
			}
			vector<char> answer(n, 'B');
			function<void()> PrintAnswer = [&]() {
				solved = true;
				cout << "YES\n";
				for (int i = 0; i < n; ++i) {
					cout << answer[i];
				}
				cout << ' ' << cut + 1 << '\n';
			};
			answer[p[0]] = 'R';
			if (Check()) {
				PrintAnswer();
			}
			for (int i = 1; i + 1 < n && !solved; ++i) {
				int ind = p[i];
				answer[ind] = 'R';
				left_red.insert(pref_min[ind][cut]);
				left_blue.erase(left_blue.find(pref_max[ind][cut]));
				right_red.insert(suf_max[ind][cut + 1]);
				right_blue.erase(right_blue.find(suf_min[ind][cut + 1]));
				if (Check()) {
					PrintAnswer();
				}
			}
		}
		if (!solved) {
			cout << "NO\n";
		}
	}
	return 0;
}