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
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

struct edge {
	int to, cost;
};
vector<edge> G[1 << 19];

int n, k;
LP dfs(int id, int fr) {
	LP res;
	vector<LP> v;
	rep(j, G[id].size()) {
		int to = G[id][j].to;
		if (to == fr)continue;
		LP nex = dfs(to, id);
		nex.second += G[id][j].cost;
		v.push_back(nex);
	}
	ll sum = 0;
	vector<ll> difs;
	rep(j, v.size()) {
		if (v[j].first >= v[j].second) {
			sum += v[j].first;
		}
		else {
			sum += v[j].second;
			difs.push_back(v[j].second - v[j].first);
		}
	}
	sort(difs.begin(), difs.end());
	ll csum = sum;
	//0-remain
	if (difs.size() > k) {
		rep(i, difs.size() - k) {
			csum -= difs[i];
		}
		res.first = csum;
	}
	else {
		res.first = csum;
	}
	csum = sum;
	//1-remain
	if (difs.size() > k - 1) {
		rep(i, difs.size() - (k - 1)) {
			csum -= difs[i];
		}
		res.second = csum;
	}
	else {
		res.second = csum;
	}
	res.first = max(res.first, res.second);
	return res;
}
void solve() {
	cin >> n >> k;
	rep(i, n) {
		G[i].clear();
	}
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--; int w; cin >> w;
		G[a].push_back({ b,w }); G[b].push_back({ a,w });
	}
	LP z = dfs(0, -1);
	cout << z.first << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	int q; cin >> q;
	rep(i, q) {
		solve();
	}

	//cout << "finish" << endl;
	//stop
		return 0;
}