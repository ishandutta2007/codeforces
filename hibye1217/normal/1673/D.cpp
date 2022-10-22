#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

inline int sgn(ll x){
	if (x > 0){ return 1; } if (x < 0){ return -1; } return 0;
}
ll gcd(ll a, ll b){
	if (b == 0){ return a; } return gcd(b, a%b);
}
ll lcm(ll a, ll b){ return a*b / gcd(a,b); }

bool chk(ll a, ll b, ll c, ll x){
	if ((x-b) % a != 0){ return 0; }
	ll val = (x-b) / a;
	if (0 <= val && val < c){ return 1; } else{ return 0; }
}

const ll mod = 1e9 + 7;

void Main(){
	int t; cin >> t;
	while (t--){
		ll a2, b2, c2; cin >> b2 >> a2 >> c2;
		ll a3, b3, c3; cin >> b3 >> a3 >> c3;
		if (a2 == 0){
			if (a3 != 0){ cout << 0; goto next; }
			if (b2 != b3){ cout << 0; goto next; }
			if (c2 < c3){ cout << 0; goto next; }
			if (c2 > c3){ cout << 1; goto next; }
			cout << -1; goto next;
		}
		if (a3 == 0){
			if ( chk(a2, b2, c2, b3) ){ cout << -1; goto next; }
			cout << 0; goto next;
		}
		if (a3 % a2 != 0){ cout << 0; goto next; }
		if ( sgn(a2) != sgn(a3) ){ cout << 0; goto next; }
		if ( !chk(a2, b2, c2, b3) ){ cout << 0; goto next; }
		if ( !chk(a2, b2, c2, a3*(c3-1) + b3) ){ cout << 0; goto next; }
		if ( !chk(a2, b2, c2, -a3 + b3) ){ cout << -1; goto next; }
		if ( !chk(a2, b2, c2, a3*c3 + b3) ){ cout << -1; goto next; }
		b2 *= sgn(a2); a2 *= sgn(a2);
		b3 *= sgn(a3); a3 *= sgn(a3);
		if (a2 == a3){
			vector<ll> dvs;
			for (ll i = 1; i*i <= a3; i++){
				if (a3 % i == 0){
					dvs.push_back(i);
					if (i*i != a3){ dvs.push_back(a3/i); }
				}
			}
			ll ans = 0;
			for (ll x : dvs){
				ll val = a2 / x;
				ans += val*val % mod; ans %= mod;
			}
			cout << ans;
			goto next;
		}
		else{
			ll dif = a3 / a2;
			vector<ll> dvs;
			for (ll i = 1; i*i <= a3; i++){
				if (a3 % i == 0){
					dvs.push_back(i);
					if (i*i != a3){ dvs.push_back(a3/i); }
				}
			}
			ll ans = 0;
			for (ll x : dvs){
				if (a2 % x == 0){ continue; }
				if (lcm(x, a2) != a3){ continue; }
				ll g = gcd(x, a2);
				ll val = a2 / g;
				ans += val*val % mod; ans %= mod;
			}
			cout << ans;
			goto next;
		}
		next: cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}