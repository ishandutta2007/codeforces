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

const int nax = 2e5 + 5;
const int K = 19;
const int inf = 1e9 + 5;
int tresh[nax];
pair<int,int> par[nax][K];
vector<int> children[nax];
int subtract[nax], ans[nax];

//int so_far;
void dfs1(int a) {
	{
		int i = a;
		for(int j = 1; j < K; ++j) {
			pair<int,int> mid = par[i][j-1];
			par[i][j].first = par[mid.first][j-1].first;
			par[i][j].second = min(inf, mid.second + par[mid.first][j-1].second);
		}
		int x = i;
		for(int j = K - 1; j >= 0; --j)
			if(par[x][j].second <= tresh[i]) {
				tresh[i] -= par[x][j].second;
				x = par[x][j].first;
			}
		debug() << imie(i) << imie(x);
		++subtract[par[x][0].first];
	}
	//ans[a] = 1 - subtract[a];
	for(int b : children[a]) {
		dfs1(b);
		//ans[a] += ans[b];
	}
	// ans[a] = so_far += 1 - subtract[a];
}
void dfs2(int a) {
	ans[a] = 1 - subtract[a];
	for(int b : children[a]) {
		dfs2(b);
		ans[a] += ans[b];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &tresh[i]);
	for(int j = 0; j < K; ++j)
		par[1][j].second = inf;
	for(int i = 2; i <= n; ++i) {
		scanf("%d%d", &par[i][0].first, &par[i][0].second);
		
		children[par[i][0].first].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i] - 1);
	puts("");
}