#pragma GCC optimize ("Ofast")
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

typedef long long ll;

const int nax = 2e5 + 5;
vector<int> w[nax];
int vis[nax][2];
//~ pair<int,int> from[nax][2];
bool is_draw;
vector<int> stos;

void rec(int a, int parity) {
	assert(!vis[a][parity]);
	stos.push_back(a);
	vis[a][parity] = 1;
	if(w[a].empty()) {
		if(parity) {
			puts("Win");
			for(int x : stos) printf("%d ", x);
			puts("");
			exit(0);
		}
	}
	for(int b : w[a]) {
		if(vis[b][!parity] == 1) is_draw = true;
		if(!vis[b][!parity]) {
			rec(b, !parity);
		}
	}
	vis[a][parity] = 2;
	stos.pop_back();
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int cnt;
		scanf("%d", &cnt);
		while(cnt--) {
			int j;
			scanf("%d", &j);
			w[i].push_back(j);
		}
	}
	int start;
	scanf("%d", &start);
	rec(start, 0);
	if(is_draw) puts("Draw");
	else puts("Lose");
}