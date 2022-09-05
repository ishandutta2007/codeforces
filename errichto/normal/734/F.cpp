#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i ) {
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
  for (auto it = d.b; it != d.e; ++it)
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(c) { ris; }
#endif
};

#define imie(x) " [" <<  #x ": " << (x) << "] "

const int nax = 1e6 + 5;
int n;
int a[nax], b[nax], c[nax];
int cnt[30];

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	long long s = 0;
	for(int i = 1; i <= n; ++i) s += b[i] + c[i];
	if(s % (2 * n)) NO();
	s /= 2 * n;
	for(int i = 1; i <= n; ++i) {
		long long tmp = b[i] + c[i] - s;
		if(tmp < 0 || tmp % n) NO();
		if(tmp / n > 1000 * 1000 * 1000) NO();
		a[i] = tmp / n;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 30; ++j)
			cnt[j] += bool(a[i] & (1 << j));
	for(int i = 1; i <= n; ++i) {
		long long B = 0, C = 0;
		for(int j = 0; j < 30; ++j) {
			long long mul = 1 << j;
			if(a[i] & (1 << j)) {
				C += mul * n;
				B += mul * cnt[j];
			}
			else {
				C += mul * cnt[j];
			}
		}
		if(B != b[i] || C != c[i]) NO();
	}
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	puts("");
}