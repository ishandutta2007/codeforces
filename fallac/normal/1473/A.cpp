#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, D;
		cin >> N >> D;
		int i;
		int a, b;
		int aa;
		cin >> a >> b;
		if (a < b) {
			int t = a;
			a = b;
			b = t;
		}
		int m;
		m = max(a, b);
		for (i = 3; i <= N; i++) {
			cin >> aa;
			m = max(m, aa);
			if (aa < a) a = aa;
			if (a < b) {
				int t = a;
				a = b;
				b = t;
			}
		}
		if (m <= D || a + b <= D) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}