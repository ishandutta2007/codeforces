#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );



// #define DEBUG

const ll mod = 1e9 + 7;
ll fpow(ll a, ll b){
	ll res = 1, mul = a, bit = b;
	while (bit){
		if (bit & 1){ res = res*mul % mod; }
		mul = mul*mul % mod; bit >>= 1;
	}
	return res;
}
inline ll finv(ll a){ return fpow(a, mod-2); }

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m, y, x, r, c, p; cin >> n >> m >> y >> x >> r >> c >> p;
		ll pp = p * finv(100) % mod;
		ll ip = (100-p+mod) * finv(100) % mod;
		int sty = y, stx = x;
		int dr = 1, dc = 1; ll l = 0;
		vector<int> v;
		for (int a = 0; ; a++){
			y += dr; x += dc;
			if (1 > y || y > n){ y -= dr; dr *= -1; y += dr; }
			if (1 > x || x > m){ x -= dc; dc *= -1; x += dc; }
			y -= dr; x -= dc;
			if (a != 0 && y == sty && x == stx){
				if ( (dr==1 || dr==-1&&y==n) && (dc==1 || dc==-1&&x==m) ){ l = a; break; }
			}
			if (y == r || x == c){ v.push_back(a); }
			y += dr; x += dc;
			if (1 > y || y > n){ y -= dr; dr *= -1; y += dr; }
			if (1 > x || x > m){ x -= dc; dc *= -1; x += dc; }
		}
		int k = v.size();
		int i = 0;
		ll ans = 0;
		for (ll val : v){ i += 1;
			ll r = fpow(ip, k);
			ll a = fpow(ip, i-1) * pp % mod * val % mod;
			ans += a * finv(1-r + mod); ans %= mod;
		}
		ll cns = ( fpow(ip, k)-1 + mod ) % mod * finv(ip-1 + mod) % mod;
		ll b = pp * l % mod;
		ll a = fpow(ip, k);
		ll sum = a * finv(1-a + mod) % mod * finv(1-a + mod) % mod;
		sum = sum * cns % mod * b % mod;
		ans += sum; ans %= mod;
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}