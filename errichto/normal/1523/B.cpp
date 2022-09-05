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


// 5 7
// 12 7
// 12 -5
// 12 -17
// -5 -17
// -5 -12
// -5 -7


// 5 7
// -2 7
// -2 -5
// -2 -7
// 5 -7

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<vector<int>> ope;
	auto add = [&](int i, int j) {
		a[i] += a[j];
		ope.push_back({1, i, j});
	};
	auto sub = [&](int i, int j) {
		a[i] -= a[j];
		ope.push_back({2, j, i});
	};
	
	for(int i = 0; i < n; i += 2) {
		int j = i + 1;
		add(i, j);
		sub(j, i);
		sub(j, i);
		add(i, j);
		sub(j, i);
		sub(j, i);
	}
	debug() << imie(a);
	
	printf("%d\n", (int) ope.size());
	for(vector<int> v : ope) {
		printf("%d %d %d\n", v[0], v[1] + 1, v[2] + 1);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}