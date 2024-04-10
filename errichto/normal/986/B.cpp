#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;

const int pot = 1024 * 1024;
int tr[2*pot];

int main() {
	int n;
	scanf("%d", &n);
	long long inv = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		x += pot;
		while(x > 1) {
			if(x % 2 == 0) inv += tr[x+1];
			++tr[x];
			x /= 2;
		}
	}
	if(inv % 2 == n % 2) puts("Petr");
	else puts("Um_nik");
	return 0;
	//~ int n = 1000;
	for(int k : {3 * n, 7 * n}) {
		for(int T = 0; T < 50; ++T) {
			vector<int> p(n);
			for(int i = 0; i < n; ++i) p[i] = i;
			for(int rep = 0; rep < k; ++rep) {
				int i = rand() % n;
				int j = rand() % n;
				swap(p[i], p[j]);
			}
			vector<int> inv(n);
			for(int i = 0; i < n; ++i) inv[p[i]] = i;
			vector<bool> vis(n);
			double cnt = 0;
			//~ for(int i = 0; i < n; ++i) if(p[i] != i) {
				//~ for(int j = 0; j < n; ++j) if(p[j] == i) {
					//~ cnt += 1;
					//~ swap(p[i], p[j]);
				//~ }
			//~ }
			//~ for(int i = 0; i < n; ++i)
			for(int i = 0; i < n; ++i) if(!vis[i]) {
				vis[i] = true;
				int j = i;
				int s = 1;
				while(true) {
					j = p[j];
					if(vis[j]) break;
					vis[j] = true;
					++s;
				}
				cnt += log(s);
				//~ cnt += s * s * s / 1000000.;
				//~ if(s <= 2) ++cnt;
				//~ cnt += s * s;
			}
			//~ for(int i = 0; i < n; ++i) cnt += (inv[i] == p[i]);
			printf("%lld ", llround(cnt));
		}
		puts("");
	}
		
	
}