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

const int nax = 1005;
const int inf = 1e9 + 5;

int dp[nax], weight[nax], beauty[nax];
vector<int> w[nax];
bool vis[nax];
vector<int> vec;

void dfs(int a) {
	vec.push_back(a);
	vis[a] = true;
	for(int b : w[a]) if(!vis[b]) {
		dfs(b);
	}
}

int main() {
	int n, m, W;
	scanf("%d%d%d", &n, &m, &W);
	for(int i = 1; i <= n; ++i) scanf("%d", &weight[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &beauty[i]);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int i = 0; i <= W; ++i) dp[i] = -inf;
	dp[0] = 0;
	auto f = [&](int i, int val) {
		debug() << imie(i) << imie(val);
		if(i <= W && dp[i] < val) dp[i] = val;
	};
	for(int ii = 1; ii <= n; ++ii) if(!vis[ii]) {
		vec.clear();
		dfs(ii);
		int total_weight = 0, total_beauty = 0;
		for(int who : vec) {
			total_weight += weight[who];
			total_beauty += beauty[who];
		}
		for(int i = W; i >= 0; --i) {
			for(int who : vec) f(i + weight[who], dp[i] + beauty[who]);
			f(i + total_weight, dp[i] + total_beauty);
		}
	}
	int ans = dp[0];
	for(int i = 0; i <= W; ++i)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
}