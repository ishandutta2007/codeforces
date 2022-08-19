#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
const int MAXM = 4e5;
int N, M;
pair<int, int> P[MAXN];

ll res[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int val = min(P[u].first + P[v].second, P[u].second + P[v].first);
		res[u] -= val;
		res[v] -= val;
	}

	for (int i = 0; i < N; i++) {
		res[i] -= P[i].first + P[i].second;
	}

	ll totSecond = 0;
	for (int i = 0; i < N; i++) {
		totSecond += P[i].second;
	}
	for (int i = 0; i < N; i++) {
		res[i] += totSecond;
		res[i] += ll(P[i].second) * ll(N);
	}

	for (int i = 0; i < N; i++) {
		P[i].first -= P[i].second;
		P[i].second = i;
	}
	sort(P, P + N);
	ll pref = 0;
	for (int i = 0; i < N; i++) {
		res[P[i].second] += pref + ll(P[i].first) * ll(N-i);
		pref += P[i].first;
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << " \n"[i==N-1];
	}

	return 0;
}