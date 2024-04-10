#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const ll INF = 1e18L + 5;

void mini(ll & a, ll b) { a = min(a, b); }

int main() {
	int n, need;
	cin >> n >> need;
	vector<long long> in(n);
	for(long long & x : in) cin >> x;
	while((int) in.size() <= 30) in.push_back(in.back() * 2);
	n = in.size();
	
	for(int rep = 0; rep <= 40; ++rep) {
		for(int i = 1; i < n; ++i)
			in[i] = min(in[i], 2 * in[i-1]);
		for(int i = n - 2; i >= 0; --i) in[i] = min(in[i], in[i+1]);
	}
	
	vector<long long> dp(n + 1, INF);
	dp[0] = 0;
	for(int i = 0; i < n; ++i) {
		if(!(need & (1LL << i))) {
			mini(dp[i+1], dp[i]);
			continue;
		}
		for(int j = i; j < n; ++j) {
			if(j == i) mini(dp[i+1], dp[i] + in[j]);
			else mini(dp[j], dp[i] + in[j]);
		}
	}
	printf("%lld\n", dp[n]);
		
	
	//~ long long answer = 0;
	//~ for(int i = 0; i < n; ++i) if(need & (1LL << i)) answer += in[i];
	//~ int enough = 0;
	//~ while((1 << enough) < need) ++enough;
	//~ answer = min(answer, in[enough]);
	//~ cout << answer << "\n";
}