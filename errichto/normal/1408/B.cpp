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
 
void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	vector<int> inc;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(i > 0 && a[i] > a[i-1]) {
			inc.push_back(i);
		}
	}
	if(k == 1) {
		if(inc.empty()) puts("1");
		else puts("-1");
	}
	else {
		int need = inc.size();
		debug() << imie(n) imie(need) imie(k);
		k--;
		int ans = (need + k - 1) / k;
		printf("%d\n", max(1, ans));
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
// 2,2,3,5,7,7,7...
// 0,0,0,0,0,4,6,6,10