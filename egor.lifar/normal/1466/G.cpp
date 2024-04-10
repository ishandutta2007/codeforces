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
const int Mod = 1000000007;
const int MAXN = 100028;
const int P = 424243;
const int Mod1 = 1000000009;
const int P1 = 10007;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int n, q;
string s0;
string t;
int crit;
int p[MAXN];
int r2;
int rp[MAXN];
int pref[MAXN];
int k[MAXN];
string w[MAXN];
int ans[MAXN];
int last[MAXN];
int h[MAXN * 23], h1[MAXN * 23];
int ps[MAXN * 23], ps1[MAXN * 23];
int hs[MAXN * 23], hs1[MAXN * 23];


int gethash(int l, int r) {
	int a = h[r] - (l ? (ll)h[l - 1] * ps[r - l + 1]: 0) % Mod;
	if (a < 0) {
		a += Mod;
	}
	return a;
}


int gethash1(int l, int r) {
	int a = h1[r] - (l ? (ll)h1[l - 1] * ps1[r - l + 1]: 0) % Mod1;
	if (a < 0) {
		a += Mod1;
	}
	return a;
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 // read(FILENAME);
 	cin >> n >> q;
 	cin >> s0 >> t;
 	ps[0] = 1;
 	ps1[0] = 1;
 	for (int i = 1; i <= 1000000; i++) {
 		ps[i] = ((ll)ps[i - 1] * P) % Mod;
 		ps1[i] = ((ll)ps1[i - 1] * P1) % Mod1;
 	}
 	crit = n;
 	r2 = powm(2, Mod - 2);
 	p[0] = 1;
 	for (int i = 1; i <= n; i++) {
 		p[i] = sum(p[i - 1], p[i - 1]);
 	}
 	rp[0] = 1;
 	for (int i = 1; i <= n; i++) {
 		rp[i] = mul(rp[i - 1], r2);
 	}
 	for (int it = 0; it < q; it++) {
 		cin >> k[it];
 		cin >> w[it];
 	}
 	for (int it = 0; it < q; it++) {
 		for (auto x: w[it]) {
 			hs[it] = ((ll)hs[it] * P + x) % Mod;
 			hs1[it] = ((ll)hs1[it] * P1 + x) % Mod1;
 		}
 	}	
 	int crit = n;
	for (int j = 0; j <= n; j++) {
		if (j) {
			s0 = s0 + t[j - 1] + s0;
		}
		ll curh = 0, curh1 = 0;
		for (int i = 0; i < sz(s0); i++) {
			curh = (curh * P + s0[i]) % Mod;
			h[i] = curh;
			curh1 = (curh1 * P1 + s0[i]) % Mod1;
			h1[i] = curh1;
		}
		int mid = sz(s0) / 2;
		for (int it = 0; it < q; it++) {
			if (j <= k[it]) {
 				int cnt = 0;
 				if (j == 0) {
	 				for (int j = 0; j <= sz(s0) - sz(w[it]); j++) {
	 					if (gethash(j, j + sz(w[it]) - 1) == hs[it] && gethash1(j, j + sz(w[it]) - 1) == hs1[it]) {
	 						cnt++;
	 					}
	 				}
	 			} else {
	 				for (int j = max(0, mid - sz(w[it]) + 1); j <= min(sz(s0) - sz(w[it]), mid); j++) {
	 					//cout <<w[it] << endl;
	 					if (gethash(j, j + sz(w[it]) - 1) == hs[it] && gethash1(j, j + sz(w[it]) - 1) == hs1[it]) {
	 						cnt++;
	 					}
	 				}
	 			}
 				//cout << cnt << ' ' << w[it] << ' ' << s[j] << endl;
 				ans[it] = sum(ans[it], mul(cnt, p[k[it] - j]));
			}
		}
		if (sz(s0) >= 1000000) {
			crit = j;
			break;
		}
	}
	for (char midd = 'a'; midd <= 'z'; midd++) {
		for (int i = crit + 1; i <= n; i++) {
	 		pref[i] = pref[i - 1];
	 		if (t[i - 1] == midd) {
	 			pref[i] = sum(pref[i], rp[i]);
	 		}
	 	}
		bool need = false;
		for (int it = 0; it < q; it++) {
			int d = pref[k[it]];
			if (d == 0) {
				continue;
			}	
			need = true;
		}
		if (!need) {
			continue;
		}
		string mids;
		mids += midd;
		string ds;
		for (int i = max(0, sz(s0) - 1000000); i < sz(s0); i++) {
			ds += s0[i];
		}
		ds += mids;
		int mid = sz(ds) - 1;
		for (int i = 0; i < min(sz(s0), 1000000); i++) {
			ds += s0[i];
		}
		ll curh = 0, curh1 = 0;
		for (int i = 0; i < sz(ds); i++) {
			curh = (curh * P + ds[i]) % Mod;
			h[i] = curh;
			curh1 = (curh1 * P1 + ds[i]) % Mod1;
			h1[i] = curh1;
		}
		for (int it = 0; it < q; it++) {
			int d = pref[k[it]];
			if (d == 0) {
				continue;
			}
			int cnt = 0;
			for (int j = max(0, mid - sz(w[it]) + 1); j <= min(sz(ds) - sz(w[it]), mid); j++) {
				if (gethash(j, j + sz(w[it]) - 1) == hs[it] && gethash1(j, j + sz(w[it]) - 1) == hs1[it]) {
					cnt++;
				}
			}
			ans[it] = sum(ans[it], mul(cnt, mul(p[k[it]], d)));
		}	
	}
 	for (int it = 0; it < q; it++) {
	 	cout << ans[it] << '\n';
 	}
   	return 0;
}