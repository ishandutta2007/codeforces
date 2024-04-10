#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using i64 = int64_t;

	int N; cin >> N;
	i64 g1 = 0, g2 = 0;

	auto gl = [&](i64& a, i64& b) {
		if (!a && !b) return;
		i64 g = gcd(a, b);
		b *= a / g;
		a = g;
	};
	for (int i = 0; i < N; i++) {
		i64 A; cin >> A;
		gl(g1, A);
		g2 = gcd(g2, A);
	}
	cout << g2 << '\n';

	return 0;
}