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
	int n; vector<ll> node, lazy;
	const ll init_c = INF;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	SegT(vector<ll> v) {
		int sz = v.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	ll f(ll a, ll b) {
		return min(a, b);
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
	int find_rightzero() {
		int k = 0, l = 0, r = n;
		while (k < n - 1) {
			eval(k, l, r);
			int mid = (l + r) / 2;
			eval(2 * k + 2, mid, r);
			if (node[2 * k + 2] == 0) {
				k = 2 * k + 2; l = mid;
			}
			else {
				k = 2 * k + 1; r = mid;
			}
		}
		return k - (n - 1);
	}
};

int ans[1 << 18];
void solve(){
	int n; cin >> n;
	vector<ll> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	SegT st(s);
	rep1(i, n) {
		int id = st.find_rightzero();
		ans[id] = i;
		st.add(-i, id + 1, id + n);
		st.add(INF, id, id + 1);
	}
	rep(i, n) {
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
//	stop
	return 0;
}