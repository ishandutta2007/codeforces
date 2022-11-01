// October 31, 2018
// http://codeforces.com/problemset/problem/1060/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	int n, m;
	cin >> n >> m;
	vector<int> a(n), apsa(n + 1);
	vector<int> b(m), bpsa(m + 1);
	apsa[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		apsa[i + 1] = apsa[i] + a[i];
	}
	bpsa[0] = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		bpsa[i + 1] = bpsa[i] + b[i];
	}
	int x;
	cin >> x;
	const int INF = (int) 1e9;
	vector<int> amin(n + 1, INF), bmin(m + 1, INF);
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 0; i + sz <= n; i++) {
			amin[sz] = min(amin[sz], apsa[i + sz] - apsa[i]);
		}
	}
	for (int sz = 1; sz <= m; sz++) {
		for (int i = 0; i + sz <= m; i++) {
			bmin[sz] = min(bmin[sz], bpsa[i + sz] - bpsa[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((long long) amin[i] * bmin[j] <= x) {
				ans = max(ans, i * j);
			}
		}
	}
	cout << ans << '\n';


	return 0;
}