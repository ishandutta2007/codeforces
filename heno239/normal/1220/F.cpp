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
const ld pi = acos(-1.0);

vector<int> b;
struct SegT {
private:
	int sz; vector<P> node;
	const int init_c = mod;
public:
	void init(vector<int> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, {mod,0});
		rep(i, n) {
			node[i + sz - 1] = { v[i],i };
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	P f(P a, P b) {
		return min(a, b);
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return { mod,0 };
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

SegT st;
int calc(int l, int r) {

	if (l > r)return 0;
	int ret = 0;
	int loc = st.query(l, r + 1).second;
	//cout << l << " " << r << " " << loc << endl;
	ret = max(ret, calc(l, loc-1));
	ret = max(ret, calc(loc+1, r));
	return ret + 1;
}
int n;
int calc2(int mid) {
	return max(calc(0, mid), calc(mid + 1, n-2));
}
void solve() {
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1 0" << endl; return;
	}
	else if (n == 2) {
		cout << "2 0" << endl; return;
	}
	int zre = 0;
	rep(i, n) {
		if (a[i] == 1) {
			zre = i;
			rep1(j, n-1) {
				int id = (i + j) % n;
				b.push_back(a[id]);
			}
			break;
		}
	}
	st.init(b);
	int le = -1, ri = n-2;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		int cle = calc(0, mid);
		int cri = calc(mid+1,n-2);
		if (cle > cri) {
			ri = mid;
		}
		else {
			le = mid;
		}
	}
	if (ri == n||le==-1) {
		int ma = calc(0, n-2);
		cout << ma+1 << " " << zre << endl;
	}
	else {
		int ma = 0;
		int chk = 0;
		int cl = calc2(le); int cr = calc2(ri);
		if (cl < cr) {
			int num = zre + le + 2;
			num %= n;
			cout << cl + 1 << " " << num << endl;
		}
		else {
			int num = zre + ri + 2;
			num %= n;
			cout << cr + 1 << " " << num << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}