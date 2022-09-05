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



int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<int> answer(n, -1);
	vector<vector<int>> rev_edges(n);
	vector<int> q;
	for(int i = 0; i < n; ++i) {
		for(int j : {i - a[i], i + a[i]}) {
			if(0 <= j && j < n) {
				if(a[i] % 2 != a[j] % 2) {
					answer[i] = 1;
					q.push_back(i);
				}
				rev_edges[j].push_back(i);
			}
		}
	}
	for(int z = 0; z < (int) q.size(); ++z) {
		int i = q[z];
		for(int j : rev_edges[i]) {
			// the actual edge is from j to i
			if(answer[j] == -1) {
				answer[j] = answer[i] + 1;
				q.push_back(j);
			}
		}
	}
	for(int x : answer) {
		printf("%d ", x);
	}
	puts("");
}