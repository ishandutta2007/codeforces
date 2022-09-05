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

int mul(int a, int b) {
	return (long long) a * b % mod;
}
void add_self(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}
int add(int a, int b) {
	add_self(a, b);
	return a;
}

vector<int> get_dp(vector<bool> killed) {
	int n = killed.size();
	// dp[x] should be the number of ways to choose x
	// disjoint pairs of adjacent not-killed positions
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		// Compute dp[i+1]
		for(int x = 0; x <= n; ++x) {
			add_self(dp[i+1][x], dp[i][x]); // doing nothing
			if(i >= 1 && x >= 1 && !killed[i] && !killed[i-1]) {
				add_self(dp[i+1][x], dp[i-1][x-1]);
			}
		}
	}
	return dp[n];
}

int main() {
	int H, W, n;
	scanf("%d%d%d", &H, &W, &n);
	vector<bool> row_killed(H), col_killed(W);
	for(int rep = 0; rep < n; ++rep) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		--r1; --c1; --r2; --c2;
		row_killed[r1] = row_killed[r2] = true;
		col_killed[c1] = col_killed[c2] = true;
	}
	vector<int> dp_row = get_dp(row_killed);
	vector<int> dp_col = get_dp(col_killed);
	const int M = max(H, W) + 1;
	vector<vector<int>> choose(M + 1, vector<int>(M + 1));
	vector<int> fac(M + 1); // factorial;
	fac[0] = 1;
	for(int i = 1; i <= M; ++i) {
		fac[i] = mul(fac[i-1], i);
	}
	for(int i = 0; i <= M; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			choose[i][j] = add(choose[i-1][j-1], choose[i-1][j]);
		}
	}
	for(bool is_killed : row_killed) {
		H -= is_killed;
	}
	for(bool is_killed : col_killed) {
		W -= is_killed;
	}
	debug() << "after subtracting: " imie(H) imie(W);
	int answer = 0;
	for(int v = 0; v <= min(W, H / 2); ++v) {
		for(int h = 0; h <= min(H, W / 2); ++h) {
			int ways = mul(fac[v], mul(fac[h], mul(dp_row[v], mul(dp_col[h], mul(choose[W-2*h][v], choose[H-2*v][h])))));
			debug() << imie(h) imie(v) imie(ways);
			add_self(answer, ways);
		}
	}
	printf("%d\n", answer);
}
/*
x...
x...   x4

xx..
....   x6

xx..
..xx   x2

....
....   x1
*/