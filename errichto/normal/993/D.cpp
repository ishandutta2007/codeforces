#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

typedef long long ll;

const ll INF = 2e18L + 5;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<ll,ll>> in(n);
	for(auto & p : in) {
		scanf("%lld", &p.first);
		p.first *= 1000;
	}
	for(auto & p : in) scanf("%lld", &p.second);
	ll low = 0, high = 0;
	for(auto & p : in) high = max(high, p.first);
	sort(in.rbegin(), in.rend());
	debug() << imie(in);
	//~ low = high = 1000;
	while(low <= high) {
		ll answer = (low + high) / 2;
		//~ int can_skip = 0;
		vector<ll> dp(n + 1, INF);
		dp[0] = 0;
		for(int i = 0; i < (int) in.size(); ++i) {
			int A = i;
			int B = i;
			while(B + 1 < (int) in.size() && in[B].first == in[B+1].first) ++B;
			vector<ll> dp2(n + 1, INF);
			for(int j = 0; j <= i; ++j) if(dp[j] < INF)
				for(int new_skip = 0; new_skip <= B - A + 1; ++new_skip) if(j + new_skip <= i - j) {
					ll maybe = dp[j];
					for(int k = 0; k < B - A + 1 - new_skip; ++k)
						maybe += in[A+k].first - in[A+k].second * answer;
					dp2[j+new_skip] = min(dp2[j+new_skip], maybe);
				}
			dp = dp2;
			i = B;
		/*	int prv = i;
			//~ debug() << imie(i) imie(can_skip) imie(dp);
			ll here = in[i].first;
			int cnt = 0;
			while(i < (int) in.size() && in[i].first == here) {
				++cnt;
				ll extra = in[i].first - in[i].second * answer;
				for(int j = min((i + 1) / 2, prv); j >= 0; --j) {
					dp[j] += extra;
					if(j) dp[j] = min(dp[j], dp[j-1]);
				}
				++i;
			}
			--i;
			assert(cnt >= 1);
			//~ can_skip = i + 1;
			*/
		}
		debug() << imie(dp);
		//~ return 0;
		ll best = INF;
		for(int i = 0; i <= n; ++i)
			best = min(best, dp[i]);
		if(low == high) {
			if(best <= 0) printf("%lld\n", low);
			else printf("%lld\n", low + 1);
			break;
		}
		if(best == 0) {
			printf("%lld\n", answer);
			break;
		}
		if(best < 0) high = answer;
		else low = answer + 1;
	}
}