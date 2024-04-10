#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M; cin >> N >> M;
	int64_t G = 0;
	int64_t A; cin >> A;
	for (int i = 1; i < N; i++) {
		int64_t A2; cin >> A2;
		G = std::gcd(G, A2-A);
	}
	for (int j = 0; j < M; j++) {
		int64_t B; cin >> B;
		cout << std::gcd(G, A + B) << " \n"[j+1==M];
	}

	return 0;
}