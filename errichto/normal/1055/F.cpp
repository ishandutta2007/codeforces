#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;
typedef unsigned long long ull;

const ull ONE = 1;

int main() {
	int T = 30;
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	vector<ull> a(n), on(n);
	//~ for(int i = 1; i < n; ++i) {
		//~ int par;
		//~ ll x = 0;
		//~ for(int rep = 0; rep < 3; ++rep) {
		    //~ x = x * RAND_MAX + rand();
		//~ }
		//~ par = rand() % i + 1;
		//~ a[i] = a[par-1] ^ x;
	//~ }
	for(int i = 1; i < n; ++i) {
		int par;
		ll x;
		scanf("%d%llu", &par, &x);
		a[i] = a[par-1] ^ x;
	}
	debug() << imie(a);
	ll count_smaller = 0;
	ull answer = 0;
	vector<ull> A(n);
	vector<pair<ull,ull>> B(n), tmp(n);
	for(int i = 0; i < n; ++i) {
		B[i] = make_pair(0ULL, a[i]);
	}
	sort(B.begin(), B.end());
	vector<ull> sorted = a;
	sort(sorted.begin(), sorted.end());
	for(int bit = 63; bit >= 0; --bit) {
		const ull ONLY = ONE << bit;
		answer |= ONLY;
		for(int i = 0; i < n; ++i) {
			if(a[i] & ONLY) {
				on[i] |= ONLY;
			}
			if(sorted[i] & ONLY) {
				A[i] |= ONLY;
			}
		}
		ll nowe = 0;
		for(int i = 0; i < n; ++i) {
			//~ A[i] = on[i];
			int type = T / 16 % 4;
			if(type == 3 || bool(B[i].second & ONLY) == type) {
				B[i].first ^= ONLY;
			}
			//~ B[i].first = A[i] ^ (answer ^ ONLY);
		}
		//~ sort(A.begin(), A.end());
		//sort(B.begin(), B.end());
		auto ple = [&]() {
			for(int i = 0; i < n - 1; ++i) {
				if(B[i].first > B[i+1].first) {
					int nxt = 0;
					int start = i;
					while(start - 1 >= 0 && B[start-1].first == B[start].first) {
						--start;
					}
					int en = i + 1;
					while(en + 1 < n && B[en].first == B[en+1].first) {
						++en;
					}
					for(int j = start; j <= i; ++j) {
						tmp[nxt++] = B[j];
					}
					nxt = start;
					for(int j = i + 1; j <= en; ++j) {
						B[nxt++] = B[j];
					}
					for(int j = nxt; j <= en; ++j) {
						B[j] = tmp[j-nxt];
					}
				}
			}
		};
		ple();
		int j = 0;
		for(int i = 0; i < n; ++i) {
			int cnt = 1;
			while(i + 1 < n && A[i] == A[i+1]) {
				++i;
				++cnt;
			}
			while(j < n && B[j].first < A[i]) {
				++j;
			}
			while(j < n && B[j].first == A[i]) {
				++j;
				nowe += cnt;
			}
		}
			
		//~ for(int i = 0; i < n; ++i) {
			//~ for(int j = 0; j < n; ++j) {
				//~ if((on[i] ^ on[j]) == (answer ^ ONLY)) {
					//~ ++nowe;
				//~ }
			//~ }
		//~ }
		if(count_smaller + nowe < k) {
			count_smaller += nowe;
			for(int i = 0; i < n; ++i) {
				int type = T / 4 % 4;
				if(type == 3 || bool(B[i].second & ONLY) == type) {
					B[i].first ^= ONLY;
				}
			}
		}
		else {
			answer ^= ONLY;
			for(int i = 0; i < n; ++i) {
				int type = T % 4;
				if(type == 3 || bool(B[i].second & ONLY) == type) {
					B[i].first ^= ONLY;
				}
			}
		}
		ple();
	}
	printf("%lld\n", answer);
	//~ vector<ll> pary;
	//~ for(int i = 0; i < n; ++i) {
		//~ for(int j = 0; j < n; ++j) {
			//~ pary.push_back(a[i] ^ a[j]);
		//~ }
	//~ }
	//~ debug() << imie(pary);
	//~ sort(pary.begin(), pary.end());
	//~ printf("%lld\n", pary[k-1]);
}