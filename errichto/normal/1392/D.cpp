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

const int nax = 1e6 + 5;
char s[nax];

int div_ceil(int a, int b) {
	return (a + b - 1) / b;
}

void test_case() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	assert(n == (int) strlen(s));
	int first = -1;
	for(int i = 0; i < n; ++i) {
		int j = i - 1;
		if(j == -1) {
			j = n - 1;
		}
		if(s[i] != s[j]) {
			first=  i;
			break;
		}
	}
	if(first == -1) {
		printf("%d\n", div_ceil(n, 3));
		return;
	}
	string s2;
	for(int i = 0; i < n; ++i) {
		s2 += s[(i+first)%n];
	}
	debug() << imie(s2);
	int answer = 0;
	for(int i = 0; i < n; ++i) {
		int cnt = 1;
		while(i + 1 < n && s2[i] == s2[i+1]) {
			++i;
			++cnt;
		}
		answer += cnt / 3;
	}
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}