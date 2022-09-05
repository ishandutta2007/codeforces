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

// M

// a[i] >= M

// #d : d|M && a[i] >= d


const int mod = 1e9 + 7;
int mul(int a, int b) {
	return (long long) a * b % mod;
}
const int nax = 100'002;
int pref[nax];
int interval(int a, int b) {
	return pref[b] - (a ? pref[a-1] : 0);
}
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b%2) r = mul(r,a);
		a = mul(a,a);
		b /= 2;
	}
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++pref[x];
	}
	for(int i = 1; i < nax; ++i) {
		pref[i] += pref[i-1];
	}
	int answer = 0;
	for(int M = 1; M < nax; ++M) {
		// if(pref[M]) {
		vector<int> divisors;
		for(int i = 1; i * i <= M; ++i) {
			if(M % i == 0) {
				divisors.push_back(i);
				if(i * i != M) {
					divisors.push_back(M / i);
				}
			}
		}
		sort(divisors.begin(), divisors.end());
		// debug() << imie(M) imie(divisors.back());
		divisors.push_back(nax - 1);
		// 10 -> 1, 2, 5, 10
		int ways = 1, bad_ways = 1;
		for(int i = 0; i < (int) divisors.size() - 1; ++i) {
			int d1 = divisors[i];
			int d2 = divisors[i+1];
			// debug() << imie(d1) imie(d2-1) imie(interval(d1,d2-1));
			ways = mul(ways, my_pow(i + 1, interval(d1, d2 - 1)));
		}
		divisors.pop_back();
		divisors.pop_back();
		divisors.push_back(nax - 1);
		for(int i = 0; i < (int) divisors.size() - 1; ++i) {
			int d1 = divisors[i];
			int d2 = divisors[i+1];
			// debug() << imie(d1) imie(d2-1) imie(interval(d1,d2-1));
			bad_ways = mul(bad_ways, my_pow(i + 1, interval(d1, d2 - 1)));
		}
		if(ways || bad_ways) {
			debug() << imie(M) imie(ways) imie(bad_ways);
		}
		answer = (answer + ways - bad_ways) % mod;
		// }
	}
	printf("%d\n", (answer + mod + 1) % mod);
}