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

const int nax = 3e5 + 5;
char s[nax];

void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	assert(n == (int) strlen(s));
	vector<bool> must_one(k), must_zero(k);
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			must_one[i%k] = true;
		}
		if(s[i] == '0') {
			must_zero[i%k] = true;
		}
	}
	int ones = 0, zeros = 0;
	for(int i = 0; i < k; ++i) {
		if(must_zero[i] && must_one[i]) {
			puts("NO");
			return;
		}
		ones += must_one[i];
		zeros += must_zero[i];
	}
	if(ones > k / 2 || zeros > k / 2) {
		puts("NO");
	}
	else {
		puts("YES");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}