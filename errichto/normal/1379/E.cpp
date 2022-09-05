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

const int nax = 105;
bool dp[nax][nax];

bool f(int n, int k) {
	if(n % 2 == 0) {
		return false;
	}
	// assert(n % 2 == 1);
	if(k == 0) {
		return __builtin_popcount(n + 1) == 1;
	}
	if(k == 2 && n == 9) {
		return false;
	}
	if(k == 1 && __builtin_popcount(n + 1) == 1) {
		return false;
	}
	return n >= 2 * k + 3;
}

const int MAX_N = 1e5 + 5;
int parent[MAX_N];

void rec(int n, int k, int root) {
	assert(f(n, k));
	if(n == 1) {
		return;
	}
	for(int n1 = 1; n1 < n; n1 += 2) {
		int n2 = n - 1 - n1;
		for(int k1 = 0; k1 <= min(n1,k); ++k1) {
			bool am_bad = (n1 >= 2 * n2 || n2 >= 2 * n1);
			int k2 = k - k1 - am_bad;
			if(k2 < 0) {
				continue;
			}
			// debug() << imie(n1) imie(k1) imie(n2) imie(k2);
			if(f(n1, k1) && f(n2, k2)) {
				parent[root+1] = root;
				parent[root+n1+1] = root;
				debug() << make_pair(n, k) << " = " << make_pair(n1, k1) << " + " << make_pair(n2, k2);
				
				rec(n1, k1, root+1);
				rec(n2, k2, root+n1+1);
				return;
			}
		}
	}
	assert(false);
}

int main() {
	{
		int n, k;
		cin >> n >> k;
		if(f(n, k)) {
			rec(n, k, 1);
			puts("YES");
			for(int i = 1; i <= n; ++i) {
				printf("%d ", parent[i]);
			}
			return 0;
		}
		puts("NO");
		return 0;
	}
	dp[1][0] = true;
	for(int n1 = 1; n1 < nax; ++n1) {
		for(int n2 = 1; n1 + n2 + 1 < nax; ++n2) {
			for(int k1 = 0; k1 < n1; ++k1) {
				for(int k2 = 0; k2 < n2; ++k2) {
					if(dp[n1][k1] && dp[n2][k2]) {
						dp[n1+n2+1][k1+k2+(n1>=2*n2 || n2>=2*n1)] = true;
					}
				}
			}
		}
	}
	for(int k = 0; k < 15; ++k) {
		for(int n = 1; n < nax; n += 2) {
			// if(!dp[n][k] && k == 2) debug() << imie(n);
			assert(f(n,k) == dp[n][k]);
			cout << dp[n][k];
		}
		cout << endl;
	}
	cout << "OK" << endl;
}

// impossible: k=1, n=7,15,31,63...   k=2,n=9