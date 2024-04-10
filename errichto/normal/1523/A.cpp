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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

char s[1005];

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	// int par = m % 2;
	if(m >= 2 * n) {
		m = m % (2 * n) + 2 * n;
	}
	debug() << imie(m);
	scanf("%s", s);
	vector<bool> yes(n);
	while(m--) {
		for(int i = 0; i < n; ++i) {
			if(s[i] == '0') {
				int cnt = 0;
				if(i != 0 && s[i-1] == '1') {
					cnt++;
				}
				if(i != n - 1 && s[i+1] == '1') {
					cnt++;
				}
				if(cnt == 1) {
					yes[i] = true;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			if(yes[i]) {
				s[i] = '1';
				yes[i] = false;
			}
		}
	}
	printf("%s\n", s);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}