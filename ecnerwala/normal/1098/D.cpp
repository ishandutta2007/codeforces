#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll N = 0;
multiset<ll> buckets[40];
ll bucketmin[40];
ll bucketsum[40];

ll cnt() {
	if (N == 0) return 0;
	ll res = N-1;
	ll sum = 0;
	for (int i = 0; i < 32; i++) {
		sum += bucketsum[i];
		if (sum && !buckets[i+1].empty() && bucketmin[i+1] > 2 * sum) {
			res--;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;

	for (int q = 0; q < Q; q++) {
		char c; ll v; cin >> c >> v;
		assert(v > 0);
		// leading bit
		ll b = 63 - __builtin_clzll((unsigned long long)v);
		assert(v & (1ll << b));
		if (c == '+') {
			buckets[b].insert(v);
			bucketsum[b] += v;
			N++;
		} else if (c == '-') {
			buckets[b].erase(buckets[b].find(v));
			bucketsum[b] -= v;
			N--;
		} else assert(false);

		bucketmin[b] = buckets[b].empty() ? 0 : *buckets[b].begin();

		cout << cnt() << '\n';
	}

	return 0;
}