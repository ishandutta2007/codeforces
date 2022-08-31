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

void solve() {
	ll a, b; cin >> a >> b;
	ll d = abs(a - b);
	if (d == 0) {
		cout << 0 << endl; return;
	}
	ll n = 1;
	while (n*(n + 1) / 2 < d)n++;
	while ((n*(n + 1) / 2 - d) % 2)n++;
	cout << n << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}