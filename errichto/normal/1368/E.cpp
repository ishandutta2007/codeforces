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

const int nax = 2e5 + 5;
vector<int> edges[nax];

int r(int a, int b) {
	return a + rand() % (b - a + 1);
}

void test_case() {
	int n = 1000;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
	}
	// for(int i = n - 1; i >= 1; --i) {
		// int a = r(i + 1, n);
		// int b = r(i + 1, n);
		// edges[i].push_back(a);
		// if(a != b) {
			// edges[i].push_back(b);
		// }
	// }
	int turn = 0;
	while(true) {
		turn++;
		int prob = r(2, 10);
		if(turn % 3 == 0) {
			prob = 2;
		}
		if(turn % 7 == 0) {
			prob = 3;
		}
		vector<bool> removed(n + 1);
		int cnt = 0;
		for(int i = n; i >= 1; --i) {
			for(int a : edges[i]) if(!removed[a]) {
				for(int b : edges[a]) if(!removed[b]) {
					removed[i] = true;
					break;
				}
			}
			if(rand() % prob == 0) {
				removed[i] = true;
			}
			cnt += removed[i];
		}
		if(cnt * 7 <= 4 * n) {
			printf("%d\n", cnt);
			for(int i = 1; i <= n; ++i) {
				if(removed[i]) {
					printf("%d ", i);
				}
			}
			puts("");
			break;
		}
		// cout << cnt << endl;
	}
	for(int i = 0; i <= n; ++i) {
		edges[i].clear();
	}
}

int main() {
	int t = 10;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		test_case();
	}
}