#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;

ll A[MAXN];

map<int, int> milestones[MAXN];

ll V[MAXN]; // number of fill

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += max(0ll, A[i] - V[i]);
	}

	int Q; cin >> Q;
	while (Q--) {
		int s, t, u; cin >> s >> t >> u; s--, t--, u--;
		if (milestones[s].count(t)) {
			int v = milestones[s][t];
			ans -= max(0ll, A[v] - V[v]);
			V[v] --;
			ans += max(0ll, A[v] - V[v]);
			milestones[s].erase(t);
		}

		if (u != -1) {
			ans -= max(0ll, A[u] - V[u]);
			V[u] ++;
			ans += max(0ll, A[u] - V[u]);
			milestones[s][t] = u;
		}
		cout << ans << '\n';
	}

	return 0;
}