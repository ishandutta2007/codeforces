#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())



int n;
ll a[150005];
vector<int>edge[150005];

bool rem[200005]={};
int sub[200005]={};
int make(int v,int u)
{
	int cnt=1;
	for(int i=0;i<edge[v].size();i++)
	{
		int v2=edge[v][i];
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
		int v2=edge[v][i];
		if(rem[v2] || v2==u) continue;
		res=min(res,search(v2,v,siz));
		m=max(m,sub[v2]);
		s+=sub[v2];
	}
	m=max(m,siz-s);
	res=min(res,mp(m,v));
	return res;
}
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
		//assert(!empty());
		if(empty()) return -5e18;
		Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
		return l.k * x + l.m;
	}
};
LineContainer cur;
ll ans;

void eval_dfs(int v,int u,ll curr,ll sum,ll d){
	ans = max(ans,cur.query(d)+curr);
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u || rem[to]) continue;
		eval_dfs(to,v,curr+sum+a[to],sum+a[to],d+1);
	}
}
void make_dfs(int v,int u,int w,ll c,ll sl){
    //cout << sl+a[v] << " " << c+1LL*w*a[v] << endl;
	cur.add(sl+a[v], c+1LL*w*a[v]);
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(to == u || rem[to]) continue;
		make_dfs(to,v,w+1,c+1LL*w*a[v], sl+a[v]);
	}
}

void sol(int v)
{
	make(v,-1);
	int cent=search(v,-1,sub[v]).sc; //cout << cent << endl;
	rem[cent]=true;
	cur.clear();
	cur.add(a[v],a[v]);
	for(int i=0;i<edge[cent].size();i++)
	{
		if(rem[edge[cent][i]]) continue;
		//evaluate
		eval_dfs(edge[cent][i],cent,a[edge[cent][i]],a[edge[cent][i]],1);
		//make
		make_dfs(edge[cent][i],cent,2,a[cent],a[cent]);
	}
	
	//same
	cur.clear();
	int sz = edge[cent].size();
	for(int i=sz-1;i>=0;i--)
	{
		if(rem[edge[cent][i]]) continue;
		//evaluate
		eval_dfs(edge[cent][i],cent,a[edge[cent][i]],a[edge[cent][i]],1);
		//make
		make_dfs(edge[cent][i],cent,2,a[cent],a[cent]);
	}
	ans = max(ans,cur.query(0));
	for(int i=0;i<edge[cent].size();i++) if(!rem[edge[cent][i]]) sol(edge[cent][i]);
	rem[cent]=false;
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	repn(i,n) scanf("%lld",&a[i]);
	
	sol(1);
	
	cout << ans << endl;
}