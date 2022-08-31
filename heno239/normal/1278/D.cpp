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
const ll INF = (1e+18)+7;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

using mat = pair<LP, LP>;
void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}
void debug(mat &m) {
	cout << m.first.first << " " << m.first.second << endl;
	cout << m.second.first << " " << m.second.second << endl;
}

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};
struct SegT {
private:
	int sz; vector<P> node;
	const P init_c = { mod,mod };
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	P f(P a, P b) {
		return min(a, b);
	}
	void update(int k, int a,int b) {
		k += sz - 1;
		node[k] = { a,b };
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

struct SegT2 {
private:
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	SegT2(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
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

void solve() {
	int n; cin >> n;
	BIT b(2 * n);
	vector<int> id(2 * n);
	vector<int> isend(2 * n);
	vector<P> v;
	rep(i, n) {
		int l, r; cin >> l >> r;
		l--; r--;
		v.push_back({ l,r });
		id[l] = id[r] = i;
		isend[r] = true;
	}
	int c = 0;
	SegT st(2*n);
	SegT2 st2(2 * n);
	rep(i, n) {
		int l = v[i].first, r = v[i].second;
		st.update(r, l,i);
		st2.update(l, r);
	}
	vector<int> le(2 * n);
	rep(i, 2*n) {
		if (isend[i]) {
			int t = id[i];
			int l = v[t].first;
			le[i] = l;
			P p = st.query(l, i+1);
			//cout << p.second << endl;
			le[i] = le[v[p.second].second];
			int ri = st2.query(le[i], i);
			if (i<2*n-1&&ri <= i) {
				cout << "NO" << endl; return;
			}
		}
	}
	ll sum = 0;
	rep(i, 2 * n) {
		if (!isend[i]) {
			b.add(i, 1);
		}
		else {
			int x = id[i];
			int l = v[x].first, r = i;
			b.add(l, -1);
			sum += b.sum(l, r);
		}
	}
	//cout << sum << endl;
	if (sum == n - 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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