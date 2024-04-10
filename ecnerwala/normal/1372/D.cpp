#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int64_t> pref = A;
	for (int i = 0; i+2 < N; i++) {
		pref[i+2] += pref[i];
	}
	vector<int64_t> suff = A;
	for (int i = N-1; i >= 2; i--) {
		suff[i-2] += suff[i];
	}

	int64_t ans = pref[N-1];
	for (int i = 0; i+1 < N; i++) {
		ans = max(ans, pref[i] + suff[i+1]);
	}
	cout << ans << '\n';

	return 0;
}