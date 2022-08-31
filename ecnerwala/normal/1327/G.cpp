#include<bits/stdc++.h>
using namespace std;

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

using ll = int_fast64_t;
const int D = 14;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int K; cin >> K;

	vector<array<int, D>> trans(1); trans[0].fill(0);
	vector<int> failure(1, 0);
	vector<ll> nodeVal(1, 0);

	for (int k = 0; k < K; k++) {
		string T; cin >> T;
		int cur = 0;
		for (char c : T) {
			if (!trans[cur][c-'a']) {
				int nxt = int(trans.size());
				trans.push_back(array<int, D>()); trans.back().fill(0);
				failure.push_back(0);
				nodeVal.push_back(0);

				trans[cur][c-'a'] = nxt;
			}
			cur = trans[cur][c-'a'];
		}
		int val; cin >> val;
		nodeVal[cur] += val;
	}

	vector<int> q;
	q.push_back(0);
	for (int i = 0; i < int(q.size()); i++) {
		int cur = q[i];
		for (int nxt : trans[cur]) {
			if (!nxt) continue;
			q.push_back(nxt);
		}
	}

	assert(q.size() == trans.size());

	failure[0] = -1;
	for (int cur : q) {
		if (cur) nodeVal[cur] += nodeVal[failure[cur]];
		for (int c = 0; c < D; c++) {
			(trans[cur][c] ? failure[trans[cur][c]] : trans[cur][c]) = (cur ? trans[failure[cur]][c] : 0);
		}
	}

	string S; cin >> S;
	vector<int> boundaries;
	boundaries.push_back(-1);
	for (int i = 0; i < int(S.size()); i++) {
		if (S[i] == '?') boundaries.push_back(i);
	}
	boundaries.push_back(int(S.size()));

	vector<vector<pair<int, ll>>> Strans(int(boundaries.size())-1);
	for (int i = 0; i+1 < int(boundaries.size()); i++) {
		Strans[i] = vector<pair<int, ll>>(trans.size());
		int l = boundaries[i]+1;
		// we might as well only go up to length trans.size()
		int r = min(boundaries[i+1]-1, l + int(trans.size()));
		for (int st = 0; st < int(trans.size()); st++) {
			int cur = st;
			ll val = nodeVal[cur];
			for (int j = l; j <= r; j++) {
				assert(S[j] != '?');
				cur = trans[cur][S[j]-'a'];
				val += nodeVal[cur];
			}
			Strans[i][st] = {cur, val};
		}
		if (r == l+int(trans.size())) {
			for (int v = 0; v < int(trans.size()); v++) {
				assert(Strans[i][v].first == Strans[i][0].first);
			}
			ll extraVal = 0;
			int cur = Strans[i][0].first;
			for (int j = r+1; j <= boundaries[i+1]-1; j++) {
				cur = trans[cur][S[j]-'a'];
				extraVal += nodeVal[cur];
			}
			for (int v = 0; v < int(trans.size()); v++) {
				Strans[i][v].first = cur;
				Strans[i][v].second += extraVal;
			}
		}
	}

	const ll INF = 1e18;
	vector<vector<ll>> dp(1<<D, vector<ll>(trans.size(), -INF));
	dp[0][Strans[0][0].first] = Strans[0][0].second;
	ll ans = -INF;
	for (int m = 0; m < 1<<D; m++) {
		int l = __builtin_popcount(m);
		if (l >= int(boundaries.size())-2) {
			for (ll v : dp[m]) setmax(ans, v);
			continue;
		}
		for (int i = 0; i < D; i++) {
			if (m & (1<<i)) continue;
			for (int v = 0; v < int(trans.size()); v++) {
				auto it = Strans[l+1][trans[v][i]];
				setmax(dp[m|(1<<i)][it.first], dp[m][v] + it.second);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}