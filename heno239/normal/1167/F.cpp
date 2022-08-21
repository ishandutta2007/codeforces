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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

struct SegT {
private:
	int sz; vector<ll> node;
	const ll init_c = 0;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	SegT(vector<ll> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1)node[i] = f(node[2 * i + 1], node[2 * i + 2]);
	}
	ll f(ll a, ll b) {
		ll ret = a + b; if (ret >= mod)ret -= mod;
		return ret;
	}
	void update(int k, ll a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
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

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	vector<ll> sle(n), sri(n);
	rep(i, n) {
		sle[i] = a[i] * (i + 1) % mod;
		sri[i] = a[i] * (n - i) % mod;
	}
	SegT le(sle),ri(sri);
	ll ans = 0;
	vector<P> v;
	rep(i, n)v.push_back({ a[i],i });
	sort(v.begin(), v.end());
	rep(i, n) {
		//cout << ans << endl;
		int id = v[i].second;
		ll c = v[i].first;
		ll len1 = id + 1, len2 = n - id;
		(ans += len1 * len2%mod*c%mod)%=mod;
		ll sum1 = le.query(0, id);
		ll sum2 = ri.query(id + 1, n);
		(ans += len1 * sum2 + len2 * sum1) %= mod;
		le.update(id, 0); ri.update(id, 0);
		
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}