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
	int n;
	scanf("%d", &n);
	vector<int> weight(n + 1); // 0 .. n
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &weight[i]);
	}
	vector<int> degree(n + 1);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++degree[a];
		++degree[b];
	}
	long long sum_w = 0;
	vector<int> extra;
	for(int x = 1; x <= n; ++x) {
		sum_w += weight[x];
		for(int rep = 0; rep < degree[x] - 1; ++rep) {
			extra.push_back(weight[x]);
		}
	}
	sort(extra.rbegin(), extra.rend());
	printf("%lld", sum_w);
	for(int k = 2; k <= n - 1; ++k) {
		sum_w += extra[k-2]; // out-of-boundary?
		printf(" %lld", sum_w);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
/*
sum_w = ...;

w[i] = 5, degree[i] = 3
w[i] = 4, degree[i] = 2
w[i] = 10, degree[i] = 4

5, 5, 4, 10, 10, 10

extra = {10, 10, 10, 5, 5, 4}
*/