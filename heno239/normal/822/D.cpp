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

const int mn = 5000000;
//vector<int> chi[mn + 1];
int chi[mn + 1];
ll f[mn + 1];
void init() {
	for (int i = 2; i <= mn; i++) {
		for (int j = i; j <= mn; j += i) {
			if (chi[j] == 0)chi[j] = i;
			//chi[j].push_back(i);
		}
	}
	f[1] = 0;
	for (int i = 2; i <= mn; i++) {
		f[i] = INF;
		//rep(j, chi[i].size()) {
		//ll d = chi[i][j];
		ll d = chi[i];
		ll z = i / d;
		ll cost = f[i/d] + i * (d - 1) / 2;
		f[i] = cost;
		//}
	}
	//rep1(i, mn)cout << i<<" "<<f[i] << endl;
}
void solve() {
	init();
	ll t; int l, r; cin >> t >> l >> r;
	ll ans = 0;
	ll s = 1;
	for (int i = l; i <= r; i++) {
		ans = (ans + f[i]%mod * s%mod) % mod;



		s = s * t%mod;
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}