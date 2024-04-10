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

void maxi(long long& a, long long b) {
	a = max(a, b);
}

long long max_sum(vector<int> a, vector<int> multi) { // (2, -5, 1) -> (0, 2, -5, 1, 0)
	int n = a.size();
	multi.insert(multi.begin(), 0);
	multi.insert(multi.end(), 0);
	int m = multi.size();
	// long long dp[n][m];
	const long long INF = 1e18L + 5;
	vector<vector<long long>> dp(n + 1, vector<long long>(m, -INF));
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			debug() << "dp[" << i << "][" << j << "] = " << dp[i][j];
			// dp[i][j] -> dp[i+1][j]
			maxi(dp[i+1][j], dp[i][j] + (long long) a[i] * multi[j]);
			if(j != m - 1) {
				maxi(dp[i][j+1], dp[i][j]);
			}
		}
	}
	long long answer = -INF;
	for(int j = 0; j < m; ++j) {
		maxi(answer, dp[n][j]);
	}
	return answer;
	// return dp[n][m-1];
}
// 0,1,x,1,0
// dp[3][2] = 12
// dp[4][2] = 10 -> dp[5][2]

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << max_sum(a, {1, x, 1}) << "\n";
}

/*
 * 
    <----------->
_ _ _ _ _ _ _ _ _ _
    <----------->
         x 5
         
         
x = 0

    <--------->
_ _ _ _ _ _ _ _ _
        000
        
x < 0 -> maybe we should multiply only negative values?

x = -3

10 10 -9 1 -9 10 10
      <----->
      
      
      
      
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
  <---> <-----> ...
    x2    x-5

multipliers: {2, -5, 3, 7, -1, 6}   {1, x, 1}
      
O(N * M)
      

_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
         ^
(i, sum so far, last used multiplier)      
      
int dp[i][last_used_multiplier];      
dp[i][
*/