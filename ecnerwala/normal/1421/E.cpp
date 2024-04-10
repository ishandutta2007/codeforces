#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using i64 = int64_t;
	const i64 INF = 1e18;

	int N; cin >> N;

	int64_t v_alt = 0;
	array<i64, 3> dp{-INF,-INF,-INF};
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		dp = {max(dp[2]+A,dp[1]-A), max(dp[0]+A,dp[2]-A), max(dp[1]+A,dp[0]-A)};

		if (i&1) A = -A;
		dp[2] = max(dp[2], v_alt - A);
		v_alt += A;
	}

	cout << (N == 1 ? v_alt : dp[1]) << '\n';

	return 0;
}

// A set of coeffs is valid if you can take 2 adjacent equal and replace with 1 opposite, and it converges to +1
// [+ - + - +]
// [+ + - - +] -> [- - - +] -> [- + +] -> [- -] -> [+]
//
// +1 +1 -> -1 doesn't change the sum mod 3
// -1 -1 -> +1 doesn't change the sum mod 3
//
// Valid iff sum of +1 and -1 mod 3 = +1 and not purely alternating