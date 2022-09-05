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

using ll = long long;

void min_self(ll& a, ll b) {
	a = min(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	ll r1, r2, r3;
	scanf("%lld%lld%lld", &r1, &r2, &r3);
	ll d;
	scanf("%lld", &d);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<pair<ll, ll>> his(n + 3);
	for(int i = 0; i < n; ++i) {
		ll t_small = min(r2, (a[i] + 1) * r1) + r1;
		ll t_big = r1 * a[i] + r3;
		min_self(t_big, t_small + 2 * d);
		his[i] = {t_small, t_big};
	}
	const ll INF = 4e18L + 5;
	vector<ll> dp(n + 3, INF);
	dp[0] = 0;
	for(int i = 0; i < n; ++i) {
		min_self(dp[i+1], dp[i] + his[i].second);
		min_self(dp[i+2], dp[i] + his[i].first + his[i+1].first + 2 * d);
	}
	ll answer = min({dp[n-1] + his[n-1].second, dp[n-2] + his[n-2].first + his[n-1].second + d, dp[n-2] + his[n-2].first + his[n-1].first + 2 * d});
	printf("%lld\n", answer + (ll) d * (n - 1));
		// if(i == n - 1) {
			// printf("%lld\n", answer + min(t_small, t_big));
			// return 0;
		// }
		// answer += min(t_small, t_big) + d;
		// debug() << imie(i) imie(answer);
	// }
	// printf("%lld\n", answer);
}