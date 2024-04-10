#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> G(N); for (auto& s : G) cin >> s;
		vector<pair<int, int>> ans0;
		vector<pair<int, int>> ans1;
		(G[0][1] == '0' ? ans0 : ans1).push_back({0,1});
		(G[1][0] == '0' ? ans0 : ans1).push_back({1,0});
		(G[N-1][N-2] == '1' ? ans0 : ans1).push_back({N-1,N-2});
		(G[N-2][N-1] == '1' ? ans0 : ans1).push_back({N-2,N-1});
		if (ans0.size() > ans1.size()) swap(ans0, ans1);
		cout << ans0.size() << '\n';
		for (auto it : ans0) {
			cout << it.first+1 << ' ' << it.second+1 << '\n';
		}
	}

	return 0;
}