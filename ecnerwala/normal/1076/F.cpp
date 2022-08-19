#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
int N;
ll K;
ll X[MAXN];
ll Y[MAXN];

ll bestSame(ll st, ll a, ll b) {
	if (st > K) return K+1;
	// b has to be at most K * a
	if (b > K * a) return K+1;
	ll minB = (st + a - 1) / K;
	if (b < minB) {
		return K+1;
	} else if (b == minB) {
		return st + a - b * K;
	} else {
		return 1;
	}
}

ll bestDiff(ll st, ll a, ll b) {
	if (st > K) return K+1;
	ll minB = (st + a + K - 1) / K;
	if (b < minB) return K+1;
	// the b's have to fit
	if (b > K * (a+1)) return K+1;
	else if (b > K * a) return b - K * a;
	else return 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> X[i];
	for (int i = 0; i < N; i++) cin >> Y[i];

	ll a = K, b = K;
	for (int i = 0; i < N; i++) {
		ll na = min(bestSame(a, X[i], Y[i]), bestDiff(b, Y[i], X[i]));
		ll nb = min(bestSame(b, Y[i], X[i]), bestDiff(a, X[i], Y[i]));
		a = na, b = nb;
	}
	cout << ((a <= K || b <= K) ? "YES" : "NO") << '\n';

	return 0;
}