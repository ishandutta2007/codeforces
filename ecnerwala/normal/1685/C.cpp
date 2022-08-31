#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;

		string S; cin >> S;
		assert(int(S.size()) == 2 * N);

		std::vector<int> pref(2*N+1);
		for (int i = 0; i < 2*N; i++) {
			pref[i+1] = pref[i] + (S[i] == '(' ? +1 : -1);
		}

		int first_neg = -1;
		int last_neg = -1;
		for (int i = 0; i <= 2*N; i++) {
			if (pref[i] < 0) {
				if (first_neg == -1) first_neg = i;
				last_neg = i;
			}
		}
		if (first_neg == -1) {
			cout << 0 << '\n';
		} else {
			int md = int(std::max_element(pref.begin(), pref.end()) - pref.begin());

			int m1 = int(std::max_element(pref.begin(), pref.begin() + first_neg + 1) - pref.begin());
			int m2 = int(std::max_element(pref.begin() + last_neg, pref.end()) - pref.begin());

			if (pref[m1] + pref[m2] >= pref[md]) {
				cout << 1 << '\n';
				cout << m1+1 << ' ' << m2 << '\n';
			} else {
				// you can always do 2 by taking the tallest point
				cout << 2 << '\n';
				cout << 1 << ' ' << md << '\n';
				cout << md+1 << ' ' << 2*N << '\n';
			}
		}
	}

	return 0;
}