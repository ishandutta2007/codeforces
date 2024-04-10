#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<vector<int>> S(K);
		for (auto& s : S) {
			int c; cin >> c;
			s.resize(c);
			for (auto& v : s) cin >> v;
		}
		auto run_query = [&](const vector<int>& query) -> int {
			cout << '?' << ' ' << query.size();
			for (int v : query) cout << ' ' << v;
			cout << '\n' << flush;

			int res; cin >> res;
			return res;
		};

		vector<int> big_query(N); iota(big_query.begin(), big_query.end(), 1);
		const int MAX_VAL = run_query(big_query);

		int mi = 0, ma = K;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			vector<int> query; query.reserve(N);
			for (int i = mi; i < md; i++) {
				query.insert(query.end(), S[i].begin(), S[i].end());
			}
			int mx = run_query(query);
			if (mx == MAX_VAL) {
				ma = md;
			} else {
				mi = md;
			}
		}
		vector<int> ans(K, MAX_VAL);
		vector<bool> used(N);
		for (int v : S[mi]) used[v-1] = true;

		vector<int> query; query.reserve(N);
		for (int i = 0; i < N; i++) if (!used[i]) query.push_back(i+1);

		ans[mi] = run_query(query);
		cout << '!';
		for (int v : ans) cout << ' ' << v;
		cout << '\n' << flush;

		string resp; cin >> resp;
		if (resp == "Correct") continue;
		else if (resp == "Incorrect") exit(0);
		else assert(false);
	}

	return 0;
}