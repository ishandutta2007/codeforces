#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll L[MAXN];
char T[MAXN];

ll cap[6];


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	cin >> T;
	assert(int(strlen(T)) == N);

	ll res = 0;
	cap[0] = 0;
	for (int i = 0; i < N; i++) {
		if (T[i] == 'G') {
			// we can walk, which is cost 2 for up to 2L and cost 5 for inf
			cap[5] = ll(1e18);
			cap[2] += 2 * L[i];
		} else if (T[i] == 'W') {
			cap[3] = ll(1e18);
			cap[1] += 2 * L[i];
		} else {
			// sad
		}
		res += L[i];
		// pay up L stamina
		ll cost = L[i];
		for (ll c = 1; cost > 0; c++) {
			if (cap[c] == 0) continue;
			ll amt = min(cost, cap[c]);
			res += c * amt;
			cost -= amt;
			if (c == 3 || c == 5) {
				// it's inf or 0, so dont bother subtracting
			} else {
				cap[c] -= amt;
			}
		}
	}
	cout << res << '\n';

	return 0;
}