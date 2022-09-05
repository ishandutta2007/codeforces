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

const int nax = 3e5 + 5;
vector<int> edges[nax];
bool forbidden[nax];
vector<int> taken;
bool visited[nax];

void dfs(int a) {
	assert(!visited[a]);
	visited[a] = true;
	if(!forbidden[a]) {
		forbidden[a] = true;
		taken.push_back(a);
		for(int b : edges[a]) {
			forbidden[b] = true;
		}
	}
	for(int b : edges[a]) {
		if(!visited[b]) {
			dfs(b);
		}
	}
}

void test_case() {
	taken.clear();
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(m >= n - 1) {
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
	}
	if(m < n - 1) {
		puts("NO");
		return;
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			taken.clear();
		}
	}
	for(int i = 0; i <= n; ++i) {
		edges[i].clear();
		visited[i] = forbidden[i] = false;
	}
	if(taken.empty()) {
		puts("NO");
	}
	else {
		puts("YES");
		printf("%d\n", (int) taken.size());
		for(int x : taken) {
			printf("%d ", x);
		}
		puts("");
	}
	taken.clear();
}	

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
	
}