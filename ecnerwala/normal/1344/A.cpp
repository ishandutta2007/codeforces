#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> cnt(N);
		for (int i = 0; i < N; i++) {
			int v = (i + A[i]) % N;
			if (v < 0) v += N;
			cnt[v]++;
		}
		if (*max_element(cnt.begin(), cnt.end()) == 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}