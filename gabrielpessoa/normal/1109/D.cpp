#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;

ll fat[ms];
ll ifat[ms];

ll fExp(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	fat[0] = 1;
	ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % mod;
		ifat[i] = ifat[i-1] * fExp(i, mod - 2) % mod;
		//assert(fat[i] * ifat[i] % mod == 1);
	}
	int n, m, a, b;
	cin >> n >> m;
	ll ans = 0;
	for(int x = 2; x <= min(m+1, n ); x++) {
		ll pesos = fat[m-1] * ifat[x-2] % mod * ifat[m-x+1] % mod;
		ll caminho = fat[n-2] * ifat[n-x] % mod;
		ll resto = (x < n) ? x * fExp(n, n-x-1)  % mod : 1;
		ll pesosResto = fExp(m, n - x);
		ll cur = pesos * caminho % mod * resto % mod * pesosResto % mod;
		//cout << x << ' ' << pesos << ' ' << caminho << ' ' << resto << ' ' << pesosResto << ' ' << cur << '\n';
		ans = (ans + cur) % mod;
	}
	cout << ans << '\n';
}