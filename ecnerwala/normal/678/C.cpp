#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int64_t N, A, B, P, Q; cin >> N >> A >> B >> P >> Q;
	cout << (N / A) * P + (N / B) * Q - (N / A / (B / gcd(A, B))) * min(P, Q) << '\n';

	return 0;
}