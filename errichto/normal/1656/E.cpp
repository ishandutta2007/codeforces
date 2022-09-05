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

const int nax = 1e5 + 5;
vector<int> edges[nax];
int answer[nax];

void dfs(int a, int parent, int type) {
	answer[a] += type;
	debug() << imie(a) imie(answer[a]);
	for(int b : edges[a]) {
		if(b != parent) {
			dfs(b, a, type * -1);
			answer[a] += type;
			debug() << imie(a) imie(b) imie(answer[a]) imie(type);
		}
	}
}

void test_case() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		if((int) edges[i].size() == 1) {
			answer[i] = -1;
			dfs(i, -1, 1);
			break;
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d ", answer[i]);
		answer[i] = 0;
	}
	puts("");
	for(int i = 0; i <= n; ++i) {
		edges[i].clear();
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}