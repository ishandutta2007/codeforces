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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int pot = 1 << 20;
int tr[2*pot];

int findS(int a, int b) {
	if(a > b) return 0;
	a += pot;
	b += pot;
	int s = tr[a];
	if(a != b) s += tr[b];
	while(a < b - 1) {
		if(a % 2 == 0) s += tr[a+1];
		if(b % 2 == 1) s += tr[b-1];
		a /= 2, b /= 2;
	}
	return s;
}

void add(int a) {
	for(int i = pot + a; i >= 1; i /= 2)
		tr[i]++;
}

#define next next_compile

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	k = min(k, n - k);
	int now = 0;
	long long ans = 1;
	for(int rep = 0; rep < n; ++rep) {
		int next = now + k;
		int a = now + 1, b = next - 1;
		if(b >= n)
			ans += findS(a, n - 1) + findS(0, b % n);
		else
			ans += findS(a, b);
		++ans;
		add(now);
		now = next % n;
		add(now);
		// if(rand() % 10000 == 0)
		printf("%lld ", ans);
	}
	puts("");
}