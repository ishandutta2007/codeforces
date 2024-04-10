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

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		p[i] /= 100;
	}
	int x, a;
	scanf("%d%d", &x, &a);
	int y, b;
	scanf("%d%d", &y, &b);
	if(x < y) {
		swap(x, y);
		swap(a, b);
	}
	assert(x >= y);
	ll k;
	scanf("%lld", &k);
	sort(p.rbegin(), p.rend());
	int low = 1, high = n + 1;
	while(low < high) {
		int mid = (low + high) / 2;
		if(low + 10 < high) {
			mid = (low + 3 * high) / 4;
		}
		#define they p
		// vector<int> they(mid);
		
		// for(int i = 0; i < mid; ++i) {
			// they[i] = p[i];
		// }
		// sort(they.rbegin(), they.rend());
		long long tmp = (long long) a * b / __gcd(a, b);
		int cnt_both = mid / tmp;
		int cnt_a = mid / a - cnt_both;
		int cnt_b = mid / b - cnt_both;
		assert(cnt_both + cnt_a + cnt_b <= mid);
		long long total = 0;
		for(int i = 0; i < cnt_both; ++i) {
			total += (long long) they[i] * (x + y);
		}
		for(int i = cnt_both; i < cnt_both + cnt_a; ++i) {
			total += (long long) they[i] * x;
		}
		for(int i = cnt_both + cnt_a; i < cnt_both + cnt_a + cnt_b; ++i) {
			total += (long long) they[i] * y;
		}
		debug() << imie(mid) imie(they) imie(total);
		if(total >= k) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	if(low == n + 1) {
		low = -1;
	}
	printf("%d\n", low);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}