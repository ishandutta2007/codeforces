#include <bits/stdc++.h>
using namespace std;
 
#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif
 
#define ARG4(_1,_2,_3,_4,...) _4
 
#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)
 
#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)
 
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;
 
const ld pi = 3.1415926535897932384626433832795l;
 
template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}
 
const int N = 1000000;
 
struct Input {
	string s;
       
	bool read () {
		return getline(cin, s);
	}
 
	void init (const Input &input) {
		*this = input;
	}
};
 
struct Data: Input {
	string ans;
       
	void write () {
		puts(ans.c_str());
	}
       
	virtual void solve () {}
       
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int inf = 2 * N + 1;
	int n;
	int d[2 * N + 1];
	int mn1[N + 1], mn2[N + 1];
	bool ok[N + 1];
	
	static const ll mod = 1000000009;
	static const ll p1 = 7;
	static const ull p2 = 13;
	ll pp1[2 * N + 1];
	ull pp2[2 * N + 1];
	ll h1[2 * N + 1];
	ull h2[2 * N + 1];
	
	bool check (int i, int j) {
		int l = 0, r = n;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (!(((h1[i + m] - h1[i] * pp1[m]) - (h1[j + m] - h1[j] * pp1[m])) % mod) && !((h2[i + m] - h2[i] * pp2[m]) - (h2[j + m] - h2[j] * pp2[m]))) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		if (l == n) {
			return 0;
		}
		return s[i + l] == '(';
	}
       
	int calc () {
		debug(n);
		debug(s);
		debug(ok, ok + n);
		pp1[0] = 1;
		pp2[0] = 1;
		forn (i, 2 * N) {
			pp1[i + 1] = pp1[i] * p1 % mod;
			pp2[i + 1] = pp2[i] * p2;
		}
		h1[0] = h2[0] = 0;
		forn (i, 2 * n) {
			h1[i + 1] = (h1[i] * p1 + s[i]) % mod;
			h2[i + 1] = h2[i] * p2 + s[i];
		}
		int bst = -1;
		forn (i, n) {
			if (ok[i]) {
				if (bst == -1 || check(i, bst)) {
					bst = i;
				}
			}
		}
		return bst;
	}
       
	void solve () {
		deepen(0);
		n = sz(s);
		s = s + s;
		d[0] = 0;
		forn (i, 2 * n) {
			d[i + 1] = d[i] + (s[i] == '(') - (s[i] == ')');
		}
		mn1[n] = mn2[0] = inf;
		ford (i, n) {
			mn1[i] = min(mn1[i + 1], d[i]);
		}
		forn (i, n) {
			mn2[i + 1] = min(mn2[i], d[i + n]);
		}
		int k = d[n];
		if (k >= 0) {
			forn (i, n + 1) {
				ok[i] = min(mn1[i], mn2[i]) >= d[i];
			}
		} else {
			forn (i, n + 1) {
				ok[i] = min(mn1[i], mn2[i]) >= d[i + n];
			}
		}
		int st = calc();
		debug(st);
		ans = s.substr(st, n);
		debug(ans);
		if (k >= 0) {
			ans = ans + string(k, ')');
		} else {
			ans = string(-k, '(') + ans;
		}
	}
       
	void clear () {
		*this = Solution();
	}
};
 
Solution sol;
 
int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}