#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

int main() {
	ios_base::sync_with_stdio(0);
	int N;
	ll K;
	cin >> N >> K;
	ll v = 1;
	for(int i = 0; i < N; i++) {
		ll c; cin >> c;
		v = __gcd(K, lcm(c, v));
	}
	cout << ((v == K) ? "Yes" : "No") << '\n';
	return 0;
}