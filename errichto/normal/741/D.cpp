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

const int N = 5e5 + 5;
const int inf = 1e9 + 5;
int mask[N], par[N], subtree[N], h[N];
vector<int> children[N];
int deepest[1 << 22], ans[N];

void maxi(int & a, int b) { a = max(a, b); }

int G;

void twenty(int a) {
	int be = -inf;
	maxi(be, deepest[mask[a]]);
	for(int i = 0; i < 22; ++i)
		maxi(be, deepest[mask[a] ^ (1 << i)]);
	debug() << "twenty" << imie(a) << imie(be);
	maxi(G, be + h[a]);
}

void one(int a) {
	twenty(a);
	for(int b : children[a]) one(b);
}

void two(int a) {
	maxi(deepest[mask[a]], h[a]);
	for(int b : children[a]) two(b);
}
void three(int a) {
	deepest[mask[a]] = -inf;
	for(int b : children[a]) three(b);
}

void dfs(int a, bool shouldClear) {
	//debug() << imie(a) << imie(shouldClear);
	pair<int,int> pp = {-1, -1};
	for(int b : children[a])
		pp = max(pp, {subtree[b], b});
	int big = pp.second;
	debug() << imie(a) << imie(big);
	for(int b : children[a]) if(b != big)
		dfs(b, true);
	if(big != -1)
		dfs(big, false);
	maxi(deepest[mask[a]], h[a]);
	G = -inf;
	twenty(a);
	debug() << "dfs " << imie(a);
	for(int b : children[a]) if(b != big) {
		one(b);
		two(b);
	}
	ans[a] = G - 2 * h[a];
	if(shouldClear) three(a);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		char let;
		scanf("%d %c", &par[i], &let);
		h[i] = h[par[i]] + 1;
		children[par[i]].push_back(i);
		//debug() << let - 'a';
		mask[i] = mask[par[i]] ^ (1 << (let - 'a'));
	}
	//for(int i = 1; i <= n; ++i) debug() << imie(i) << imie(mask[i]);
	for(int i = 0; i < 1 << 22; ++i) deepest[i] = -inf;
	//for(int i = 1; i <= n; ++i) deepest[mask[i]] = -inf;
	for(int i = 1; i <= n; ++i)
		subtree[i] = 1;
	for(int i = n; i >= 2; --i)
		subtree[par[i]] += subtree[i];
	//debug() << "ple";
	dfs(1, false);
	for(int i = n; i >= 2; --i) maxi(ans[par[i]], ans[i]);
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);;
}