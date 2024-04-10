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

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}

void test_case(int n) {
	vector<pair<int,int>> operations;
	for(int x = 3; x <= n - 1; ++x) {
		if(x != 8) {
			operations.emplace_back(x, n);
		}
	}
	assert((int) operations.size() <= n + 5);
	
	if(n <= 8) {
		// n /= 2
		int value = n;
		while(value > 1) {
			operations.emplace_back(n, 2);
			value = ceil_div(value, 2);
		}
	}
	else {
		// n /= 8
		int value = n;
		while(value > 1) {
			operations.emplace_back(n, 8);
			value = ceil_div(value, 8);
		}
		// 8 /= 2
		for(int rep = 0; rep < 3; ++rep) {
			operations.emplace_back(8, 2);
		}
	}
	
	printf("%d\n", (int) operations.size());
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		a[i] = i;
	}
	for(pair<int,int> p : operations) {
		printf("%d %d\n", p.first, p.second);
		a[p.first] = ceil_div(a[p.first], a[p.second]);
		assert(1 <= min(p.first, p.second) && max(p.first, p.second) <= n);
	}
	sort(a.begin(), a.end());
	assert(a.back() == 2);
	assert(a[(int)a.size()-2] == 1);
}

int main() {
	// for(int n = 3; n <= 10; ++n) {
		// test_case(200'003 - n);
	// }
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		test_case(n);
	}
}

/*
solution in N+log(N) steps:
get rid of 3, 4, ..., N-1

Keep dividing N by 2.


N -> sqrt(N) -> sqrt(sqrt(N))

1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 1 1 1 1 10
1 2 3 4 5 1 1 1 1 2

101 10
11 10
2 10



N, 8, 2 -> N + log_8(N) + O(1)


log(N) = 17
log8(N) = 6

1, 2, ...

8 and N are special

N-4 + 6 + 3 = N + 5

*/