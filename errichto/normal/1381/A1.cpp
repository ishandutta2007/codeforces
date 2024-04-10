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

const int nax = 1e5 + 5;
char a[nax], b[nax];

void test_case() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	vector<int> queries;
	auto query = [&](int i) {
		queries.push_back(i + 1);
		reverse(a, a + i + 1);
		for(int j = 0; j <= i; ++j) {
			a[j] = (a[j] == '0' ? '1' : '0');
		}
	};
	for(int i = n - 1; i >= 0; --i) {
		if(a[i] != b[i]) {
			if(a[0] == b[i]) {
				query(0);
			}
			assert(a[0] != b[i]);
			query(i); // up to i
		}
		assert(a[i] == b[i]);
	}
	printf("%d", (int) queries.size());
	for(int x : queries) {
		printf(" %d", x);
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