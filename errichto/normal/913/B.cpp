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

const int nax = 1005;
int cnt[nax], par[nax];
bool isLeaf[nax];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) isLeaf[i] = true;
	for(int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		par[i] = x;
		isLeaf[x] = false;
		//~ ++cnt[x];
	}
	for(int i = 2; i <= n; ++i)
		if(isLeaf[i]) ++cnt[par[i]];
	for(int i = 1; i <= n; ++i)
		if(!isLeaf[i] && cnt[i] < 3) {
			puts("No");
			return 0;
		}
	puts("Yes");
}