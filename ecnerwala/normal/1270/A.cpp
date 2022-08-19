#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, K1, K2; cin >> N >> K1 >> K2;
		int m1 = 0, m2 = 0;
		for (int i = 0; i < K1; i++) {
			int a; cin >> a;
			m1 = max(m1, a);
		}
		for (int i = 0; i < K2; i++) {
			int b; cin >> b;
			m2 = max(m2, b);
		}
		cout << (m1 > m2 ? "YES" : "NO") << '\n';
	}

	return 0;
}