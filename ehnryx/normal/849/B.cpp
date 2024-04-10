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

pair<int,int> get_slope(int y[], int i, int j) {
	int rise = y[i]-y[j];
	int run = i-j;
	int g = __gcd(rise, run);
	rise /= g;
	run /= g;
	if (rise < 0) return pair<int,int>(-rise, -run);
	else return pair<int,int>(rise, run);
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	bool online;
	pair<int,int> foundslope(0,0);
	int n;
	cin >> n;
	int y[n+1];
	for (int i = 1; i <= n; i++) 
		cin >> y[i];
	map<pair<int,int>,int> slopes;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			pair<int,int> curr = get_slope(y, i, j);
			slopes[curr]++;
			if (slopes[curr] >= 3) {
				foundslope = curr;
				goto next;
			}
		}
	}
	next:
	if (foundslope.second == 0) {
		if (n == 3) {
			cout << "Yes" << nl;
			return 0;
		}
		else if (n == 4) {
			if (slopes.size() == 1 || slopes.size() == 6)
				cout << "No" << nl;
			else
				cout << "Yes" << nl;
			return 0;
		}
		else {
			cout << "No" << nl;
			return 0;
		}
	}
	int start = 0;
	for (int i = 1; i <= n; i++) {
		online = false;
		for (int j = 1; j < i; j++) {
			if (get_slope(y, i, j) == foundslope) {
				online = true;
				break;
			}
		}
		if (!online) {
			start++;
		}
	}

	if (start != 2)
		cout << "No" << nl;
	else 
		cout << "Yes" << nl;

	return 0;
}