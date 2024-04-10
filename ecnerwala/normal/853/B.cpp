#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;

	vector<tuple<int, int, int64_t>> in_flights; in_flights.reserve(M);
	vector<tuple<int, int, int64_t>> out_flights; out_flights.reserve(M);

	for (int i = 0; i < M; i++) {
		int d, f, t; int64_t c; cin >> d >> f >> t >> c;
		f--, t--;
		if (f == -1) {
			out_flights.push_back({d, t, c});
		} else if (t == -1) {
			in_flights.push_back({d, f, c});
		} else assert(false);
	}

	sort(in_flights.begin(), in_flights.end());
	sort(out_flights.begin(), out_flights.end());
	vector<multiset<int64_t>> all_out_flights(N);
	for (auto [_, f, c] : out_flights) {
		all_out_flights[f].insert(c);
	}

	const int64_t INF = 1.1e12;
	vector<int64_t> in_cost(N, INF);
	int64_t ans = INF;
	int64_t cur = std::accumulate(in_cost.begin(), in_cost.end(), int64_t(0));
	for (int i = 0; i < N; i++) {
		all_out_flights[i].insert(INF);
		cur += *all_out_flights[i].begin();
	}

	int i = 0;
	int j = 0;
	for (; i < int(in_flights.size()); i++) {
		while (j < int(out_flights.size()) && get<0>(in_flights[i]) + K >= get<0>(out_flights[j])) {
			auto [_, f, c] = out_flights[j];

			cur -= *all_out_flights[f].begin();
			all_out_flights[f].erase(all_out_flights[f].find(c));
			cur += *all_out_flights[f].begin();

			j++;
		}

		auto [_, f, c] = in_flights[i];
		cur -= in_cost[f];
		in_cost[f] = min(in_cost[f], c);
		cur += in_cost[f];

		//cerr << get<0>(in_flights[i]) << ' ' << cur << '\n';
		ans = min(ans, cur);
	}

	if (ans >= INF) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}