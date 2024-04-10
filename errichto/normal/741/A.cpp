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

const int nax = 105;
int t[nax];
bool vis[nax];
int last;
int size;
void dfs(int a) {
	++size;
	last = t[a];
	vis[a] = true;
	if(!vis[t[a]]) dfs(t[a]);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		--t[i];
	}
	long long ans = -1;
	for(int i = 0; i < n; ++i) if(!vis[i]) {
		last = -1;
		size = 0;
		dfs(i);
		assert(last != -1);
		if(last != i) {
			puts("-1");
			return 0;
		}
		assert(size);
		if(size % 2 == 0) size /= 2;
		debug() << imie(size);
		if(i == 0) ans = size;
		else ans = ans / __gcd(ans, (long long) size) * size;
	}
	printf("%lld\n", ans);
}