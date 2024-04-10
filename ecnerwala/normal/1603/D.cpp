#include <bits/stdc++.h>

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = int(1e5) + 10;
	const int MAXCNT = 20;

	std::vector<int> primes; primes.reserve(V+1);
	std::vector<int> pfac(V+1);
	std::vector<int> phi(V+1);
	phi[1] = 1;
	for (int i = 2; i <= V; i++) {
		if (!pfac[i]) {
			pfac[i] = i;
			primes.push_back(i);
			phi[i] = i-1;
		}
		for (int p : primes) {
			if (p > V / i) break;
			pfac[i * p] = p;
			if (p == pfac[i]) {
				phi[i*p] = phi[i] * p;
				break;
			} else {
				phi[i*p] = phi[i] * (p-1);
			}
		}
	}

	std::vector<int64_t> pref_phi(V+1);
	for (int i = 1; i <= V; i++) pref_phi[i] = pref_phi[i-1] + phi[i];

	std::vector<std::vector<pair<int64_t, int>>> all_dp(MAXCNT+1);
	all_dp[1] = std::vector<pair<int64_t, int>>(V+1);
	for (int v = 0; v <= V; v++) {
		all_dp[1][v] = {int64_t(v) * int64_t(v+1) / 2, 0};
	}

	for (int cnt = 2; cnt <= MAXCNT; cnt++) {
		const std::vector<pair<int64_t, int>>& pdp = all_dp[cnt-1];
		std::vector<pair<int64_t, int>>& ndp = all_dp[cnt];
		ndp = pdp;
		std::vector<std::deque<std::pair<int, int64_t>>> suff_best;
		suff_best.emplace_back();
		int rt = 0;
		for (int v = 1; v <= V; v++) {
			if ((rt+1) * (rt+1) <= v) {
				suff_best.emplace_back();
				rt++;
			}

			{
				int64_t const_term = 0;
				for (int k = 1; k <= v; k++) {
					if (v / k < pdp[v].second) break;
					if (k <= rt) {
						assert(k == v / (v / k));
						const_term += phi[k] * (v / k);
						if (int(suff_best.size()) <= k) {
							assert(k == rt && rt * rt == v);
							suff_best.emplace_back();
							assert(v / (rt+1) == rt-1);
						}
						if (v % k == 0) {
							int l = v / k;
							int64_t cnd = pdp[l].first - l * pref_phi[k];
							while (!suff_best[k].empty() && suff_best[k].back().second >= cnd) suff_best[k].pop_back();
							suff_best[k].push_back({l, cnd});
						}
						while (suff_best[k].front().first <= v / (k+1)) suff_best[k].pop_front();
						setmin(ndp[v], {const_term + suff_best[k].front().second, suff_best[k].front().first});
					} else {
						int lo = k-1;
						k = v / (v / k);
						assert(v / k == v / (lo+1));
						assert(v / (k+1) < v / k);
						const_term += (pref_phi[k] - pref_phi[lo]) * (v / k);
						for (int l = v / (k+1) + 1; l <= v / k; l++) {
							setmin(ndp[v], {const_term + pdp[l].first - l * pref_phi[k], l});
						}
					}
				}
			}
		}
	}

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		K = min(K, MAXCNT);
		cout << all_dp[K][N].first << '\n';
	}

	return 0;
}