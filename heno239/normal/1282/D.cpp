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
typedef pair<int, int>P;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

int query(string s) {
	cout << s << endl;
	int x; cin >> x;
	return x;
}
void solve() {
	int z = query("a");
	if (z == 0)return;
	if (z == 300) {
		string ans;
		rep(i, 300)ans.push_back('b');
		cout << ans << endl; cin >> z; return;
	}
	int n = z + 1;
	string u;
	rep(i, n) {
		u.push_back('a');
	}
	int ori = query(u);
	if (ori == n) {
		string ans;
		rep(i, n - 1) {
			ans.push_back('b');
		}
		cout << ans << endl;
		cin >> z;
		return;
	}
	if (ori == 0)return;
	string res; res.resize(n);
	int tmp = 0;
	rep(i, n - 1) {
		u[i] = 'b';
		z = query(u);
		if (z == 0)return;
		if (z < ori) {
			res[i] = 'b'; tmp++;
		}
		else res[i] = 'a';
		u[i] = 'a';
	}
	if (tmp == ori)res[n - 1] = 'a';
	else res[n - 1] = 'b';
	cout << res << endl;
	cin >> z;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init();
	solve();
	//stop
	return 0;
}