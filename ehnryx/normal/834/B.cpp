#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

// MODINT
template<int MOD> struct ModInt {
	ll x;
	ModInt(ll n=0) { n %= MOD; if (n < 0) n += MOD; x = n; }
	int get() const { return (int) x; }
	ModInt operator + (const ModInt& other) { return ModInt(x + other.x); }
	ModInt operator - (const ModInt& other) { return ModInt(x + MOD - other.x); }
	ModInt operator * (const ModInt& other) { return ModInt(x * other.x); } 
	ModInt& operator += (const ModInt& other) { x = (x + other.x) % MOD; return *this; }
	ModInt& operator -= (const ModInt& other) { x = (x + MOD - other.x) % MOD; return *this; }
	ModInt& operator *= (const ModInt& other) { x = (x * other.x) % MOD; return *this; }
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	bitset<26> curr;
	int last[26];
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++) {
		last[s[i]-'A'] = i;
	}
	int open = 0;
	for (int i = 0; i < n; i++) {
		if (curr[s[i]-'A'] == false) {
			curr[s[i]-'A'] = true;
			open++;
		}
		if (open > k) {
			cout << "YES" << endl;
			return 0;
		}
		if (last[s[i]-'A'] == i) {
			open--;
		}
	}
	cout << "NO" << endl;
	return 0;

	return 0;
}