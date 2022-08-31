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
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
using vec = vector<ll>;


using mat = vector<vec>;
struct SegT {
private:
	int sz; vector<mat> node;
	mat init_c;
public:
	SegT(vector<mat> v) {
		init_c = mat(3, vec(3, -INF));
		rep(i, 3)init_c[i][i] = 0;
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
	mat f(mat a, mat b) {
		mat res(3, vec(3, -INF));
		rep(i, 3)rep(j, 3)rep(k,3) {
			res[i][j] = max(res[i][j], b[i][k] + a[k][j]);
		}
		return res;
	}
	void update(int k, mat a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	mat query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			mat vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			mat vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	vector<ll> b(n);
	rep(i, n)cin >> b[i]; 
	

	vector<LP> as;
	rep(i, n) {
		as.push_back({ a[i],i });
	}
	sort(all(as));
	vector<P> bs;
	rep(i, n) {
		bs.push_back({ b[i],i });
	}
	sort(all(bs));
	vector<int> trans(n);
	rep(i, n) {
		trans[bs[i].second] = i;
	}

	auto calc = [&](int i)->mat {
		i++;
		mat res(3, vec(3, -INF));
		res[1][0] = res[2][1] = 0;
		if (i - 3 >= 0) {
			rep1(s, 2) {
				bool valid = true;
				ll sum = 0;
				rep(j, 3) {
					int to = (s + j) % 3;
					if (as[i - 3 + j].second == bs[i - 3 + to].second)valid = false;
					sum += as[i - 3 + j].first * bs[i - 3 + to].first;
				}
				if (valid) {
					res[0][2] = max(res[0][2], sum);
				}
			}
		}
		if (i - 2 >= 0) {
			if (as[i - 2].second != bs[i - 1].second && as[i - 1].second != bs[i - 2].second) {
				res[0][1] = max(res[0][1], as[i - 2].first * bs[i - 1].first + as[i - 1].first * bs[i - 2].first);
			}
		}
		if (i - 1 >= 0) {
			if (as[i - 1].second != bs[i - 1].second) {
				res[0][0] = max(res[0][0], as[i - 1].first * bs[i - 1].first);
			}
		}
		return res;
	};
	vector<mat> ori(n);
	rep(i, n) {
		//i+1
		ori[i] = calc(i);
	}
	
	SegT st(ori);
	rep(aa, q) {
		int l, r; cin >> l >> r; l--; r--;
		bs[trans[l]].second = r;
		bs[trans[r]].second = l;
		swap(trans[l], trans[r]);
		rep(j, 3) {
			if (trans[l] + j < n) {
				st.update(trans[l] + j, calc(trans[l] + j));
			}
			if (trans[r] + j < n) {
				st.update(trans[r] + j, calc(trans[r] + j));
			}
		}
		mat res = st.query(0, n);
		ll ans = -INF; rep(i, 3)ans = max(ans, res[0][i]);
		cout << ans << "\n";
	}
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}