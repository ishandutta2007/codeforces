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
#include<cstdlib>
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
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int n;
ll x[1 << 17];
vector<int> G[1 << 17];

map<ll, int> mp[100000];
ll ans = 0;
void dfs(int id, int fr) {
	ll sum = 0;
	mp[id][x[id]] = 1; sum += x[id];
	if (fr >= 0) {
		for (auto itr = mp[fr].begin(); itr != mp[fr].end(); itr++) {
			ll g = gcd(x[id], (*itr).first);
			mp[id][g] += (*itr).second;
			sum += g * (*itr).second%mod;
		}
	}
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs(to, id);
	}
	ans += sum; ans %= mod;
}
void solve() {
	cin >> n;
	rep(i, n) {
		cin >> x[i];
	}
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}