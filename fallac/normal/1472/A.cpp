#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int w, h, n;
		cin >> w >> h >> n;
		int cnt;
		cnt = 0;
		while (w % 2 == 0) {
			w /= 2;
			cnt++;
		}
		while (h % 2 == 0) {
			h /= 2;
			cnt++;
		}
		int a = 1;
		int i;
		for (i = 1; i <= cnt; i++) {
			if (a >= 1000000001) break;
			a *= 2;
		}
		if (a >= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}