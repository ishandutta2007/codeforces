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

struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = 0;
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
};

int n;
vector<pair<P, P>> ori;
bool check() {
	vector<P> v(n);
	vector<int> x;
	vector<pair<int, P>> al;
	rep(i, n) {
		int a = ori[i].first.first;
		int b = ori[i].first.second;
		int c = ori[i].second.first;
		int d = ori[i].second.second;
		v[i] = { c,d };
		x.push_back(c);
		x.push_back(d);
		al.push_back({ a,{ 0,i } });
		al.push_back({ b,{ 1,i } });
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	map<int, int> mpx;
	rep(i, x.size())mpx[x[i]] = i;
	rep(i, n) {
		v[i].first = mpx[v[i].first];
		v[i].second = mpx[v[i].second];
	}
	sort(al.begin(), al.end());
	int tmp = 0;
	SegT st(x.size());
	rep(i, al.size()) {
		int t = al[i].second.first;
		int id = al[i].second.second;
		int l = v[id].first, r = v[id].second;
		if (t == 0) {
			tmp++;
			st.add(1,l, r + 1);
		}
		else {
			st.add(-1,l, r + 1); tmp--;
			ll s = st.query(l, r + 1);
			if (tmp!=s) {
				return false;
			}
		}
	}
	return true;
}
void solve() {

	cin >> n;
	rep(i, n) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		ori.push_back({ {a,b},{c,d} });
	}
	
	bool b = check();
	if (!b) {
		cout << "NO" << endl; return;
	}
	rep(i, n) {
		swap(ori[i].first, ori[i].second);
	}
	b = check();
	if (!b) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
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