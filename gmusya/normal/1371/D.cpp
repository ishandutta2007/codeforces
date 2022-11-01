#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <vector <int>> a(n, vector <int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n && k; j++, k--)
				a[(i + j) % n][j % n] = 1;
		int mina = 1e6, minb = 1e6, maxa = -1e6, maxb = -1e6;
		for (int i = 0; i < n; i++) {
			int s = 0;
			for (int j = 0; j < n; j++)
				s += a[i][j];
			mina = min(mina, s);
			maxa = max(maxa, s);
		}
		for (int j = 0; j < n; j++) {
			int s = 0;
			for (int i = 0; i < n; i++)
				s += a[i][j];
			minb = min(minb, s);
			maxb = max(maxb, s);
		}
		cout << (maxa - mina) * (maxa - mina) + (maxb - minb) * (maxb - minb) << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << a[i][j];
			cout << '\n';
		}
	}
	return 0;
}