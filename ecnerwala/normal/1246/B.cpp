#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N, K;
int A[MAXN];

const int MAXV = 1.1e5;
const int V = int(1e5) + 10;
bool isPrime[MAXV];
ll ownVal[MAXV];
ll otherVal[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (K >= 5) {
		vector<ll> vals;
		for (ll x = 1; true; x++) {
			ll v = 1; for (int i = 0; i < K; i++) { v *= x; }
			if (v > ll(1.01e10)) break;
			vals.push_back(v);
		}
		unordered_map<ll, int> cnt;
		ll ans = 0;
		for (int i = 0; i < N; i++) {
			for (ll v : vals) {
				if (v % A[i] == 0) {
					ans += cnt[v / A[i]];
				}
			}
			cnt[A[i]] ++;
		}
		cout << ans << '\n';
		exit(0);
	}

	assert(K <= 4);
	for (int v = 1; v <= V; v++) {
		isPrime[v] = (v >= 2);
		ownVal[v] = 1;
		otherVal[v] = 1;
	}
	for (int p = 2; p <= V; p++) {
		if (!isPrime[p]) continue;

		for (int j = p + p; j <= V; j += p) {
			isPrime[j] = false;
		}

		for (int j = p; j <= V; j += p) {
			int k = 0;
			for (int cur = j; cur % p == 0; cur /= p) k++;
			k %= K;
			if (!k) continue;
			for (int i = 0; i < k; i++) ownVal[j] *= p;
			for (int i = k; i < K; i++) otherVal[j] *= p;
		}
	}

	unordered_map<ll, int> cnt;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += cnt[otherVal[A[i]]];
		cnt[ownVal[A[i]]] ++;
	}
	cout << ans << '\n';

	return 0;
}