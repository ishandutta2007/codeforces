#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> B(N+1);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	B[N] = B[0];

	// minimize deletion which is x * (N-B[i]) + (N-x)*(B[i+1)
	// Minimize x * B[i]

	vector<pair<int, int>> pts;
	for (int i = 0; i < N; i++) {
		pts.emplace_back(B[i] + B[i+1], i);
	}
	sort(pts.begin(), pts.end());

	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		ans[pts[i].second] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}