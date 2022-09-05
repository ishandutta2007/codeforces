#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int nax = 1e6 + 5;
vector<int> w[nax];
bool vis[nax];
bool whatever[nax];

void dfs(int a) {
	assert(!vis[a]);
	vis[a] = true;
	for(int b : w[a])
		if(!vis[b])
			dfs(b);
}

long long choose2(long long x) {
	return x * (x - 1) / 2;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int loops = 0, ordinary = 0;
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		whatever[a] = whatever[b] = true;
		if(a == b) ++loops;
		else {
			w[a].push_back(b);
			w[b].push_back(a);
			++ordinary;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(whatever[i]) {
			dfs(i);
			break;
		}
	for(int i = 1; i <= n; ++i)
		if(!vis[i] && whatever[i]) {
			puts("0");
			debug() << "not connected";
			return 0;
		}
	long long answer = choose2(loops);
	answer += (long long) loops * ordinary;
	for(int i = 1; i <= n; ++i)
		answer += choose2(w[i].size());
	printf("%lld\n", answer);
}