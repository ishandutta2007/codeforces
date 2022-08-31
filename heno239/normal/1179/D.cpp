#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct CHT {
	vector<LP> v;
	bool check(LP a, LP b, LP c) {
		return (b.first - a.first)*(c.second - b.second) >= (b.second - a.second)*(c.first - b.first);
	}
	void add(LP p) {
		while (v.size() >= 2 && check(p, v[v.size() - 1], v[v.size()-2]))v.pop_back();
		v.push_back(p);
	}
	ll f(LP a, ll x) {
		return a.first*x + a.second;
	}
	ll query(ll x) {
		if (v.empty())return INF;
		while (v.size() >= 2 && f(v[v.size() - 1], x) >= f(v[v.size() - 2], x))v.pop_back();
		return f(v.back(), x);
	}
};

const int mn = 1 << 19;
int n;
vector<int> G[mn];

int cur = 0;
int trans[mn];
int ri[mn];
vector<ll> c;

void dfs(int id, int fr) {
	trans[id] = cur; cur++;
	c[id] = 1;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs(to, id);
		c[id] += c[to];
	}
	ri[trans[id]] = cur;
}

vector<ll> ori;
void dfs2(int id, int fr,ll s) {
	if (fr >= 0) {
		s -= c[fr]*c[fr];
		s += (c[fr] - c[id])*(c[fr] - c[id]);
	}
	s += c[id]*c[id];
	ori[trans[id]] = s;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs2(to, id, s);
	}
}

ll mi = INF;

LP dfs3(int id, int fr) {
	if (G[id].size() == 1 && fr >= 0) {
		return { 1,1 };
	}
	ll ret=INF;
	vector<LP> v;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		LP p = dfs3(to, id);
		v.push_back(p);
		ret = min(ret, p.second + (c[id] - c[to])*(c[id] - c[to]));
	}
	sort(v.begin(), v.end());
	CHT cht;
	rep(i, v.size()) {
		ll z = cht.query(-2 * (n - v[i].first));
		z += v[i].second + (n - v[i].first)*(n - v[i].first);
		mi = min(mi, z);
		cht.add({ v[i].first,v[i].first*v[i].first + v[i].second });
	}
	return { c[id],ret };
}

void solve() {
	int root;
	cin >> n; c.resize(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	rep(i, n)if (G[i].size() == 1)root = i;
	dfs(root,-1);
	ori.resize(n);
	dfs2(root, -1,0);
	//rep(i, n)cout << "/ " << c[i] << endl;
	//rep(i, n)cout << "/ " << ori[i] << endl;
	rep(i, n)if (G[i].size() != 1)ori[trans[i]] = INF;
	rep(i, n)mi = min(mi, ori[i]);
	dfs3(root, -1);
	//cout << mi << endl;
	ll ans = (ll)n*n - mi; ans = ans / 2 + (ll)n*(n - 1) / 2;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}