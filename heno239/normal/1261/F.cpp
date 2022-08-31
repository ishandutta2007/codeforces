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
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

vector<LP> resol(ll l, ll r) {
	vector<LP> res;
	rep(i, 60) {
		ll k = (ll)1 << i;
		if (l&k) {
			ll s = l + k;
			if (s - 1 <= r) {
				res.push_back({ l,i });
				l = s;
			}
			else {
				break;
			}
		}
	}
	if (l > r)return res;
	per(i, 60) {
		ll k = (ll)1 << i;
		ll s = l + k;
		if (s - 1 <= r) {
			res.push_back({ l,i });
			l = s;
		}
		if (l > r)break;
	}
	return res;
}

ll calc(ll x) {
	x %= mod;
	ll res = x * (x + 1) / 2;
	return res % mod;
}
ll calc(ll x, ll y) {
	ll res = calc(y) - calc(x - 1);
	if (res < 0)res += mod;
	return res;
}

bool comp(LP a, LP b) {
	if (a.second != b.second)return a.second > b.second;
	return a.first < b.first;
}
void solve() {
	int n, m; cin >> n;
	vector<vector<LP>> ra(n);
	vector<LP> pa(n);
	rep(i, n) {
		ll l, r; cin >> l >> r;
		ra[i] = resol(l, r);
		sort(ra[i].begin(), ra[i].end(), comp);
		pa[i] = { l,r };
	}

	cin >> m;
	vector<vector<LP>> rb(m);
	vector<LP> pb(m);
	rep(i, m) {
		ll l, r; cin >> l >> r;
		rb[i] = resol(l, r);
		sort(rb[i].begin(), rb[i].end(), comp);
		pb[i] = { l,r };
	}
	vector<LP> allsegs;
	rep(i, n) {
		rep(j, m) {
			vector<pair<ll, short>> segs;
			
			rep(k, ra[i].size()) {
				int ma = ra[i][k].second;
				ll z = (ll)1 << ma;
				ll za = z * (ra[i][k].first / z);
				ll zb = z * (pb[j].first / z);
				ll zz = za ^ zb;
				segs.push_back({ zz,ma });
				zb = z * (pb[j].second / z);
				zz = za ^ zb;
				segs.push_back({ zz,ma });
			}
			rep(k, rb[j].size()) {
				int ma = rb[j][k].second;
				ll z = (ll)1 << ma;
				ll za = z * (rb[j][k].first / z);
				ll zb = z * (pa[i].first / z);
				ll zz = za ^ zb;
				segs.push_back({ zz,ma });
				zb = z * (pa[i].second / z);
				zz = za ^ zb;
				segs.push_back({ zz,ma });
			}
			int le = 0;
			rep(k, ra[i].size()) {
				int ma = ra[i][k].second;
				while (le<rb[j].size() && rb[j][le].second>ma) {
					le++;
				}
				ll z = (ll)1 << ma;
				ll za = z * (ra[i][k].first / z);
				if (le < rb[j].size() && rb[j][le].second == ma) {
					ll zb = z * (rb[j][le].first / z);
					ll zz = za ^ zb;
					segs.push_back({zz, ma});
				}
				if (le + 1 < rb[j].size() && rb[j][le + 1].second == ma) {
					ll zb = z * (rb[j][le + 1].first / z);
					ll zz = za ^ zb;
					segs.push_back({ zz,ma });
				}
			}

			sort(segs.begin(), segs.end());
			ll l = 0, r = 0;

			ll ans = 0;
			rep(g, segs.size()) {
				ll k = (ll)1 << segs[g].second;
				ll le = segs[g].first;
				ll ri = le + k - 1;
				if (r >= le) {
					r = max(r, ri);
				}
				else {
					allsegs.push_back({ l,r });
					l = le, r = ri;
				}
			}
			allsegs.push_back({ l,r });
		}
	}
	sort(allsegs.begin(), allsegs.end());
	ll l = 0, r = 0;

	ll ans = 0;
	rep(i, allsegs.size()) {
		ll le = allsegs[i].first;
		ll ri = allsegs[i].second;
		if (r >= le) {
			r = max(r, ri);
		}
		else {
			ans += calc(l, r);
			ans %= mod;
			l = le, r = ri;
		}
	}
	ans += calc(l, r);
	ans %= mod;
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