#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 200013
#define MAXT (2*MAXN)

int N;
LL A[MAXN], B[MAXN], T[MAXN];
vector<LL> times;
unordered_map<LL, int> to_t;
vector<int> st[MAXT], en[MAXT];
pair<LL, LL> dp[MAXT];
vector<pair<LL, LL> > cutoffs[MAXT];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> T[i];
		times.push_back(A[i]);
		times.push_back(B[i] - T[i] + 1);
	}

	sort(times.begin(), times.end());
	times.resize(unique(times.begin(), times.end()) - times.begin());

	for (int i = 0; i < times.size(); i++)
		to_t[times[i]] = i;

	for (int i = 0; i < N; i++) {
		st[to_t[A[i]]].push_back(i);
		en[to_t[B[i] - T[i] + 1]].push_back(i);
	}

	dp[0] = {0, 0};
	multiset<LL> m;
	for (int i = 0; i < times.size() - 1; i++) {
		// get dp[i + 1] from dp[i]

		for (int j : en[i]) m.erase(m.find(T[j]));
		for (int j : st[i]) m.insert(T[j]);

		LL cur = dp[i].first; // first try not doing anything & waiting :)

		LL cost = m.size() ? *m.begin() : 0; // smallest forging time

		if (m.size()) {
			LL len = times[i + 1] - times[i];
			cur += len / cost;
			dp[i + 1] = {cur, len % cost};
		}
		else {
			dp[i + 1] = {cur, 0};
		}

		// now take cutoffs
		for (auto p : cutoffs[i + 1]) {
			LL left = times[i + 1] - p.second;
			if (cost)
				dp[i + 1] = max(dp[i + 1], {p.first + left / cost, left % cost});
			else
				dp[i + 1] = max(dp[i + 1], {p.first, 0});
		}

		// add a cutoff
		if (dp[i + 1].second) {
			LL future = times[i + 1] - dp[i + 1].second + cost;
			int k = lower_bound(times.begin(), times.end(), future) - times.begin();
			cutoffs[k].emplace_back(dp[i + 1].first + 1, future);

			// if (k < times.size()) {
			// 	LL left = times[k] - future;
			// 	dp[k] = max(dp[k], {cur + left / T[k], left % T[k]});
			// }
		}
	}

	LL ans = dp[times.size() - 1].first;
	if (dp[times.size() - 1].second) ++ans;

	cout << ans << endl;
	return 0;
}