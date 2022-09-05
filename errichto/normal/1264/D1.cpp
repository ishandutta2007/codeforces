#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int mod = 998244353;

const int nax = 2005;
int open[nax][nax], close[nax][nax];

void add_self(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}
int mul(int a, int b) {
	return (long long) a * b % mod;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	s = "#" + s;
	open[0][0] = close[n+1][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int x = 0; x < i; ++x) {
			if(s[i] != ')') {
				add_self(open[i][x+1], open[i-1][x]);
			}
			if(s[i] != '(') {
				add_self(open[i][x], open[i-1][x]);
			}
		}
	}
	for(int i = 0; i <= n + 1; ++i) {
		for(int j = n; j >= 0; --j) {
			add_self(open[i][j], open[i][j+1]);
		}
	}
	for(int i = n; i >= 1; --i) {
		for(int x = 0; x < (n - i + 1); ++x) {
			if(s[i] != '(') {
				add_self(close[i][x+1], close[i+1][x]);
			}
			if(s[i] != ')') {
				add_self(close[i][x], close[i+1][x]);
			}
		}
	}
	int answer = 0;
	for(int i = 2; i <= n; ++i) {
		if(s[i] == '(') {
			continue;
		}
		for(int x = 1; x <= n; ++x) {
			int y = x;
			// for(int y = x; y <= n; ++y) {
				add_self(answer, mul(close[i+1][x-1], open[i-1][y]));
				debug() << imie(i) imie(x) imie(y) imie(close[i+1][x]) imie(open[i-1][y]);
			// }
		}
	}
	printf("%d\n", answer);
}