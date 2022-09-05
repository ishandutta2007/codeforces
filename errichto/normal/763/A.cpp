#include <bits/stdc++.h>
using namespace std;

const long double CHANGE = 1e-8;
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

const int nax = 1e5 + 5;
vector<int> w[nax];
int col[nax];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int i = 1; i <=n ; ++i)
		scanf("%d", &col[i]);
	
	int bad = 0;
	for(int i = 1; i <= n; ++i)
		for(int b : w[i])
			if(i < b && col[i] != col[b])
				++bad;
	
	for(int i = 1; i <= n; ++i) {
		int tmp = 0;
		for(int b : w[i])
			if(col[i] != col[b])
				++tmp;
		if(tmp == bad) {
			puts("YES");
			printf("%d\n", i);
			return 0;
		}
	}
	puts("NO");
}