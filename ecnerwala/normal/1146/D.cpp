#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXA = 1.1e5;
ll reachCost[MAXA];

// sum i = 0 to a-1 of floor(i / M) + 1
ll prefSum(ll a, ll M) {
	ll res = a;
	res += (a % M) * (a / M);
	res += (a / M - 1) * (a - a % M) / 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll M, A, B; cin >> M >> A >> B;
	memset(reachCost, -1, sizeof(reachCost));
	ll cur = 0;
	ll maxPos = 0;
	reachCost[cur] = maxPos;
	while (true) {
		if (cur >= B) {
			cur -= B;
			assert(cur < A);
			if (cur == 0) break;
			reachCost[cur] = maxPos;
		} else {
			cur += A;
			maxPos = max(maxPos, cur);
		}
	}

	ll res = 0;
	for (ll i = 0; i < A; i++) {
		if (reachCost[i] == -1) continue;
		assert(reachCost[i] >= i);
		if (reachCost[i] > M) continue;
		assert(M >= reachCost[i]);
		res += prefSum(M + 1 - i, A) - prefSum(reachCost[i] - i, A);
	}
	cout << res << '\n';

	return 0;
}