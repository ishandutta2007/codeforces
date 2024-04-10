#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		set<int> B; for (int i = 0; i < N; i++) { int b; cin >> b; B.insert(b); }
		cout << (int(B.size()) < N ? "YES" : "NO") << '\n';
	}

	return 0;
}