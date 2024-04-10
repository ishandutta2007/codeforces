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

struct SegT {
private:
	int sz; vector<ll> node;
	const ll init_c = -INF;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	SegT(vector<ll>v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	ll f(ll a, ll b) {
		return max(a, b);
	}

	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

ll ans[1 << 20];
vector<ll> v[1 << 20];
void solve(){
	int n, w;
	cin >> n >> w;
	rep(i, n) {
		int l; cin >> l;
		v[i].resize(l);
		rep(j, l) {
			cin >> v[i][j];
		}
		if (w >= 2 * l) {
			ll ma = -INF;
			rep(j, l) {
				ma = max(ma, v[i][j]);
				ans[j] += max(ma,(ll)0);
				ans[j + 1] -= max(ma,(ll)0);
			}
			ans[l] += max(ma, (ll)0);
			ans[w - l] -= max(ma, (ll)0);
			ma = -INF;
			rep(j, l) {
				ma = max(ma, v[i][l - 1 - j]);
				ans[w - 1 - j] += max(ma, (ll)0);
				ans[w - j] -= max(ma, (ll)0);
			}
		}
		else {
			SegT st(v[i]);
			rep(j, w) {
				int le, ri;
				le = max(l - (w - j), 0);
				ri = min(j, l - 1);
				ll z = st.query(le, ri + 1);
				if (j < w - l || j >= l) {
					z = max(z, (ll)0);
				}
				ans[j] += z;
				ans[j + 1] -= z;
			}
		}
	}
	rep(i, w) {
		ans[i + 1] += ans[i];
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}