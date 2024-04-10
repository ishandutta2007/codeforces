#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000009;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



ll MAXM = 100100;
vl fact(MAXM);
vl rfact(MAXM);

ll mod_pow(ll x, ll p, ll M) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll m) {
	return mod_pow(a, m - 2, m);
}

ll nCr(ll n, ll r) {
	ll ret = fact[n];
	ret = (ret*mod_inverse(fact[r], MOD)) % MOD;
	ret = (ret*mod_inverse(fact[n - r], MOD)) % MOD;
	return ret;
}

ll n, a, b, k;
string s;
ll solve2() {
	ll ans = 0;
	rep(i, n + 1) {
		int j = i%k;
		if (s[j] == '+') {
			ans += mod_pow(a, n - i, MOD)*mod_pow(b, i, MOD) % MOD;
			ans %= MOD;
		}
		else {
			ans -= mod_pow(a, n - i, MOD)*mod_pow(b, i, MOD) % MOD;
			ans %= MOD;
		}
	}
	while (ans < 0) {
		ans += MOD;
	}
	return ans;
}

#include <random>
int main() {
	cin >> n >> a >> b >> k;
	cin >> s;
	//DEBUG(a); DEBUG(b); DEBUG(n);  DEBUG(k); DEBUG(s);
	ll x = 0, y = 0;
	rep(i, k) {
		if (s[i] == '+') {
			y += mod_pow(a, n % k - i, MOD) * mod_pow(b, i, MOD) % MOD;
		}
		else {
			y -= mod_pow(a, n % k - i, MOD) * mod_pow(b, i, MOD) % MOD;
		}
		y %= MOD;
	}
	while (y < 0)
		y += MOD;
	if (mod_pow(b, k, MOD) * mod_pow(mod_inverse(a, MOD), k, MOD) == 1) {
		x = mod_pow(a, n + 1 - k, MOD);
		x = x * ((n + 1) / k) % MOD;
	}
	else {
		ll m = n + 1 - k;
		x = 1LL - mod_pow(b, n + 1, MOD) * mod_pow(mod_inverse(a, MOD), n + 1, MOD);
		x %= MOD;
		x = x * mod_pow(a, m, MOD) % MOD;
		ll temp = 1LL - mod_pow(b, k, MOD) * mod_pow(mod_inverse(a, MOD), k, MOD) % MOD;
		temp %= MOD;
		x = x * mod_inverse(temp, MOD) % MOD;
	}
	while (x < 0) {
		x += MOD;
	}
	ll ans = x*y%MOD;
	while (ans < 0) {
		ans += MOD;
	}
	//ll ans2 = solve2();
	//DEBUG(ans);
	//DEBUG(ans2);
	cout << ans << endl;
}