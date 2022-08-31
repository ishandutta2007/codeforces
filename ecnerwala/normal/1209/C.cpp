#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		for (char d = '0'; d <= '9'; d++) {
			int a_lo = -1;
			int b_hi = N;
			int b_last = -1;
			string res(N, '0');
			for (int i = 0; i < N; i++) {
				if (S[i] < d) {
					if (a_lo != -1 && S[i] < S[a_lo]) {
						goto bad;
					}
					a_lo = i;
				} else if (S[i] > d) {
					if (b_last != -1 && S[i] < S[b_last]) {
						goto bad;
					}
					b_last = i;
					if (b_hi != N) {
					} else {
						b_hi = i;
					}
				}
			}
			for (int i = 0; i < N; i++) {
				if (S[i] < d) {
					res[i] = '1';
				} else if (S[i] > d) {
					res[i] = '2';
				} else {
					if (i >= a_lo) {
						res[i] = '1';
					} else if (i <= b_hi) {
						res[i] = '2';
					}
					else goto bad;
				}
			}
			cout << res << '\n';
			goto done;
bad:;
		}
		cout << '-' << '\n';
done:;
	}

	return 0;
}