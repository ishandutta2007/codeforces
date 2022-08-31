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
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

int ans[2000];
int c[2000];
int root;
vector<int> G[2000];

bool valid = true;
int tmp;
vector<P> dfs(int id) {
	vector<P> res;
	rep(j, G[id].size()) {
		int to = G[id][j];
		vector<P> nex = dfs(to);
		rep(i, nex.size())res.push_back(nex[i]);
	}
	tmp++;
	if (c[id] > res.size()) {
		valid = false;
	}
	else {
		int len = res.size();
		sort(res.begin(), res.end());
		res.push_back({ tmp,0 });
		for (int i = 0; i < len - c[id];i++) {
			res[len - i].second = res[len - i - 1].second;
		}
		res[c[id]].second = id;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	rep(i, n) {
		int p; cin >> p >> c[i]; p--;
		if (p < 0)root = i;
		else G[p].push_back(i);
	}
	vector<P> res=dfs(root);
	if (!valid) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		vector<int> ans(n + 1);
		rep(i, n) {
			ans[res[i].second] = res[i].first;
		}
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}