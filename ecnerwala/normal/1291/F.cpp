#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K; cin >> N >> K;
	int B = (K+1)/2;
	vector<bool> bad(N);
	for (int d = 1; d < N/B; d++) {
		for (int i = 0; i + d < N/B && i < d; i++) {
			for (int j = i; j < N/B; j += d) {
				for (int k = 0; k < B; k++) {
					cout << '?' << ' ' << (j*B+k)+1 << '\n' << flush;
					char c; cin >> c;
					if (c == 'Y') bad[j*B+k] = true;
				}
			}
			cout << 'R' << '\n' << flush;
		}
	}
	int ans = 0;
	for (bool b : bad) ans += !b;
	cout << '!' << ' ' << ans << '\n';

	return 0;
}