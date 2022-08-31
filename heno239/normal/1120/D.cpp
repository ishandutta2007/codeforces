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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int n;
vector<ll> c;
vector<int> G[1 << 18];

vector<int> par[1 << 18][2];

LP dfs(int id, int fr) {
	if (fr >= 0 && G[id].size() == 1) {
		return { c[id],0 };
	}
	vector<LP> v;
	vector<int> ids;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		ids.push_back(to);
		v.push_back(dfs(to, id));
	}
	LP ret = { INF,INF };
	ll sum = 0;
	rep(i, v.size()) {
		sum += v[i].first;
	}
	ll mi = sum; ll mi2 = INF;
	rep(i, v.size()) {
		ll s = sum - v[i].first + v[i].second;
		mi2 = min(mi2, s);
		mi = min(mi, s + c[id]);
	}
	if (sum == mi) {
		par[id][0].push_back(-1);
	}
	rep(i, v.size()) {
		ll s = sum - v[i].first + v[i].second;
		if (mi == s + c[id]) {
			par[id][0].push_back(i);
		}
		if (mi2 == s) {
			par[id][1].push_back(i);
		}
	}
	return{ mi,mi2 };
}

bool used[1 << 18][2];
vector<int> ansids;
void strans(int id,int id2, int fr) {
	if (used[id][id2])return;
	used[id][id2] = true;
	if (fr >= 0 && G[id].size() == 1 && id2 == 0) {
		ansids.push_back(id); return;
	}
	vector<int> v;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		v.push_back(to);
	}
	bool f = false;
	if (par[id][id2].size() >= 2) {
		rep(j, v.size()) {
			strans(v[j], 0, id);
		}
		rep(j, par[id][id2].size()) {
			int t = par[id][id2][j];
			if (t < 0)continue;
			if (id2 == 0)f = true;
			strans(v[t], 1, id);
		}
	}
	else {
		rep(j, v.size()) {
			if (par[id][id2][0] == j) {
				if (id2 == 0)f = true;
				strans(v[j], 1, id);
			}
			else {
				strans(v[j], 0, id);
			}
		}
	}
	if (f) {
		ansids.push_back(id);
	}
}

void solve() {
	cin >> n;
	c.resize(n);
	rep(i, n) {
		cin >> c[i];
	}
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	LP ans = dfs(0, -1);
	int root = 0; int root2 = 0;
	strans(root, root2, -1);
	sort(ansids.begin(), ansids.end());
	ansids.erase(unique(ansids.begin(), ansids.end()), ansids.end());
	cout << ans.first << " " << ansids.size() << endl;
	rep(i, ansids.size()) {
		if (i > 0)cout << " ";
		cout << ansids[i]+1;
	}
	cout << endl;
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