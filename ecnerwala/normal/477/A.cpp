#include<bits/stdc++.h>
using namespace std;

// x = b * k * m + m for m = 1 .. b - 1
// k = 1..a
// sum (b * a * (a + 1) / 2 + a) * (b * (b - 1) / 2)

typedef long long ll;
const ll MOD = 1e9 + 7;
ll c2(ll a) {
	return a * (a - 1) / 2 % MOD;
}

int main() {

	long long a, b; cin >> a >> b;

	cout << (b * c2(a + 1) % MOD + a) % MOD * c2(b) % MOD << '\n';
	return 0;
}