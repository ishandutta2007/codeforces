#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <int>> a(n, vector <int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		vector <int> cnt0(n + m), cnt1(n + m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int posa = (i + j);
				int posb = (n + m - 2) - posa;
				if (posb == posa) continue;
				if (posa > posb) swap(posa, posb);
				if (a[i][j] == 0) cnt0[posa]++;
				else cnt1[posa]++;
			}
		int ans = 0;
		for (int i = 0; i < n + m; i++)
			ans += min(cnt0[i], cnt1[i]);
		cout << ans << '\n';
	}
	return 0;
}