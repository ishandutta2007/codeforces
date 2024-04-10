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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	void init(vector<int> v) {
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
	int f(int a, int b) {
		return max(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

int n;
vector<int> p;
SegT st;
int trans[1 << 18];

ll ans = 0;
void d_and_c(int l, int r) {
	if (l > r)return;
	int ma = st.query(l, r+1);
	int mid = trans[ma];
	d_and_c(l, mid - 1);
	d_and_c(mid + 1, r);
	int lenl = mid - l;
	int lenr = r - mid;
	if (lenl < lenr) {
		for (int i = l; i <= mid - 1; i++) {
			int loc = trans[ma-p[i]];
			if (mid + 1 <= loc && loc <= r)ans++;
		}
	}
	else {
		for (int i = mid + 1; i <= r; i++) {
			int loc = trans[ma - p[i]];
			if (l <= loc && loc <= mid-1)ans++;
		}
	}
}
void solve() {
	cin >> n; p.resize(n);
	rep(i, n) {
		cin >> p[i];
		trans[p[i]] = i;
	}
	st.init(p);
	d_and_c(0, n - 1);
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