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

#warning increase nax!!!
const int nax = 1e6 + 5;
long long dp[7][nax];
const long long INF = 1e18L + 5;

struct S {
	vector<vector<long long>> big;
	void init(vector<long long> a) {
		int n = a.size();
		big.push_back(a);
		for(int k = 1; (1 << k) <= (int) a.size(); ++k) {
			vector<long long> new_max(n - (1 << k) + 1);
			for(int i = 0; i + (1 << k) - 1 < n; ++i) {
				new_max[i] = max(big[k-1][i], big[k-1][i+(1<<(k-1))]);
			}
			big.push_back(new_max);
		}
	}
	long long get_max(int L, int R) {
		// assert(0 <= L && L <= R && R < (int) a.size());
		int len = R - L + 1;
		int k = 0; //31 - __builtin_clz(len);
		while(1 << (k + 1) <= len) {
			++k;
		}
		return max(big[k][L], big[k][(R-(1<<k)+1)]);
		// long long big = a[L];
		// for(int i = L; i <= R; ++i) {
			// big = max(big, a[i]);
		// }
		// return big;
	}
};

int main() {
	int k;
	scanf("%d", &k);
	vector<long long> F(6);
	for(int i = 0; i < 6; ++i) {
		scanf("%lld", &F[i]);
	}
	for(int pos = 0; pos < 7; ++pos) {
		for(int i = 0; i < nax; ++i) {
			dp[pos][i] = -INF;
		}
	}
	dp[0][0] = 0;
	int ten = 1;
	for(int pos = 0; pos < 6; ++pos, ten *= 10) {
		// dp[pos][...] -> dp[pos+1][...]
		const int jump = 3 * ten;
		vector<vector<long long>> group(jump);
		for(int i = 0; i < nax; ++i) {
			group[i%jump].push_back(dp[pos][i]);
		}
		for(auto& vec : group) {
			for(int i = 0; i < (int) vec.size(); ++i) {
				vec[i] -= i * F[pos];
			}
		}
		vector<S> DS(jump);
		for(int i = 0; i < jump; ++i) {
			DS[i].init(group[i]);
			// DS[i].a = group[i];
			// DS[i].
		}
		for(int dig = 0; dig < 10; ++dig) {
			int rem = k - 1;
			if(dig == 0) {
				rem++;
			}
			#define k dont_use_k
			for(int val = 0; val < nax; ++val) {
				int prev = val - ten * dig;
				if(prev < 0) {
					continue;
				}
				long long offset = F[pos] * (prev / jump);
				int R = prev / jump;
				int L = max(0, prev / jump - 3 * rem);
				long long best = DS[prev%jump].get_max(L, R);
				// for(int i = L; i <= R; ++i) {
					// best = max(best, group[prev%jump][i]);
				// }
				// for(int step = 0; step <= 3 * rem && prev >= 0; step++, prev -= jump) {
					// best = max(best, group[prev % jump][prev/jump]);
				// }
				dp[pos+1][val] = max(dp[pos+1][val], best + offset);
			}
		}
	}
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", dp[6][x]);
	}
}