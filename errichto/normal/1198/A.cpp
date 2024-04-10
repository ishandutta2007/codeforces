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

using ll = long long;



int main() {
	int n, I;
	scanf("%d%d", &n, &I);
	int answer = n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int lg = 0;
	debug() << imie(a);
	for(int nr_diff = 1; nr_diff <= 2 * n; nr_diff *= 2, ++lg) {
		int B = 0;
		int cnt = 1;
		for(int A = 0; A < n; ++A) {
			debug() << imie(A) imie(B) imie(nr_diff);
			if(B == A - 1) {
				B = A;
				cnt = 1;
			}
			while(B + 1 < n && (a[B] == a[B+1] || cnt + 1 <= nr_diff)) {
				if(a[B] != a[B+1]) {
					++cnt;
				}
				++B;
			}
			if(cnt <= nr_diff && n * lg <= I * 8) {
				answer = min(answer, A + (n - B) - 1);
			}
			int z = a[A];
			while(A < n && a[A] == z) {
				++A;
			}
			--A;
			--cnt;
		}
	}
	printf("%d\n", answer);
}