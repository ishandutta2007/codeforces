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

const int nax = 1e5 + 5;
int h[nax];
ll should[nax], answer[nax];
bool vis[nax];
vector<pair<int,int>> w[nax];
ll EVEN = 0, ODD = 0;
pair<pair<int,int>,int> spec;
vector<pair<int,int>> children[nax];

void dfs_one(int a) {
	if(h[a]%2) ODD += should[a];
	else EVEN += should[a];
	assert(!vis[a]);
	vis[a] = true;
	for(pair<int,int> edge : w[a]) {
		int b = edge.first;
		if(!vis[b]) {
			children[a].push_back(edge);
			h[b] = h[a] + 1;
			dfs_one(b);
		}
		else if((h[a] - h[b]) % 2 == 0) {
			spec = make_pair(make_pair(a, b), edge.second);
		}
	}
}

void dfs_two(int a) {
	for(pair<int,int> edge : children[a]) {
		int b = edge.first;
		dfs_two(b);
		answer[edge.second] = should[b];
		should[a] -= should[b];
		should[b] = 0;
	}
}

void NO() {
	puts("NO");
	exit(0);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &should[i]);
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back({b, i});
		w[b].push_back({a, i});
	}
	dfs_one(1);
	ll need = EVEN - ODD;
	if(need) {
		if(need % 2 != 0) NO();
		need /= 2;
		debug() << imie(need) imie(spec);
		int id = spec.second;
		if(id == 0) NO();
		if(h[spec.first.first] % 2 == 1) need *= -1;
		answer[id] = need;
		should[spec.first.first] -= need;
		should[spec.first.second] -= need;
	}
	dfs_two(1);
	assert(should[1] == 0);
	puts("YES");
	for(int i = 1; i <= m; ++i)
		printf("%lld\n", answer[i]);
}