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

// E1. Chiori and Doll Picking (easy version)

const int MOD = 998244353;

int dp[37][37][1<<16];

void add_self(int& a, int b) {
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	// Gauss elimination
	int A = 0;
	for(int bit = 0; bit < m; ++bit) {
		for(int i = A; i < n; ++i) {
			if(a[i] & (1LL << bit)) {
				for(int j = 0; j < n; ++j) {
					if(i != j && (a[j] & (1LL << bit))) {
						a[j] ^= a[i];
					}
				}
				swap(a[i], a[A]);
				A++;
				break;
			}
		}
	}
	for(int i = A; i < n; ++i) {
		assert(a[i] == 0);
	}
	debug() << imie(A);
	
	int multiplier = 1;
	for(int i = A; i < n; ++i) {
		multiplier = 2 * multiplier % MOD;
	}
	vector<int> answer(m + 1);
	
	// #warning remove false
	if(A <= 22) {
		for(int mask = 0; mask < (1 << A); ++mask) {
			long long x = 0;
			for(int i = 0; i < A; ++i) {
				if(mask & (1 << i)) {
					x ^= a[i];
				}
			}
			answer[__builtin_popcountll(x)]++;
		}
	}
	else {
		// dp[row][cntHigh][mask_other_bits]
		
		vector<int> high;
		for(int i = 0; i < A; ++i) {
			int bit = 0;
			while((a[i] & (1LL << bit)) == 0) {
				bit++;
			}
			high.push_back(bit);
		}
		debug() << imie(a) imie(high);
		for(int i = 0; i < A - 1; ++i) {
			assert(high[i] < high[i+1]);
		}
		vector<int> non_high;
		for(int bit = 0; bit < m; ++bit) {
			bool is_high = false;
			for(int x : high) if(x == bit) is_high = true;
			if(!is_high) {
				non_high.push_back(bit);
			}
		}
		debug() << imie(high) imie(non_high);
		// {2, 5, 6}
		// {0, 1, 2}
		int z = m - A;
		assert(z == (int) non_high.size());
		// vector<int> mapping(z);
		// for(int i = 0; i < z; ++z) {
			// mapping[
		
		dp[0][0][0] = 1;
		for(int row = 0; row < A; ++row) {
			long long x = a[row];
			int mapped = 0;
			for(int i = 0; i < z; ++i) {
				if(x & (1LL << non_high[i])) {
					mapped ^= (1 << i);
				}
			}
			for(int cntHigh = 0; cntHigh <= row; ++cntHigh) {
				for(int mask = 0; mask < (1 << z); ++mask) {
					int me = dp[row][cntHigh][mask];
					add_self(dp[row+1][cntHigh][mask], me);
					add_self(dp[row+1][cntHigh+1][mask^mapped], me);
				}
			}
		}
		for(int cntHigh = 0; cntHigh <= A; ++cntHigh) {
			for(int mask = 0; mask < (1 << z); ++mask) {
				add_self(answer[cntHigh + __builtin_popcount(mask)], dp[A][cntHigh][mask]);
			}
		}
	}
	
	for(int x : answer) {
		printf("%lld ", (long long) x * multiplier % MOD);
	}
	puts("");
}
/*
v
0110
1011
0101
0001


Gauss elimination
vv  v        v    v   
2001000110000001000
0211010100010000000
------
0000200100000000000
0000000000000200100
0000000000000000002

dp[row][cntHigh][mask_other_bits]

order of linear base is 5
-> there are k-5 other bits
O(2^min(k, k-A))  -> O(2^(k/2))
*/