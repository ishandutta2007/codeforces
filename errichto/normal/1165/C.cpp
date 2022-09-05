#include "bits/stdc++.h"
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

// _ _ _ _ _ _
// dp[i][27]

const int MAX_N = 200 * 1000 + 5;
char a[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	char prev_ch = 0;
	int answer = 0;
	string s_print;
	for(int i = 0; i < n; ++i) {
		if(a[i] == prev_ch) {
			++answer; // remove a[i]
		}
		else {
			s_print += a[i];
			if(prev_ch == 0) {
				prev_ch = a[i];
			}
			else {
				prev_ch = 0;
			}
		}
	}
	if(prev_ch) {
		s_print.pop_back();
		++answer;
	}
	printf("%d\n", answer);
	printf("%s\n", s_print.c_str());
}