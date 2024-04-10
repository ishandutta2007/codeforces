#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int M; cin >> M;
	vector<int> L(M);
	for (int i = 0; i < M; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < M; i++) {
		if (L[i] + i > N) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	long long sumL = 0;
	for (int i = 0; i < M; i++) {
		sumL += L[i];
	}
	if (sumL < N) {
		cout << -1 << '\n';
		exit(0);
	}
	vector<int> ans(M+1);
	ans[M] = N;
	for (int i = M-1; i >= 0; i--) {
		ans[i] = max(ans[i+1] - L[i], i);
	}
	for (int i = 0; i < M; i++) {
		cout << ans[i]+1 << " \n"[i+1==M];
	}

	return 0;
}