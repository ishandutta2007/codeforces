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
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = f(node[k],a);
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

int cnt[301];
void solve() {
	int n, t; cin >> n >> t;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i]; cnt[a[i]]++;
	}
	SegT st(301);
	rep(i, 301)st.update(i, 0);
	if (t < 602) {
		rep(i, t) {
			rep(j, n) {
				int z = st.query(0, a[j] + 1);
				st.update(a[j], z + 1);
			}
		}
		int ans = st.query(0, 301);
		cout << ans << endl; return;
	}
	rep(i, 301) {
		rep(j, n) {
			int z = st.query(0, a[j] + 1);
			st.update(a[j], z + 1);
		}
	}
	int tt = t - 602;
	rep(i, 301) {
		int num = st.query(i, i + 1);
		num += tt * cnt[i];
		st.update(i, num);
	}
	rep(i, 301) {
		rep(j, n) {
			int z = st.query(0, a[j] + 1);
			st.update(a[j], z + 1);
		}
	}
	int ans = st.query(0, 301);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}