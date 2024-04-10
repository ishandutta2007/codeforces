#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const ll MAXN = 600228;
const ll Mod = 998244353;


ll sum(ll a, ll b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}
 
 
ll mul(ll a, ll b) {
	return ((ll)a * b) % Mod;
}


ll powm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


ll n;
ll a[MAXN];
ll fact[MAXN];
ll rfact[MAXN];


ll getC(ll i, ll j) {
	return mul(fact[i], mul(rfact[j], rfact[i - j]));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	fact[0] = 1;
	for (ll i = 1; i <= 2 * n; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	rfact[2 * n] = powm(fact[2 * n], Mod - 2);
	for (ll i = 2 * n - 1; i >= 0; i--) {
		rfact[i] = mul(rfact[i + 1], i + 1);
	}
	for (ll i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	ll ans = 0;
	ll f = getC(2 * n - 1, n - 1);
	for (ll i = 0; i < 2 * n; i++) {
		if (i >= n) {
			ans = sum(ans, mul(f, a[i]));
		} else {
			ans = sum(ans, mul(f, Mod - a[i]));
		}
	}
	reverse(a, a + 2 * n);
	for (ll i = 0; i < 2 * n; i++) {
		if (i < n) {
			ans = sum(ans, mul(f, a[i]));
		} else {
			ans = sum(ans, mul(f, Mod - a[i]));
		}
	}
	ans %= Mod;
	if (ans < 0) {
		ans += Mod;
	}
	cout << ans << '\n';
}