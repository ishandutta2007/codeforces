#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> val(N+M-1, 0);
		for (int i = N-1; i >= 0; i--) {
			for (int j = M-1; j >= 0; j--) {
				int a; cin >> a; val[i+j] ^= a;
			}
		}
		cout << (any_of(val.begin(), val.end(), [&](int a) -> bool { return a; }) ? "Ashish" : "Jeel") << '\n';
	}

	return 0;
}