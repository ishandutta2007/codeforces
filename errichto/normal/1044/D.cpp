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

map<int,int> g;
#define list list_compile
vector<int> list[500123];
//~ map<int,vector<int>> list;
//~ map<int,int> g_offset;
map<int,int> mine;
int nxt;

int main() {
	int q;
	scanf("%d", &q);
	int last = 0;
	while(q--) {
		int type;
		scanf("%d", &type);
		debug() << imie(mine) imie(g) imie(list[0]) imie(list[2]) imie(list[4]);
		if(type == 1) {
			int L, R, x;
			scanf("%d%d%d", &L, &R, &x);
			L ^= last;
			R ^= last;
			x ^= last;
			if(L > R) {
				swap(L, R);
			}
			debug() << imie(type) imie(L) imie(R) imie(x);
			--L;
			auto it_L = g.find(L);
			auto it_R = g.find(R);
			if(it_L == g.end()) {
				g[L] = ++nxt;
				list[nxt].push_back(L);
				it_L = g.find(L);
			}
			if(it_R == g.end()) {
				g[R] = ++nxt;
				list[nxt].push_back(R);
				it_R = g.find(R);
			}
			if(it_L->second == it_R->second) {
				debug() << "ignore";
				continue;
			}
			if(list[it_L->second].size() > list[it_R->second].size()) {
				swap(L, R);
				swap(it_L, it_R);
			}
			int L_g = it_L->second;
			int R_g = it_R->second;
			debug() << imie(x);
			x ^= mine[R] ^ mine[L];
			debug() << imie(x);
			for(int a : list[L_g]) {
				list[R_g].push_back(a);
				g[a] = R_g;
				mine[a] ^= x;
			}
			list[L_g].clear();
		}
		else {
			int L, R;
			scanf("%d%d", &L, &R);
			L ^= last;
			R ^= last;
			if(L > R) {
				swap(L, R);
			}
			debug() << imie(type) imie(L) imie(R);
			--L;
			auto it_L = g.find(L);
			auto it_R = g.find(R);
			if(it_L == g.end() || it_R == g.end() || it_L->second != it_R->second) {
				puts("-1");
				last = 1;
				continue;
			}
			int answer = mine[L] ^ mine[R];
			//~ auto it = g.find(-1);
			
			printf("%d\n", answer);
			last = answer;
		}
	}
}