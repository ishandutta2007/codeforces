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
 
using ll = long long;

const int mod = 998244353;

int main() {
	vector<int> yes{1, 2};
	int a = 2;
	while(a <= 1000 * 1000) {
		a *= 2;
		yes.push_back(a);
		yes.push_back(++a);
		a = 2 * a - 1;
		yes.push_back(a);
		yes.push_back(++a);
	}
	//~ for(int x : yes) printf("%d ", x);
	int n;
	scanf("%d", &n);
	for(int x : yes) if(x == n) { puts("1"); return 0; }
	puts("0");
	return 0;
	/*
	int N;
	scanf("%d", &N);
	vector<int> dp(N + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 0;
	int low = 1, high = 3;
	for(int n = 4; n <= N; ++n) {
		for(int root = 1; root <= n; ++root) {
			int L = root - 1;
			int R = n - root;
			if(root % 2 == n % 2 && low <= min(L, R) && max(L, R) <= high) {
				dp[n] = (dp[n] + (ll) dp[L] * dp[R]) % mod;
			}
		}
		if(n == 2 * high + 1) {
			// [1, 3] -> [3, 7] -> [7, 15]
			low = high;
			high = 2 * high + 1;
		}
		// n = 4 -> 1&2 2&1
		// n = 5 -> 1&3 2&2 3&1
		// n = 6 -> 2&3 3&2
		// n = 7 -> 3&3
		
		// n = 8 -> 4&3 3&4
		// n = 14 -> 6&7 7&6
		// n = 15 -> 7&7
		
		
	}
	for(int i = 1; i <= N; ++i) {
		if(dp[i]) printf("%d\n", i);
		//~ printf("%d: %d\n", i, dp[i]);
	}
	//~ for(int x : dp) {
		//~ printf("%d ", x);
	//~ }
	//~ puts("");
	*/
}