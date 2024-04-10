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

string a = "codeforces";

pair<long long,string> dp[1605][1605];

int main() {
	dp[0][0] = {1,""};
	long long k;
	cin >> k;
	for(int len = 0; len < 1000; ++len) {
		for(int i = 0; i < (int) a.length(); ++i) {
			for(int c = 1; c <= 100; ++c) {
				if(dp[len][i].first * c >= dp[len+c][i+1].first) {
					dp[len+c][i+1].first = dp[len][i].first * c;
					dp[len+c][i+1].second = dp[len][i].second + string(c, a[i]);
				}
				// dp[len+c][i+1] = max(dp[len+c][i+1], dp[len][i] * c);
			}
		}
		if(dp[len][(int)a.length()].first >= k) {
			cout << dp[len][(int)a.length()].second << endl;
			return 0;
		}
	}
	
}