#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll K;

// return the last sum value <= n and it's index
pair<ll, ll> lastSum(ll n) {
	if (n < K * (K+1) / 2) {
		return {0, 0};
	}
	ll startCnd = (n - K * (K+1) / 2) / K + 1;
	auto it = lastSum(startCnd + (K-1));
	ll sumVal = it.first;
	ll sumCnt = it.second;
	//cerr << "got " << startCnd + (K-1) << ' ' << sumVal << ' ' << sumCnt << '\n';

	ll numBefore = (sumVal - sumCnt) / K;

	// consider the one that wraps sumVal
	ll prefSize = (sumVal - sumCnt) % K;
	ll suffSize = K - prefSize;
	ll wrapSum = (sumVal - prefSize) * K + K * (K-1) / 2 + suffSize;
	if (wrapSum > n) {
		// go back by one
		return {(sumVal - prefSize - K) * K + K * (K-1) / 2, numBefore};
	}
	assert(wrapSum <= n);
	ll nextSum = (sumVal + suffSize + 1) * K + K * (K-1) / 2;
	if (nextSum > n) {
		return {wrapSum, numBefore + 1};
	} else {
		ll incr = (n - nextSum) / (K * K);
		return {nextSum + K * K * incr, numBefore + 1 + 1 + incr};
	}
}

ll go(ll N) {
	auto it = lastSum(N);
	ll sumVal = it.first;
	ll sumCnt = it.second;
	//cerr << "got " << N << ' ' << sumVal << ' ' << sumCnt << '\n';
	if (sumVal == N) {
		return sumCnt * (K+1);
	} else {
		return N - sumCnt + (N - sumCnt - 1) / K;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		ll N; cin >> N >> K;
		cout << go(N) << '\n';
	}

	return 0;
}

// gaps are k*(k+1)/2 - 1, k^2 - 1,