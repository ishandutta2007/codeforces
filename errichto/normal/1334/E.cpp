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

const int mod = 998244353;

const int nax = 1005;
int C[nax][nax]; // binomial coefficients

// 2223233552

int main() {
	for(int i = 0; i < nax; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	
	long long D;
	scanf("%lld", &D);
	vector<long long> primes;
	for(long long i = 2; i * i <= D; ++i) {
		if(D % i == 0) {
			primes.push_back(i);
		}
		while(D % i == 0) {
			D /= i;
		}
	}
	if(D != 1) {
		primes.push_back(D);
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		int answer = 1;
		long long memo_g = __gcd(a, b);
		for(int rep = 0; rep < 2; ++rep) {
			long long g = memo_g;
			// a -> g
			int positions = 0;
			for(long long p : primes) {
				if(a % p == 0) {
					int one = 0, two = 0;
					while(a % p == 0) {
						one++;
						a /= p;
					}
					while(g % p == 0) {
						two++;
						g /= p;
					}
					int diff = abs(one - two); // 2^7  2^10
					debug() << imie(p) imie(diff);
					answer = (long long) answer * C[diff+positions][diff] % mod;
					positions += diff;
				}
			}
			swap(a, b);
		}
		printf("%d\n", answer);
	}
}

// 2^2 * 3^3 * 5^5
// 3x4x6 -> 1x1x1

// 3*4*6-1*1*1 = 71


// 3 - 1 - 2 - 4

// 6x4   2x7

   // 2x4 <- gcd

// 6 -> 2 -> 3

// DDDDU <- 1

// 3 -> 1 -> 3

// LLRR <- C(9, 4)

// DLLDDRDUR




// 2^5 * 3^20 -> 2^5 * 3^19 -> 2^5 * 3^18...
   // 6 + 6 + 6 + ... + 6 + 1 + 1 
   
   // 20*6+5*1=125
   
// 21 x 6 -> 21 x 5
// 2^5 * 3^20 -> 2^4 * 3^20 -> ...
// 21*5 + 20*1= 125