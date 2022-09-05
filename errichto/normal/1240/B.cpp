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



int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		vector<vector<int>> where(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
			where[a[i]].push_back(i);
		}
		int different = 0;
		for(int x = 0; x < n; ++x) {
			if(!where[x].empty()) {
				++different;
			}
		}
		// int B = 1;
		// while(B < n) {
			// B *= 2;
		// }
		int answer = 0;
		int last = -1, cnt = 0;
		// vector<int> tree(2 * b);
		for(int x = 0; x < n; ++x) {
			if(!where[x].empty()) {
				int L = where[x][0];
				int R = where[x].back();
				if(L > last) {
					++cnt;
					last = R;
				}
				else {
					cnt = 1;
					last = R;
				}
				answer = max(answer, cnt);
			}
		}
		printf("%d\n", different - answer);
				// int best = 0;
				// for(int i = B + L; i > 1; i /= 2) {
					// if(i % 2 == 1) {
						// best = max(best, tree[i-1]);
					// }
				// }
				// best += where[x].size();
				// for(int i = B + R; i > 1; i /= 2) {
					// tree[i] = max(tree[i], best);
				// }
				// answer = max(answer, best);
			// }
		// }
	}
}