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

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> k(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &k[i]);
		--k[i];
	}
	sort(k.begin(), k.end());
	vector<int> cost(m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &cost[i]);
	}
	int low = 0, high = min(n, m);
	while(low < high) {
		int mid = (low + high + 1) / 2;
		// debug() << imie(low) imie(high) imie(mid);
		bool ok = true;
		for(int i = 0; i < mid; ++i) {
			if(k[n-mid+i] < i) {
				ok = false;
			}
		}
		if(ok) {
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}
	int mid = low;
	long long maybe = 0;
	for(int i = 0; i < n; ++i) {
		if(i < n - mid) {
			maybe += cost[k[i]];
		}
		else {
			maybe += cost[i - (n - mid)];
		}
	}
	long long answer = maybe;
	for(int i = mid - 1; i >= 0; --i) {
		maybe += cost[k[n-1-i]] - cost[i];
		answer = min(answer, maybe);
	}
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}