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

map<int, int> mp[1 << 18];
int num[1 << 18];
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
	}
	ll dec = 0;
	int q; cin >> q;
	rep(i, q) {
		int s, t, u; cin >> s >> t >> u; s--; u--;
		if (mp[s].find(t) != mp[s].end()) {
			int to = mp[s][t];
			num[to]--;
			if (num[to] + 1 <= a[to]) {
				dec--;
			}
			mp[s].erase(t);
		}
		if (u >= 0) {
			int to = u;
			num[to]++;
			if (num[to] <= a[to]) {
				dec++;
			}
			mp[s][t] = u;
		}
		cout << sum - dec << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(4);
	//init();
	solve();
	//stop
		return 0;
}