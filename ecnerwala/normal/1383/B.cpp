#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;
		int tot = 0;
		for (int a : A) tot ^= a;
		if (!tot) {
			cout << "DRAW" << '\n';
			continue;
		}
		int b = (31 - __builtin_clz(tot));
		int cnt = 0;
		for (int a : A) if (a & (1 << b)) cnt++;
		assert(cnt & 1);
		if ((N-cnt) % 2 == 0 && (cnt + 1) / 2 % 2 == 0) {
			cout << "LOSE" << '\n';
		} else {
			cout << "WIN" << '\n';
		}
	}

	return 0;
}