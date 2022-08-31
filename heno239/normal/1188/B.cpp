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
using namespace std;

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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;


void solve() {
	int n; ll p, k; cin >> n >> p >> k;
	vector<ll> a(n),b(n);
	rep(i, n) {
		cin >> a[i];
		b[i] = a[i] * a[i] % p;
		b[i] = b[i] * b[i] % p;
		b[i] = b[i] - k * a[i] % p;
		b[i] = (b[i] % p + p) % p;
	}
	sort(b.begin(), b.end());
	ll ans = 0;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&b[i] == b[i + 1])i++;
		ll len = i - le + 1;
		ans += len * (len - 1) / 2;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}