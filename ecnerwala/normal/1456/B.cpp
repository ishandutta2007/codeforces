#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> pref(N+1);
	for (int i = 0; i < N; i++) {
		pref[i+1] = pref[i] ^ A[i];
	}

	for (int l = 3; l <= N; l++) {
		for (int i = 0, j = l; j <= N; i++, j++) {
			for (int k = i+1; k <= j-1; k++) {
				if ((pref[k] ^ pref[i]) > (pref[j] ^ pref[k])) {
					cout << l-2 << '\n';
					exit(0);
				}
			}
		}
	}
	cout << -1 << '\n';

	return 0;
}