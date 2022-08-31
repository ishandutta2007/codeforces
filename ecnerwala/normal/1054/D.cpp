#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
long long N, K, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	M = (1ll << K) - 1;
	map<long long, long long> mp;

	long long pref = 0;
	mp[pref]++;
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		pref ^= a;
		pref = min(pref, pref ^ M);
		mp[pref] ++;
	}

	long long res = N * (N+1) / 2;
	for (auto it : mp) {
		long long l = it.second / 2;
		long long r = it.second - l;
		res -= l * (l-1) / 2;
		res -= r * (r-1) / 2;
	}
	cout << res << '\n';

	return 0;
}