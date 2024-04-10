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
constexpr ll mod = 998244353;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, (n + 1) / 2) {
		cin >> a[i];
	}
	ll x; cin >> x;
	Rep(i, (n + 1) / 2, n)a[i] = x;
	vector<ll> ra(n + 1);
	rep(i, n) {
		ra[i + 1] = ra[i] + a[i];
	}
	if (ra[n] > 0) {
		cout << n << "\n"; return;
	}
	if (x >= 0) {
		cout << -1 << "\n"; return;
	}
	vector<int> cnt(n + 2);
	cnt[0]++; cnt[n/2+1]--;
	rep(i, (n + 1) / 2) {
		if (ra[(n + 1) / 2] - ra[i] <= 0) {
			cnt[0]++; cnt[n - i + 1]--;
			continue;
		}
		int tl = (n+1) / 2-1, tr = n;
		while (tr - tl > 1) {
			int m = (tl + tr) / 2;
			ll s = ra[m + 1] - ra[i];
			if (s > 0)tl = m;
			else tr = m;
		}
		int l=0, r = tl - i + 1;
		cnt[r + 1]++;
		cnt[n - i + 1]--;
	}
	rep(i, n + 1) {
		cnt[i + 1] += cnt[i];
		if (i>0&&cnt[i] == 0) {
			cout << i << "\n"; return;
		}
	}
	cout << -1 << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}