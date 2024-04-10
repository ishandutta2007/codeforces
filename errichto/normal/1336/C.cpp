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

const int nax = 3005;
int dp[2*nax][2*nax];
// 6000 * 6000 * 4B
// 36*4 ~= 140MB
const int MOD = 998244353;

void add_self(int& a, int b) {
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
}

int main() {
	string s, target;
	cin >> s;
	cin >> target;
	int n = s.length();
	int m = target.length();
	// abcadd???????????????
	 // ^    ^^^^^^^^^^^^^^^
	for(int i = 0; i < m; ++i) {
		if(target[i] == s[0]) {
			dp[i][i] = 2;
		}
	}
	for(int i = m; i <= n + m; ++i) {
		dp[i][i] = 2;
	}
	for(int i = 1; i < n; ++i) {
		char ch = s[i];
		for(int L = 0; true; L++) {
			int R = L + i - 1;
			if(R >= n + m) {
				break;
			}
			if(L > 0 && (L - 1 >= m || ch == target[L-1])) {
				add_self(dp[L-1][R], dp[L][R]);
			}
			if(R + 1 >= m || ch == target[R+1]) {
				add_self(dp[L][R+1], dp[L][R]);
			}
		}
	}
	int answer = 0;
	for(int R = m - 1; R <= n + m; ++R) {
		add_self(answer, dp[0][R]);
	}
	printf("%d\n", answer);
}
/*
asldkfjaslkdfja
   <------>


----------lasjdfklas

?algorithms

goal
 <->

dp0[removed][where_start]
dp[removed][suffix_matched]

dp[i][j] -> dp[i+1][j]
dp[i][j] -> dp[i+1][nxt[j][ch]]


dp[L][R] - numbers of ways to get this substring


targexgettarg?????????????????????
          argvs*/