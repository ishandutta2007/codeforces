#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	ll N, K; cin >> N >> K;
	ll A, B; cin >> A >> B;

	ll mi = N*K+1, ma = -1;
	for (int z1 = 0; z1 < 2; z1++, A = (K-A) % K) {
		for (int z2 = 0; z2 < 2; z2++, B = (K-B) % K) {
			ll l = (B-A) % K;
			if (l < 0) l += K;
			for (; l <= N*K; l += K) {
				ll stops = N*K /__gcd(l, N*K);
				mi = min(mi, stops);
				ma = max(ma, stops);
			}
		}
	}
	cout << mi << ' ' << ma << '\n';

}