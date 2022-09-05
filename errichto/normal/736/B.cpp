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

const int nax = 2005;
#define div div_compile
int div[nax]; // smallest divisor
int dp[nax];

bool isPrime(int a) {
	for(int i = 2; i * i <= a; ++i)
		if(a % i == 0) return false;
	return true;
}

int main() {
	for(int i = 2; i * i < nax; ++i) if(div[i] == 0)
		for(int j = i * i; j < nax; j += i) div[j] = i;
	for(int i = 2; i < nax; ++i) {
		if(div[i] == 0) div[i] = 1;
		else div[i] = i / div[i]; // cost
	}
	for(int n = 2; n < nax; ++n) {
		dp[n] = div[n];
		for(int i = 2; i <= n - 2; ++i)
			dp[n] = min(dp[n], dp[i] + div[n-i]);
	}
	// for(int i = 0; i < 30; ++i) printf("%d: %d\n", i, dp[i]);
	int n;
	scanf("%d", &n);
	if(n < nax) {
		printf("%d\n", dp[n]);
		return 0;
	}
	int ans = -1;
	for(int rem = 2; rem < nax; ++rem) {
		int a = n - rem;
		if(2 <= a && isPrime(a)) {
			int maybe = 1 + dp[rem];
			if(ans == -1 || ans > maybe) ans = maybe;
		}
	}
	if(isPrime(n)) ans = 1;
	assert(ans != -1);
	printf("%d\n", ans);
}