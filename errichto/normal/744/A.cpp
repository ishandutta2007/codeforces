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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int N = 1005;
int spec[N];
vector<int> w[N];
bool vis[N];

int dfs(int a) {
	assert(!vis[a]);
	vis[a] = true;
	int s = 1;
	for(int b : w[a]) if(!vis[b]) s += dfs(b);
	return s;
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; ++i)
		scanf("%d", &spec[i]);
	for(int rep = 0; rep < m; ++rep) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	vector<int> they;
	for(int i = 0; i < k; ++i)
		they.push_back(dfs(spec[i]));
	sort(they.begin(), they.end());
	assert(!they.empty());
	for(int i = 1; i <= n; ++i) if(!vis[i]) they.back()++;
	int ans = 0;
	for(int x : they) ans += x * (x - 1) / 2;
	ans -= m;
	printf("%d\n", ans);
}