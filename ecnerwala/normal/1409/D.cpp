#include<bits/stdc++.h>

int digit_sum(int64_t a) { return a ? digit_sum(a/10) + a%10 : 0; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N, S; cin >> N >> S;
		if (digit_sum(N) <= S) {
			cout << 0 << '\n';
			continue;
		}
		for (int64_t p10 = 1; true; p10 *= 10) {
			if (digit_sum(N + p10 - (N % p10)) <= S) {
				cout << p10 - (N % p10) << '\n';
				break;
			}
		}
	}

	return 0;
}