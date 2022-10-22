#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

// Find x,y such that ax + by = d = gcd(a,b)
// * a^-1 (mod m): if (egcd(a,m,x,y) == 1) return (x+m)%m; else ERROR;
ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }

ll fact[1000001];
ll invf[1000001];
void init() {
	ll x, y;
	fact[0] = 1;
	invf[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		fact[i] = (i*fact[i-1]) % MOD;
		egcd(fact[i], MOD, x, y);
		invf[i] = (x+MOD) % MOD;
	}
}

ll get_count(const vector<int>& letters, int ub) {
	ll ans, res, sum;
	ans = sum = 0;
	res = 1;
	for (int i = 0; i < 26; i++) {
		res = (res * invf[letters[i]]) % MOD;
	}
	for (int i = 0; i < ub; i++) {
		if (letters[i] > 0) {
			ans = (ans + res * fact[letters[i]] % MOD * invf[letters[i]-1] % MOD) % MOD;
		}
	}
	for (int i = 0; i < 26; i++) {
		sum += letters[i];
	}
	if (sum == 0) return 0;
	else return fact[sum-1] * ans % MOD;
}

ll find_less(int n, vector<int> letters, const string& bound) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = bound[i]-'a'; j < 26; j++) {
			sum += letters[j];
		}
		if (sum == 0) {
			res = (res + get_count(letters, bound[i]-'a')) % MOD;
			break;
		} else {
			res = (res + get_count(letters, bound[i]-'a')) % MOD;
			//cerr << i << ": add " << get_count(letters, bound[i]-'a') % MOD << nl;
			if (letters[bound[i]-'a'] == 0)
				break;
			else 
				letters[bound[i]-'a']--;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();
	vector<int> letters(26);

	string a, b;
	cin >> a >> b;

	int n = a.size();

	for (int i = 0; i < n; i++) {
		letters[a[i]-'a']++;
	}

	cout << (find_less(n, letters, b) - find_less(n, letters, a) - 1 + MOD) % MOD << nl;

	return 0;
}