#include <bits/stdc++.h>

const int MOD = 998244353;
int minv(int a, int m) {
	return a == 1 ? 1 : m - int(int64_t(minv(m % a, a)) * m / a);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int M; cin >> M;
	int N = 0;
	vector<int> A(M); for (auto& a : A) { cin >> a; N += a; }
	sort(A.begin(), A.end());

	int x = 1;
	int64_t denom = 1;
	int64_t numer_cur = 2;
	int64_t numer_tot = numer_cur;
	auto get_val = [&](int a) {
		assert(x <= a);
		for (; x < a; x++) {
			numer_cur *= 2*N-x;
			numer_tot *= N-x;
			denom *= N-x;
			numer_tot += numer_cur;
			numer_cur %= MOD;
			numer_tot %= MOD;
			denom %= MOD;
		}
		return int(numer_tot * minv(int(denom), MOD) % MOD);
	};

	int ans = 0;
	for (int a : A) {
		ans -= get_val(a);
		ans = (ans < 0 ? ans + MOD : ans);
	}
	ans += get_val(N);
	ans = (ans >= MOD ? ans - MOD : ans);
	cout << ans << '\n';

	return 0;
}