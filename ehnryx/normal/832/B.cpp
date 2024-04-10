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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

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

	bool star;
	bitset<26> good;
	string given, s;
	cin >> given;
	for (int i = 0; i < given.size(); i++)
		good[given[i]-'a'] = true;
	cin >> s;
	star = false;
	for (int i = 0; i < s.size(); i++) 
		if (s[i] == '*')
			star = true;

	bool bad;
	string query;
	int queries;
	cin >> queries;
	while (queries--) {
		cin >> query;
		//cerr << "string: " << s << nl << "query: " << query << endl;
		bad = false;
		if (query.size() < s.size() - star)
			bad = true;
		else for (int i = 0, j = 0; i < query.size(); i++, j++) {
			if (j == s.size()) {
				bad = true;
				break;
			}
			//cerr << "compare " << j << " " << i << ": " << s[j] << " " << query[i] << endl;
			if (s[j] != query[i]) {
				if (s[j] == '?') {
					if (!good[query[i]-'a']) {
						bad = true;
						break;
					}
				}
				else if (s[j] == '*') {
					for (int k = 0; k <= (int)(query.size() - s.size()); k++) {
						//cerr << "look at k = " << k << ", index " << i+k << endl;
						//assert(i+k < query.size());
						if (good[query[i+k]-'a']) {
							bad = true;
							break;
						}
					}
					i += query.size() - s.size();
				}
				else {
					bad = true;
					break;
				}
				if (bad)
					break;
			}
		}
		if (!bad) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}