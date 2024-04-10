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
typedef double ld;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

ll mod_pow(ll x, ll n,ll m) {
	ll ret = 1;
	while (n) {
		if (n % 2) {
			ret = ret * x%m;
		}
		x = x * x%m; n >>= 1;
	}
	return ret;
}
struct rolling_hash{
private:
	int sz;
	vector<ll> node;
	vector<ll> r;
	ll t = 999999937;
	ll m = 1000000009;
	ll invt;
public:
	rolling_hash(const string &s) {
		int n = s.length();
		sz = n;
		node.resize(n + 1); r.resize(n + 1);
		node[0] = 0;

		invt = mod_pow(t, m - 2, m);
		ll a = 1;
		rep(i, n) {
			//r[i] = a;
			int z = s[i] - 'a';
			node[i + 1] = node[i] + a * z;
			node[i + 1] %= m;
			a = a * t%m;
		}
		a = 1;
		rep(i, n) {
			r[i] = a; a = invt * a%m;
		}
	}
	ll calc(int le, int len) {
		ll ret = node[le + len] - node[le];
		if (ret < 0)ret += m;
		ret = ret * r[le] % m;
		return ret;
	}
};
int loc[1 << 17][31];
void solve() {
	int n, m;
	string s, t;
	cin >> n >> s >> m >> t;
	int x; cin >> x;
	rolling_hash rs(s), rt(t);
	//cout << rs.calc(1, 3) << endl;
	//cout << rt.calc(0, 3) << endl;
	rep(i, n) {
		rep(j, x) {
			int id = loc[i][j];
			int le = -1, ri = m - id+1;
			while (ri - le > 1) {
				int mid = (ri + le) / 2;
				if (i + mid > n) {
					ri = mid; continue;
				}
				ll cs = rs.calc(i, mid);
				ll ct = rt.calc(id, mid);
				if (cs == ct) {
					//cout << mid<<" "<<"hello" << endl;
					le = mid;
				}
				else ri = mid;
			}
			//cout << le << endl;
			//cout << i<<" "<<j<<" "<<le << endl;
			loc[i + le][j + 1] = max(loc[i + le][j + 1], id + le);
			if (id + le == m) {
				cout << "YES" << endl; return;
			}
			loc[i + 1][j] = max(loc[i + 1][j], loc[i][j]);
		}
	}
	/*rep(i, n) {
		rep(j, x) {
			cout << i << " " << j << " " << loc[i][j] << endl;
		}
	}*/
	cout << "NO" << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}