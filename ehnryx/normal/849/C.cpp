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

int findT(int n) {
	int left, mid, right;
	left = 1;
	right = 1e3;
	while (left <= right) {
		mid = (left+right)/2;
		if (mid*(mid-1)/2 > n)
			right = mid-1;
		else
			left = mid+1;	
	}
	if (mid*(mid-1)/2 > n)
		mid--;
	return mid;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	if (n == 0) {
		cout << "a" << nl;
	}
	else {
		vector<char> ans;
		char curr = 'a';
		while (n > 0) {
			int tri = findT(n);
			assert(curr <= 'z');
			for (int i = 0; i < tri; i++) {
				ans.push_back(curr);
			}
			n -= tri*(tri-1)/2;
			curr++;
		}
		for (char c: ans) {
			cout << c;
		} cout << nl;
	}

	return 0;
}