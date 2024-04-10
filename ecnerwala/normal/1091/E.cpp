#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 6e5;
ll N;
ll A[MAXN];
ll pref[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	pref[0] = 0;
	for (ll i = 0; i < N; i++) {
		pref[i+1] = pref[i] + A[i];
	}

	ll maxA = N;
	ll minA = 0;
	// the sum of any k is bounded by
	for (ll k = 1; k <= N+1; k++) {
		if (k > 1) {
			// sum of the biggest k is at most k * (k-1)
			ll lhs = pref[N] - pref[N+1-k];
			ll mid = lower_bound(A, A + N+1-k, k) - A;
			ll rhs = k * (k-1) + pref[mid] + (N+1 - k - mid) * k;
			// lhs + a <= rhs
			maxA = min(maxA, rhs - lhs);
		}

		if (k <= N) {
			ll lhs = pref[N] - pref[N-k];
			ll mid = lower_bound(A, A + N-k, k) - A;
			ll rhs = k * (k-1) + pref[mid] + (N - k - mid) * k;
			// lhs <= rhs + min(k, A)
			if (!(lhs <= rhs + k)) {
				minA = N+1;
			}
			minA = max(minA, lhs - rhs);
		}
	}
	vector<ll> res;
	for (ll i = minA; i <= maxA; i++) {
		if (i % 2 == pref[N] % 2) {
			res.push_back(i);
		}
	}
	if (res.empty()) {
		cout << -1 << '\n';
	} else {
		for (ll v : res) cout << v << ' ';
		cout << '\n';
	}


	return 0;
}