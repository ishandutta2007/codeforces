#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e8+1;

bitset<ms> sieve;

const ll mod = 1ll<<32;

ll a, b, c, d;

ll f(int k) {
	ll x = k;
	ll x2 = (x * x) % mod;
	ll x3 = (x2 * x) % mod;
	return (x3*a + x2*b + x*c + d) % mod;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n >> a >> b >> c >> d;
	int qnt2 = 0;
	for(int i = 2; i <= n; i <<= 1) {
		qnt2 += n/i;
	}
	ll ans = (f(2) * qnt2) % mod;
	int qnt3 = 0;
	for(int i = 3; i <= n; i *= 3) {
		qnt3 += n/i;
	}
	ans = (ans + f(3) * qnt3) % mod;
	//cout << ans << '\n';
	for(int i = 5; i <= n; i += 4) {
		int v = i/3;
		if(!sieve[v]) {
			ll val = f(i);
			int c = n/i;
			ll aux = (ll) i*i;
			while(aux <= n) {
				c += n / aux;
				aux *= i;
			}
			//cout << c << " de " << i << endl;
			for(int j = i + i + i; j <= n; j += i + i) {
				if(j%3) sieve[j/3] = 1;
				//cout << (j >> 1) << " agora eh invalido " << endl;
			}
			ans = (ans + val * c) % mod;
		}
		i += 2;
		if(i <= n) {
			v = i / 3;
			if(!sieve[v]) {
				ll val = f(i);
				int c = n/i;
				ll aux = (ll) i*i;
				while(aux <= n) {
					c += n / aux;
					aux *= i;
				}
				//cout << c << " de " << i << endl;
				for(int j = i + i + i; j <= n; j += i + i) {
					if(j%3) sieve[j/3] = 1;
					//cout << (j >> 1) << " agora eh invalido " << endl;
				}
				ans = (ans + val * c) % mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}