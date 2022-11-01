#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

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
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector <int> pos(m);
	int it = -1;
	for (int i = 0; i < m; i++) {
		bool tf = false;
		for (++it; it < n; it++) {
			if (a[it] == b[i]) {
				pos[i] = it, tf = true;
				if (i + 1 != m) break;
			}
			if (a[it] < b[i]) {
				tf = false;
				break;
			}
		}
		if (!tf) {
			cout << 0;
			return 0;
		}
	}
	vector <int> mid(m - 1);
	for (int i = 0; i < m - 1; i++) {
		int l = pos[i];
		int r = pos[i + 1];
		for (int j = l; j <= r; j++) {
			if (a[j] < b[i]) {
				mid[i] = j;
				break;
			}
		}
	}
	long long ans = 1;
	for (int i = 0; i < m - 1; i++)
		ans = ans * (mid[i] - pos[i]) % 998244353;
	cout << ans;
	return 0;
}