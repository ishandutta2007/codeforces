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

void solve() {
	int n; cin >> n;
	vector<ll> b(n);
	rep(i, n) {
		cin >> b[i];
	}
	vector<ll> ans[60];
	rep(i, n) {
		int cnt = 0;
		ll cop = b[i];
		while (cop % 2 == 0) {
			cop /= 2; cnt++;
		}
		ans[cnt].push_back(b[i]);
	}
	int ma = 0; int chk = -1;
	rep(i, 60) {
		if (ans[i].size() > ma) {
			ma = ans[i].size();
			chk = i;
		}
	}
	map<ll, bool> used;
	rep(i, ans[chk].size()) {
		used[ans[chk][i]] = true;
	}
	vector<ll> out;
	rep(i, n) {
		if (!used[b[i]])out.push_back(b[i]);
	}
	cout << out.size() << endl;
	rep(i, out.size()) {
		if (i > 0)cout << " ";
		cout << out[i];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}