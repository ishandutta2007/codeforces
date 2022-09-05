#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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



int main() {
	int n;
	scanf("%d", &n);
	vector<ll> a(n), b(n);
	for(ll& x : a) {
		scanf("%lld", &x);
	}
	for(ll& x : b) {
		scanf("%lld", &x);
	}
	// ll brute = 0;
	// for(int mask = 0; mask < (1 << n); ++mask) {
		// if(__builtin_popcount(mask) >= 2) {
			// bool ok = true;
			// for(int i = 0; i < n; ++i) {
				// if(mask & (1 << i)) {
					// bool someone = false;
					// for(int j = 0; j < n; ++j) {
						// if(mask & (1 << j)) {
							// if(i != j) {
								// if((a[i] & a[j]) == a[i]) {
									// someone = true;
								// }
							// }
						// }
					// }
					// if(!someone) {
						// ok = false;
						// break;
					// }
				// }
			// }
			// if(ok) {
				// ll maybe = 0;
				// for(int i = 0; i < n; ++i) {
					// if(mask & (1 << i)) {
						// maybe += b[i];
					// }
				// }
				// brute = max(brute, maybe);
			// }
		// }
	// }
	// debug() << imie(brute);
	ll answer = 0;
	vector<bool> valid(n);
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] == a[j]) {
				valid[i] = valid[j] = true;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		bool ok = false;
		for(int j = 0; j < n; ++j) {
			if(valid[j] && i != j && ((a[i] & a[j]) == a[i])) {
				ok = true;
			}
		}
		if(ok) {
			answer += b[i];
		}
	}
	// for(ll mask : a) {
		// int cnt = 0;
		// ll sum = 0;
		// for(int i = 0; i < n; ++i) {
			// if(a[i] == mask) {
				// cnt++;
			// }
			// if((mask & a[i]) == a[i]) {
				// sum += b[i];
			// }
		// }
		// if(cnt >= 2) {
			// answer = max(answer, sum);
		// }
	// }
	printf("%lld\n", answer);
	// if(brute) {
		// assert(answer == brute);
	// }
}