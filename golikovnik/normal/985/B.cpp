#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<int> cnt(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
			if (a[i][j]) ++cnt[j];
		}
	}
	int need = 0;
	for (int i = 0; i < n; ++i) {
		int need_this = 0;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] && cnt[j] == 1) {
				need_this = 1;
				break;
			}
		}
		need += need_this;
	}	
	cout << (need == n ? "NO" : "YES") << "\n";
	return 0;	

}