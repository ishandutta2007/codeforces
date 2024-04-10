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

void rev(vector<int> &v, int l, int r) {
	Rep1(i, l, r)if (v[i] >= 0)v[i] ^= 1;
}

int query(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int res; cin >> res; return res;
}
void solve() {
	int n, t; cin >> n >> t;
	vector<int> v(n, -1);
	vector<P> cn;
	int ori = t;
	rep(i, n / 2) {
		while (true) {
			int c = i;
			int x = 0,y=0;
			rep(j, c)if (v[j] == 1)x++;
			rep(j, c)if (v[n - 1 - j] == 1)y++;
			int cl = n - c - t + 2 * y - 1;
			int cr = n - c - t + 2 * y + 1;
			int cm = n - c - t + 2 * x;
			int l = i;
			int r = n - 2 - i;
			t = query(l, r);
			if (t == cm) {
				cn.push_back({ l,n - 1 });
				rev(v, l, n - 1);
			}
			else {
				cn.push_back({ 0,r });
				rev(v, 0, r);
				v[n - 1 - i] = (t == cr);
				break;
			}
		}
		while (true) {
			int c = i;
			int x = 0, y = 0;
			rep(j, c)if (v[j] == 1)x++;
			rep(j, c)if (v[n - 1 - j] == 1)y++;
			int cl = n - c - t + 2 * x - 1;
			int cr = n - c - t + 2 * x + 1;
			int cm = n - c - t + 2 * y;
			int l = i+1;
			int r = n - 1 - i;
			t = query(l, r);
			if (t == cm) {
				cn.push_back({ 0,r });
				rev(v, 0,r);
			}
			else {
				cn.push_back({l,n-1 });
				rev(v, l, n-1);
				v[i] = (t == cr);
				break;
			}
		}
	}
	per(i, (int)cn.size()) {
		int l = cn[i].first, r = cn[i].second;
		rev(v, l, r);
	}
	int cnt = 0;
	rep(i, n)if (v[i] == 1)cnt++;
	if (n % 2)v[n / 2] = (cnt != ori);
	string ans;
	rep(i, n)ans.push_back('0' + (v[i]));
	cout << "! " << ans << endl;
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