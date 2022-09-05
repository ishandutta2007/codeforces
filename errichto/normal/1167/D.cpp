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

const int MAX_N = 2e5 + 5;
char a[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	int pref[2] = {0, 0};
	for(int i = 0; i < n; ++i) {
		int who = 0;
		if(a[i] == '(') {
			if(pref[1] < pref[0]) {
				who = 1;
			}
		}
		else {
			if(pref[1] > pref[0]) {
				who = 1;
			}
		}
		printf("%d", who);
		pref[who] += (a[i] == '(' ? 1 : -1);
	}
	puts("");
}