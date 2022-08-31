#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	int M = *max_element(A.begin(), A.end())+1;
	vector<int> cnt(M); for (auto a : A) { cnt[a]++; }

	int V = int(max_element(cnt.begin(), cnt.end()) - cnt.begin());
	int ans = 0;
	vector<pair<int, int>> mp(2*N+1, {-1, -1});
	for (int u = 0; u < M; u++) {
		if (u == V) continue;
		int pref = N;
		mp[pref] = {u, 0};
		for (int i = 0; i < N; i++) {
			if (A[i] == V) pref++;
			else if (A[i] == u) pref--;
			if (mp[pref].first == u) {
				ans = max(ans, i+1 - mp[pref].second);
			} else {
				mp[pref] = {u, i+1};
			}
		}
	}
	cout << ans << '\n';

	return 0;
}