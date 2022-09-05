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

const int mod = 998244353;

int three(int x) {
	return (__int128) x * (x - 1) * (x - 2) / 6 % mod;
}
int two(int x) {
	return (long long) x * (x - 1) / 2 % mod;
}



int main() {
	int n;
	scanf("%d", &n);
	int x = 1;
	int x2 = 0;
	// int pref = 0;
	int prv = 0;
	int prv_x = 0;
	vector<int> memo(n + 1), pref_memo(n + 1);
	for(int i = 0; i < n; ++i) {
		int y = (three(x) + 2LL * two(x) + x + two(x) + x + x) % mod; // length at most n
		// debug() << imie(x) imie(y);
		if(i == n - 1) {
			int z = (y - prv + mod) % mod;
			int answer = (2LL * z - 1 + mod) % mod;
			for(int a = 1; true; ++a) {
				int b = n - 1 - a;
				if(b < 1) {
					break;
				}
				answer = (answer + (long long) memo[a-1] * pref_memo[b-1]) % mod;
			}
			printf("%d\n", answer);
			
		}
		prv = y; // length at most n-1
		prv_x = x2;
		x2 = (two(x) + x) % mod;
		x = ((long long) two(x) + x + x + 1) % mod; // length at most n-1, at most two hands
		memo[i] = (x2 - prv_x + mod) % mod;
		pref_memo[i] = ((i ? pref_memo[i-1] : 0) + memo[i]) % mod;
		debug() << imie(i) imie(memo[i]) imie(pref_memo[i]);
		// x = y;
		// debug() << imie(y);
	}
}