#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; cin >> N >> Q;
	vector<int> H(N); for (auto& h : H) cin >> h;

	vector<vector<pair<int, int>>> queries(N);
	for (int q = 0; q < Q; q++) {
		int a, b; cin >> a >> b; a--;
		queries[a].emplace_back(b, q);
	}

	vector<int> ans(Q);

	vector<int> forwardLis(N);
	{
		vector<int> buf; buf.reserve(N);
		for (int i = 0; i < N; i++) {
			for (auto [b, q] : queries[i]) {
				ans[q] += int(lower_bound(buf.begin(), buf.end(), b, std::less<>()) - buf.begin());
			}
			auto it = lower_bound(buf.begin(), buf.end(), H[i], std::less<>());
			forwardLis[i] = int(it - buf.begin());
			if (it == buf.end()) buf.push_back(H[i]);
			else *it = H[i];
		}
	}

	int LIS = *max_element(forwardLis.begin(), forwardLis.end()) + 1;
	vector<int> numCnd(LIS);
	{
		vector<int> buf; buf.reserve(N);
		for (int i = N-1; i >= 0; i--) {
			for (auto [b, q] : queries[i]) {
				ans[q] += int(lower_bound(buf.begin(), buf.end(), b, std::greater<>()) - buf.begin());
			}

			auto it = lower_bound(buf.begin(), buf.end(), H[i], std::greater<>());
			int revLis = int(it - buf.begin());
			if (it == buf.end()) buf.push_back(H[i]);
			else *it = H[i];

			if (forwardLis[i] + revLis + 1 == LIS) {
				numCnd[forwardLis[i]]++;
			} else {
				forwardLis[i] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int base = LIS - (forwardLis[i] != -1 && numCnd[forwardLis[i]] == 1);
		for (auto [_, q] : queries[i]) {
			ans[q] = max(ans[q]+1, base);
		}
	}

	for (int& v : ans) { cout << v << '\n'; }
	return 0;
}