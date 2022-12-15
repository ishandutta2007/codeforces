#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int SIZE = 1E6 + 100;
const int MOD = 1e9 + 7;

ll fat[SIZE], ifat[SIZE];

vector<int> primes[SIZE];

bool np[SIZE];

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll comb(ll a, ll b) {
	return fat[a] * ifat[b] % MOD * ifat[a - b] % MOD;
}

int main() {
	for(int i = 2; i < SIZE; i++) {
		if(np[i]) continue;
		for(int j = i; j < SIZE; j += i) {
			np[j] = true;
			int x = j;
			int e = 0;
			while(x % i == 0) {
				e++;
				x /= i;
			}
			primes[j].push_back(e);
		}
	}
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < SIZE; i++) {
		fat[i] = fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		ll r = 1;
		for(auto p : primes[x]) {
			r = r * comb(p + y - 1, y - 1) % MOD;
		}
		r = r * fexp(2, y - 1) % MOD;
		printf("%lld\n", r);
	}
	return 0;
}