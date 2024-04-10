#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int64_t> H(N);
	for (int i = 0; i < N; i++) cin >> H[i], H[i] -= i;

	int64_t tot_height = 0;
	for (int i = 0; i < N; i++) tot_height += H[i];

	vector<int64_t> ans(N);
	for (int i = 0; i < N; i++) {
		ans[i] = tot_height / N + (i < tot_height % N);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] + i << " \n"[i+1==N];
	}

	return 0;
}