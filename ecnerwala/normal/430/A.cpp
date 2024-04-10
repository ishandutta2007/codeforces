#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<pair<int, int>> X(N);
	for (int i = 0; i < N; i++) cin >> X[i].first, X[i].second = i;
	sort(X.begin(),X.end());
	vector<int> ans(N);
	for (int i = 0; i < N; i++) ans[X[i].second] = i&1;
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}