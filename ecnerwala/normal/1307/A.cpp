#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, D; cin >> N >> D;
		int ans; cin >> ans;
		for (int i = 1; i < N; i++) {
			int a; cin >> a;
			int c = min(a, D / i);
			D -= c * i;
			ans += c;
		}
		cout << ans << '\n';
	}

	return 0;
}