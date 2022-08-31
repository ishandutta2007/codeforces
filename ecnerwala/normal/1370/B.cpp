#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> c[2];
		c[0].reserve(2*N);
		c[1].reserve(2*N);
		for (int i = 0; i < 2 * N; i++) {
			int a; cin >> a; c[a&1].push_back(i);
		}
		for (int i = 0; i < N-1; i++) {
			int z = (c[0].size() >= 2) ? 0 : 1;
			cout << c[z].back()+1 << ' '; c[z].pop_back();
			cout << c[z].back()+1 << '\n'; c[z].pop_back();
		}
	}

	return 0;
}