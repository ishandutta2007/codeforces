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
	string s; cin >> s;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> b[i] >> a[i];
	}
	int ans = 0;
	vector<bool> bb(n, false);
	rep(i, n) {
		if (s[i] == '1') {
			bb[i] = true; ans++;
		}
		else {
			bb[i] = false;
		}
	}
	rep1(i, 1000) {
		rep(j, n) {
			if (i >= a[j] && (i - a[j]) % b[j] == 0) {
				bb[j] = !bb[j];
			}
		}
		int cnt = 0;
		rep(j, n)if (bb[j])cnt++;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}