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
int child[30*nax][2];
int cnt[30*nax];
int nxt;

int dfs(int node) {
	if(cnt[node]) {
		return cnt[node];
	}
	vector<int> v;
	for(int me : {0, 1}) {
		if(child[node][me]) {
			v.push_back(dfs(child[node][me]));
		}
		else {
			v.push_back(0);
		}
	}
	return max(v[0] + min(1, v[1]), v[1] + min(1, v[0]));
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		int node = 0;
		for(int bit = 29; bit >= 0; --bit) {
			bool me = x & (1 << bit);
			if(!child[node][me]) {
				child[node][me] = ++nxt;
			}
			node = child[node][me];
		}
		cnt[node]++;
	}
	printf("%d\n", n - dfs(0));
}