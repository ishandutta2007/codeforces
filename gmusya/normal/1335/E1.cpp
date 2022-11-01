#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		vector <vector <int>> cnt(n + 1, vector <int>(27));
		for (int i = 1; i <= n; i++) {
			cnt[i] = cnt[i - 1];
			cnt[i][a[i]]++;
		}
		vector <vector <int>> m(27);
		for (int i = 1; i <= n; i++)
			m[a[i]].push_back(i);
		vector <vector <pair <int, int>>> hm(27);
		for (int i = 1; i <= 26; i++) {
			if (m[i].empty()) continue;
			for (int j = 0; m[i].size() - j - 1 > j; j++) {
				hm[i].push_back({ m[i][j], m[i][m[i].size() - j - 1] });
			}
		}
		int ans = 0;
		for (int i = 1; i <= 26; i++) {
			if (hm[i].empty()) continue;
			for (int j = 0; j < hm[i].size(); j++) {
				int l = hm[i][j].first, r = hm[i][j].second - 1;
				int ma = 0;
				for (int z = 1; z <= 26; z++) 
					ma = max(ma, cnt[r][z] - cnt[l][z]);
				ans = max(ans, ma + 2 * (j + 1));
			}
		}
		cout << max(ans, 1) << endl;
	}
	return 0;
}