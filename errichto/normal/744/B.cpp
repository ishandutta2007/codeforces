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

int n;
const int inf = 1e9 + 5;

vector<int> query(vector<int> w) {
	printf("%d\n", (int) w.size());
	for(int x : w) printf("%d ", x + 1);
	puts("");
	fflush(stdout);
	vector<int> ans(n);
	for(int i = 0; i < n; ++i) scanf("%d", &ans[i]);
	return ans;
}

int ans[1005];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 1005; ++i) ans[i] = inf;
	for(int i = 0; i < 10; ++i) {
		vector<int> a, b;
		for(int j = 0; j < n; ++j) {
			if(j & (1 << i)) b.push_back(j);
			else a.push_back(j);
		}
		if(!a.empty() && !b.empty()) {
			vector<int> one = query(a);
			vector<int> two = query(b);
			debug() << imie(one) << imie(two);
			for(int j = 0; j < n; ++j) {
				if(j & (1 << i)) ans[j] = min(ans[j], one[j]);
				else ans[j] = min(ans[j], two[j]);
			}
		}
	}
	puts("-1");
	for(int i = 0; i < n; ++i) {
		assert(ans[i] != inf);
		printf("%d ", ans[i]);
	}
	puts("");
}