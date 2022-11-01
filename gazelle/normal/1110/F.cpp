#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

struct StarrySkyTree {	// segment add, segment max
	// if min, rewrite lines commented // for min

private:
	ll n;		// the size of the tree
	vector<ll> node, lazy;
	void eval(ll k, ll l, ll r) {	// lazy evaluation
		if(lazy[k] != 0) {
			node[k] += lazy[k];
			if(r - l > 1) {
				lazy[2*k+1] += lazy[k];
				lazy[2*k+2] += lazy[k];
			}
			lazy[k] = 0;
		}
	}

public:
	StarrySkyTree(vector<ll> v) {	// v: the array used for initialization
		ll sz = (ll)v.size();
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1);
		lazy.resize(2*n-1, 0);
		for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
		for(ll i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);	// for min
	}

	StarrySkyTree(ll _sz) {	// for empty tree
		ll sz = (ll)_sz;
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1);
		lazy.resize(2*n-1, 0);
		for(ll i=0; i<sz; i++) node[i+n-1] = 0;
		for(ll i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);	// for min
	}

	void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {	// add x in [a, b)
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			lazy[k] += x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2*k+1, l, (l+r)/2);
			add(a, b, x, 2*k+2, (l+r)/2, r);
			node[k] = min(node[2*k+1], node[2*k+2]);	// for min
		}
	}

	ll find(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return INF*INF;	// for min
		if(a <= l && r <= b) return node[k];
		ll vl = find(a, b, 2*k+1, l, (l+r)/2);
		ll vr = find(a, b, 2*k+2, (l+r)/2, r);
		return min(vl,vr);	// for min
	}
};

vector<vector<pll>> g;
vector<pll> segle;
vector<vector<pair<pll, ll>>> que;
vector<ll> cost;
vector<ll> ans;
ll n, q;

pll dfs1(ll pos, ll par) {
	pll ret = pll(INF, -INF);
	if(g[pos].size() == 1) {
		ret.first = pos;
		ret.second = pos;
	}
	REP(i, g[pos].size()) {
		if(g[pos][i].first == par) continue;
		pll tmp = dfs1(g[pos][i].first, pos);
		ret.first = min(ret.first, tmp.first);
		ret.second = max(ret.second, tmp.second);
	}
	segle[pos] = ret;
	return ret;
}

vector<ll> vv(505050, INF * INF);
StarrySkyTree sst(vv);

void dfs2(ll pos, ll par, ll co) {
	if(g[pos].size() == 1) sst.add(pos, pos + 1, - INF * INF + co);
	REP(i, g[pos].size()) {
		if(g[pos][i].first == par) continue;
		dfs2(g[pos][i].first, pos, co + g[pos][i].second);
	}
	return;
}

void dfs3(ll pos, ll par, ll c) {
	sst.add(0, n, c);
	sst.add(segle[pos].first, segle[pos].second + 1, - 2 * c);
	REP(i, que[pos].size()) {
		ans[que[pos][i].second] = sst.find(que[pos][i].first.first, que[pos][i].first.second + 1);
	}
	REP(i, g[pos].size()) {
		if(g[pos][i].first == par) continue;
		dfs3(g[pos][i].first, pos, g[pos][i].second);
	}
	sst.add(0, n, -c);
	sst.add(segle[pos].first, segle[pos].second + 1, 2 * c);
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	g.resize(n);
	segle.resize(n);
	REP(i, n - 1) {
		ll p, w;
		cin >> p >> w;
		p--;
		g[i + 1].pb(pll(p, w));
		g[p].pb(pll(i + 1, w));
	}
	REP(i, n) sort(ALL(g[i]));
	ans.resize(q);
	que.resize(n);
	REP(i, q) {
		ll v, l, r;
		cin >> v >> l >> r;
		v--; l--; r--;
		que[v].pb(make_pair(pll(l, r), i));
	}
	dfs1(0, -1);
	dfs2(0, -1, 0);
	dfs3(0, -1, 0);
	REP(i, q) cout << ans[i] << endl;
	return 0;
}

/* --------------------------------------- */