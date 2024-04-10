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
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int type = 0; type < 2; ++type) {
		vector<int> order;
		for(int turn = 0; turn < 2; ++turn) {
			for(int x : a) {
				if(x != 0) {
					if((type == turn) == (x > 0)) {
						order.push_back(x);
					}
				}
			}
		}
		for(int x : a) {
			if(x == 0) {
				order.push_back(x);
			}
		}
		debug() << imie(a) imie(order);
		assert(order.size() == a.size());
		int pref = 0;
		bool ok = true;
		for(int x : order) {
			pref += x;
			if(pref == 0) {
				ok = false;
			}
		}
		if(ok) {
			puts("YES");
			for(int x : order) {
				printf("%d ", x);
			}
			puts("");
			return;
		}
	}
	puts("NO");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}