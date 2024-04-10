#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
const int MAXM = 3.1e5;

int N, M;
ll V[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		ll d; cin >> d;
		V[u] += d;
		V[v] -= d;
	}

	vector<int> lefts;
	vector<int> rights;
	for (int i = 0; i < N; i++) {
		if (V[i] > 0) lefts.push_back(i);
		else if (V[i] < 0) rights.push_back(i);
	}

	vector<pair<pair<int, int>, ll>> ans;
	while (!lefts.empty() && !rights.empty()) {
		ll v = min(V[lefts.back()], -V[rights.back()]);
		ans.push_back(pair<pair<int, int>, ll>(pair<int, int>(lefts.back(), rights.back()), v));
		V[lefts.back()] -= v;
		V[rights.back()] += v;
		if (V[lefts.back()] == 0) {
			lefts.pop_back();
		}
		if (V[rights.back()] == 0) {
			rights.pop_back();
		}
	}
	cout << ans.size() << '\n';
	for (auto it : ans) {
		cout << it.first.first+1 << ' ' << it.first.second+1 << ' ' << it.second << '\n';
	}

	return 0;
}