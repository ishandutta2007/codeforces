#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int L = 0;
	int R = n + 1;
	while (L != R) {
		int M = (L + R) / 2;
		int cnt = (upper_bound(a.begin(), a.end(), M) - a.begin());
		for (int i = 0; i < m; i++) {
			if (b[i] > 0 && b[i] <= M) cnt++;
			if (b[i] < 0 && -b[i] <= cnt)
				cnt--;
		}
		if (cnt > 0) R = M;
		else L = M + 1;
	}
	if (L == n + 1) L = 0;
	cout << L;
	return 0;
}