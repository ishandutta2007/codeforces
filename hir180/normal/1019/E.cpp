#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
bool Q;

struct Line {
	mutable ll k, m, p; // slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

//max

struct LineContainer : multiset<Line> {
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		if (b < 0) a *= -1, b *= -1;
		if (a >= 0) return a / b;
		return -((-a + b - 1) / b);
	}

	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}

	ll query(ll x) { // gives max value
		assert(!empty());
		Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
		return l.k * x + l.m;
	}
};

LineContainer universe;
vector<LineContainer>paths;
// paths - vector of LineContainers
// a, b - LineContainers
// We want to take the pair-wise sum of the two line LineContainers
// and only keep the relevant ones. The sum is Minkowski Sum.

void convexsum(auto &a, auto &b)
{
	auto it1 = a.begin(), it2 = b.begin();
	while (it1 != a.end() && it2 != b.end())
	{
		universe.add((it1->k) + (it2->k), (it1->m) + (it2->m));
		if ((it1->p) < (it2->p)) it1++;
		else it2++;
	}
}

// We are merging all the LineContainers in paths.

void mergeall(int l, int r, auto &paths)
{
	if (l >= r) return;
	int mid = (l + r) / 2;

	mergeall(l, mid, paths);
	mergeall(mid + 1, r, paths);

	convexsum(paths[l], paths[mid + 1]);

	if(paths[l].size() < paths[mid+1].size()) swap(paths[l],paths[mid+1]);

	for (auto it : paths[mid + 1]) paths[l].add(it.k, it.m);
}

int n,m;
vector<pair<int,pair<ll,ll> > >edge[100005];


bool rem[200005]={};
int sub[200005]={},len;
int ind;
P xz[200005];

int make(int v,int u)
{
	int cnt=1;
	for(int i=0;i<edge[v].size();i++)
	{
		int v2=edge[v][i].fi;
		if(rem[v2] || v2==u) continue;
		cnt+=make(v2,v);
	}
	return sub[v]=cnt;
}

P search(int v,int u,int siz)
{
	//size and index
	P res=mp(INF,-1);
	int s=1,m=0;
	for(int i=0;i<edge[v].size();i++)
	{
		int v2=edge[v][i].fi;
		if(rem[v2] || v2==u) continue;
		res=min(res,search(v2,v,siz));
		m=max(m,sub[v2]);
		s+=sub[v2];
	}
	m=max(m,siz-s);
	res=min(res,mp(m,v));
	return res;
}
LineContainer cur;
void make_dfs(int v,int u,ll a,ll b){
	bool is_leaf = true;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i].fi == u || rem[edge[v][i].fi]) continue;
		is_leaf = false;
		make_dfs(edge[v][i].fi,v,a+edge[v][i].sc.fi,b+edge[v][i].sc.sc);
	}
	if(is_leaf) cur.add(a,b);
}
void sol(int v){
	make(v,-1);
	int cent = search(v,-1,sub[v]).sc;
	rem[cent]=true;
	vector<LineContainer>vec;
	for(int i=0;i<edge[cent].size();i++){
		if(rem[edge[cent][i].fi]) continue;
		cur.clear();
		make_dfs(edge[cent][i].fi,cent,edge[cent][i].sc.fi,edge[cent][i].sc.sc);
		vec.pb(cur);
	}
	if(vec.size() >= 2) mergeall(0,vec.size()-1,vec);
	else if(vec.size() == 1){
	    auto x = vec[0].begin();
	    while(x != vec[0].end()) {universe.add(x->k,x->m);x++;}
	}
	for(int i=0;i<edge[cent].size();i++){
		if(rem[edge[cent][i].fi]) continue;
		sol(edge[cent][i].fi);
	}
	rem[cent]=false;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n == 1){
	    rep(i,m) puts("0"); return 0;
	}
	for(int i=0;i<n-1;i++){
		int a,b; ll c,d; scanf("%d%d%lld%lld",&a,&b,&c,&d);
		edge[a].pb(mp(b,mp(c,d)));
		edge[b].pb(mp(a,mp(c,d)));
	}
	//
	sol(1);
	for(int i=0;i<m;i++){
		printf("%lld\n",universe.query(1LL*i));
	}
}