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
	vector<int> a(n + 1);
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(sum % n != 0) {
		puts("-1");
		return;
	}
	int should = sum / n;
	vector<vector<int>> print;
	auto f = [&](int i, int j, int x) {
		assert(x % i == 0);
		assert(x != 0);
		a[i] -= x;
		assert(a[i] >= 0);
		a[j] += x;
		print.push_back({i, j, x / i});
	};
	for(int i = 2; i <= n; ++i) {
		int rem = a[i] % i;
		rem = (i - rem) % i;
		if(rem != 0) {
			f(1, i, rem);
		}
		assert(a[i] % i == 0);
		f(i, 1, a[i]);
		assert(a[i] == 0);
	}
	for(int i = 2; i <= n; ++i) {
		f(1, i, should);
	}
	for(int i = 1; i <= n; ++i) {
		assert(a[i] == should);
	}
	assert((int) print.size() <= 3 * n);
	printf("%d\n", (int) print.size());
	for(vector<int> v : print) {
		printf("%d %d %d\n", v[0], v[1], v[2]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}

// N = 6
// 1 1 2 1 1 1