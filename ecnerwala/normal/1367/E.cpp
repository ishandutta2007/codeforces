#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string S; cin >> S;
		array<int, 26> cnt; cnt.fill(0);
		for (char c : S) cnt[c-'a']++;

		// Let G = gcd(L, K); then it must be G groups of L/G beads
		for (int L = N; L > 0; L--) {
			int G = gcd(L, K);
			int cnd = 0;
			for (int c : cnt) {
				cnd += c / (L/G);
			}
			if (cnd >= G) {
				cout << L << '\n';
				break;
			}
		}
	}

	return 0;
}