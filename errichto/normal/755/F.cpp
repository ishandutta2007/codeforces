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

const int nax = 1e6 + 5;
int cnt[nax], p[nax];
bool vis[nax];
bitset<nax> dp;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int seco = 0;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			int size = 0;
			do {
				vis[i] = true;
				++size;
				i = p[i];
			} while(!vis[i]);
			seco += size / 2;
			++cnt[size];
		}
	dp[0] = true;
	for(int size = 1; size <= n; ++size) if(cnt[size]) {
		int x = cnt[size];
		for(int i = 0; x; ++i) {
			dp |= dp << (size << i);
			x -= 1 << i;
			if(x & (1 << i)) {
				dp |= dp << (size << i);
				x -= 1 << i;
			}
		}
	}
	int strong = min(seco, k);
	printf("%d %d\n", k + !dp[k], min(n, strong * 2 + (k - strong)));
}