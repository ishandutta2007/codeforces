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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct info{
	int k, l, r;
};

struct SegT {
private:
	int sz; vector<int> nodema, nodemi;
	const int init_ma = -mod, init_mi = mod;
public:
	SegT(vector<int> ori) {
		int n = ori.size();
		sz = 1;
		while (sz < n)sz *= 2;
		nodema.resize(2 * sz - 1, init_ma);
		nodemi.resize(2 * sz - 1, init_mi);
		rep(i, n) {
			nodema[i + sz - 1] = nodemi[i + sz - 1] = ori[i];
		}
		per(i, sz - 1) {
			nodema[i] = maf(nodema[2*i+1], nodema[2 * i + 2]);
			nodemi[i] = mif(nodemi[2 * i + 1], nodemi[2 * i + 2]);
		}
	}
	int maf(int a, int b) {
		return max(a, b);
	}
	int mif(int a,int b){
		return min(a, b);
	}
	int find_id_ma(int i,int x) {
		if (i == sz)return sz;
		if (nodema[i + sz - 1] >= x)return i;
		int k = 0, l = 0, r = sz;
		stack<info> st;
		while (k < sz - 1) {
			int mid = (l + r) / 2;
			if (mid > i) {
				st.push({ 2 * k+2,mid,r });
				k = 2 * k + 1; r = mid;
			}
			else {
				k = 2 * k + 2; l=mid;
			}
		}
		k = -1;
		while (!st.empty()) {
			info in = st.top(); st.pop();
			if (nodema[in.k] >= x) {
				k = in.k, l = in.l; r = in.r;
				break;
			}
		}
		if (k < 0)return sz;
		while (k < sz - 1) {
			int mid = (l + r) / 2;
			if (nodema[2 * k + 1] >= x) {
				k = 2 * k + 1, r = mid;
			}
			else {
				k = 2 * k + 2; l = mid;
			}
		}
		return k - sz + 1;
	}
	int find_id_mi(int i, int x) {
		if (i == sz)return sz;
		if (nodemi[i + sz - 1] <= x)return i;
		int k = 0, l = 0, r = sz;
		stack<info> st;
		while (k < sz - 1) {
			int mid = (l + r) / 2;
			if (mid > i) {
				st.push({ 2 * k + 2,mid,r });
				k = 2 * k + 1; r = mid;
			}
			else {
				k = 2 * k + 2; l = mid;
			}
		}
		k = -1;
		while (!st.empty()) {
			info in = st.top(); st.pop();
			if (nodemi[in.k] <= x) {
				k = in.k, l = in.l; r = in.r;
				break;
			}
		}
		if (k < 0)return sz;
		while (k < sz - 1) {
			int mid = (l + r) / 2;
			if (nodemi[2 * k + 1] <= x) {
				k = 2 * k + 1, r = mid;
			}
			else {
				k = 2 * k + 2; l = mid;
			}
		}
		return k - sz + 1;
	}
};
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	SegT st(a);
	vector<int> up(n), down(n);
	//up
	per(i, n) {
		int nex = st.find_id_ma(i + 1, a[i] + 1);
		if (nex >= n) {
			up[i] = 1;
		}
		else {
			up[i] = up[nex] + 1;
		}
		nex = st.find_id_mi(i + 1, a[i]-1);
		if (nex >= n) {
			down[i] = 1;
		}
		else {
			down[i] = down[nex] + 1;
		}
	}
	vector<P> v; v.push_back({ -mod,mod });
	function<bool(int,int,int)> judge=[&](int i,int u,int d)->bool {
		int sum = 0;
		int uid = st.find_id_ma(i + 1, u + 1);
		if (uid < n)sum += up[uid];
		int did = st.find_id_mi(i + 1, d - 1);
		if (did < n)sum += down[did];
		//cout << i << " " << u << " " << d << " " << uid << " " << did << " " << endl;
		return n - 1 - i == sum;
	};
	function<void(int, int, int)> ans = [&](int i, int u, int d) {

		cout << "YES" << endl;
		rep(j, n) {
			if (j > 0)cout << " ";
			if (j < i) {
				if (a[j] <= u) {
					cout << 0;
				}
				else {
					cout << 1;
				}
			}
			else if (j == i) {
				if (a[j] <= u) {
					d = a[j];
					cout << 1;
				}
				else if (a[j] >= d) {
					u = a[j];
					cout << 0;
				}
			}
			else {
				if (a[j] <= u)cout << 1;
				else cout << 0;
			}
		}
		cout << endl;
	};
	rep(i, n) {
		vector<P> nex;
		rep(j, v.size()) {
			if (a[i] <= v[j].first) {
				if (judge(i, v[j].first, a[i])) {
					//cout << i << " " << v[j].first << " " << v[j].second << endl;
					ans(i, v[j].first, v[j].second);
					return;
				}
				else continue;
			}
			else if (a[i] >= v[j].second) {
				if (judge(i, a[i], v[j].second)) {
					//cout << i << " " << v[j].first << " " << v[j].second << endl;
					ans(i, v[j].first, v[j].second);
					return;
				}
				else continue;
			}
			else {
				nex.push_back({ v[j].first,a[i] });
				nex.push_back({ a[i],v[j].second });
			}
		}
		swap(v, nex);
	}
	if (!v.empty()) {
		ans(n, v[0].first, v[1].first);
		return;
	}
	cout << "NO" << endl;
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