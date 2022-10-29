#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#define ll long long
#define ALL(a) a.begin(), a.end()
using namespace std;
const int N = 1e6 + 1; 
const ll INF = 1e15;
int a[N << 1]; 
vector<ll> l[N << 1], s[N];

inline ll solve(ll id, ll h) {
	int bs = upper_bound(ALL(l[id]), h -= a[id]) - l[id].begin();
	if (bs) return h * bs - s[id][bs - 1];
	return 0;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i >= 2; --i) {
		l[i].push_back(0);
		int lc = i * 2, 
		    rc = i * 2 + 1;
		int slc = l[lc].size(), 
		    src = l[rc].size();
		for (int ilc = 0, irc = 0; ilc < slc || irc < src;) {
			ll hlc = ilc == slc ? INF : l[lc][ilc] + a[lc],
			   hrc = irc == src ? INF : l[rc][irc] + a[rc];
			l[i].push_back(hlc < hrc ? (++ilc, hlc) : (++irc, hrc));
		}
		s[i].resize(l[i].size());
		partial_sum(ALL(l[i]), s[i].begin());
	}
	for (int i = 1; i <= m; ++i) {
		ll id, h; scanf("%lld%lld", &id, &h);
		ll res = h + solve(id * 2, h) 
		       + solve(id * 2 + 1, h);
		for (h -= a[id]; id > 1; h -= a[id /= 2])
			res += max(0LL, h) + solve(id ^ 1, h);
		printf("%lld\n", res);
	}
}