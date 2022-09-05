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

long long INF = 1e18L + 5;

int main() {
	int n, d, m;
	scanf("%d%d%d", &n, &d, &m);
	vector<int> small(n+2, 0);
	vector<int> big(n+2, 0);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if(x <= m) {
			small.push_back(x);
		}
		else {
			big.push_back(x);
		}
	}
	sort(small.rbegin(), small.rend());
	sort(big.rbegin(), big.rend());
	big.insert(big.begin(), 0);
	for(int i = 1; i < (int) big.size(); ++i) {
		big[i] += big[i-1];
	}
	long long answer = 0;
	long long smalls = 0;
	for(int i = 0; i <= n; ++i) {
		int rem = n - i;
		int cnt_big = (rem + d) / (d + 1);
		long long maybe = big[cnt_big];
		debug() << imie(i) imie(smalls) imie(maybe) imie(cnt_big);
		answer = max(answer, maybe + smalls);
		smalls += small[i];
	}
	printf("%lld\n", answer);
}