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

vector<vector<int>> edges;
vector<int> dist;

void dfs(int a, int par) {
	for(int b : edges[a]) {
		if(b != par) {
			dist[b] = dist[a] + 1;
			dfs(b, a);
		}
	}
}

void test_case() {
	int n, sa, sb, A, B;
	scanf("%d%d%d%d%d", &n, &sa, &sb, &A, &B);
	edges.clear();
	dist.clear();
	edges.resize(n + 1);
	dist.resize(n + 1);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	if(B <= 2 * A) {
		puts("Alice");
		return;
	}
	dist[sa] = 0;
	dfs(sa, -1);
	if(dist[sb] <= A) {
		puts("Alice");
		return;
	}
	int best = 1;
	for(int i = 2; i <= n; ++i) {
		if(dist[i] > dist[best]) {
			best = i;
		}
	}
	dist[best] = 0;
	dfs(best, -1);
	for(int i = 1; i <= n; ++i) {
		if(dist[i] >= 2 * A + 1) {
			puts("Bob");
			return;
		}
	}
	puts("Alice");
}

// 1) B <= 2 * A -> Alice
// 2) Alice can win in first move -> Alice
// 3) diameter >= 2*A+1 -> Bob
// 4) Alice

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}