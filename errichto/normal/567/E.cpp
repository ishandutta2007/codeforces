#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;

struct edge {
	int a, b, d;
	edge() {}
	void wczytaj() { scanf("%d%d%d", &a, &b, &d); }
	void swag() { swap(a, b); }
} e[nax];

int n;
vi w[nax];

bool vis[nax];
vi pre[nax];
vi order;
vector<ll> bfs(int start) {
	vector<ll> d(n+1, INF);
	RI(i, n) vis[i] = false;
	d[start] = 0;
	set<pair<ll,int> > s;
	RI(i, n) s.insert(mp(d[i], i));
	while(!s.empty()) {
		int me = (*s.begin()).nd;
		order.pb(me);
		vis[me] = true;
		s.erase(s.begin());
		for(int ed : w[me]) {
			int he = e[ed].b;
			if(vis[he]) continue;
			s.erase(mp(d[he], he));
			ll maybe = d[me] + e[ed].d;
			if(maybe < d[he]) {
				pre[he].clear();
				pre[he].pb(ed);
			}
			else if(maybe == d[he]) pre[he].pb(ed);
			mini(d[he], maybe);
			s.insert(mp(d[he], he));
		}
	}
	return d;
}

vector<ll> d[2];

int cnt[nax];
bool yes[nax];

int main()
{
	int m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	RI(i, m) e[i].wczytaj();
	
	RI(i, m) e[i].swag();
	RI(i, m) w[e[i].a].pb(i);
	d[1] = bfs(t);
	RI(i, n) {
		w[i].clear();
		pre[i].clear();
	}
	order.clear();
	RI(i, m) e[i].swag();
	RI(i, m) w[e[i].a].pb(i);
	d[0] = bfs(s);
	
	cnt[t] = 1;
	int total = 1;
	reverse(order.begin(), order.end());
	for(int a : order) {
		if(cnt[a] == 0) continue;
		if(total == 1 && sz(pre[a]) == 1)
			yes[pre[a][0]] = true;
		for(int b : pre[a]) {
			if(cnt[e[b].a] == 0) ++total;
			++cnt[e[b].a];
		}
		--total;
	}
	ll r = d[0][t];
	RI(i, m) {
		if(yes[i]) {
			puts("YES");
			continue;
		}
		ll maybe = d[0][e[i].a] + e[i].d + d[1][e[i].b];
		if(maybe - (r-1) < e[i].d)
			printf("CAN %lld\n", maybe - (r-1));
		else puts("NO");
	}
	
	return 0;
}