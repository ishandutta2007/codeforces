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
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = -INF;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	ll f(ll a, ll b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int k, ll x) {
		ll z = query(k, k + 1);
		add(x - z, k, k + 1);
	}
};
ll ori[1 << 17], a[1 << 17];
int l[300], r[300];
int n,m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		cin >> ori[i];
	}
	rep(i, m) {
		cin >> l[i] >> r[i]; l[i]--; r[i]--;
	}
	ll ans = -1; int chk = -1;
	rep(i, n) {
		rep(j, n) {
			a[j] = ori[j];
		}
		ll ma = ori[i];
		rep(j, m) {
			if (l[j] <= i && i <= r[j])continue;
			Rep1(k, l[j], r[j])a[k]--;
		}
		ll mi = INF;
		rep(j, n) {
			mi = min(mi, a[j]);
		}
		if (ans < ma - mi) {
			ans = ma - mi; chk = i;
		}
	}
	cout << ans << endl;
	int cnt = 0; vector<int> q;
	rep(j, m) {
		if (l[j] <= chk && chk <= r[j])continue;
		cnt++; q.push_back(j+1);
	}
	cout << cnt << endl;
	rep(j, cnt) {
		if (j > 0)cout << " ";
		cout << q[j];
	}
	cout << endl;
	//stop
	return 0;
}