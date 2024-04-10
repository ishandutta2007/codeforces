#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int nax = 1e5 + 5;
int in[nax], t[nax];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &in[i]);
	long long answer = 0;
	long long suff = 0;
	long long big = 0, small = 0;
	for(int i = n - 1; i >= 1; --i) {
		int diff = abs(in[i] - in[i+1]);
		bool par = i % 2;
		if(par) diff *= -1;
		suff += diff;
		if(par) answer = max(answer, big - suff);
		else answer = max(answer, suff - small);
		big = max(big, suff);
		small = min(small, suff);
		debug() << imie(suff);
	}
	/*for(int rep = 0; rep < 2; ++rep) {
		for(int i = 1; i <= n - 1; ++i)
			t[i] = (rep ? 1 : -1) * (in[i+1] - in[i]);
		long long so_far = 0;
		for(int i = 1; i <= n - 1; ++i) {
			so_far += t[i];
			if(so_far < 0) so_far = 0;
			answer = max(answer, so_far);
		}
	}*/
	printf("%lld\n", answer);
}