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
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

const int mn = 1 << 13;
int nn; ll dat[2 * mn - 1];
void init(int n) {
	nn = 1;
	while (nn < n)nn <<= 1;
		rep(j, 2 * nn - 1) {
			dat[j] = -1;
		}
}
void update(int k, ll a) {
	k += nn - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) >> 1;
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}
ll query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l)return -1;
	if (a <= l && r <= b)return dat[k];
	else {
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
}
int n, k, x;
ll a[5000];
ll dp[5000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> x;
	rep(i, n) {
		cin >> a[i];
	}
	init(n);
	rep(i, k) {
		update(i, a[i]);
	}
	rep(j, x - 1) {
		fill(dp, dp + n, -1);
		rep1(i, n - 1) {
			ll z = query(max(0, i - k), i, 0, 0, nn);
			if (z >= 0) {
				dp[i] = z + a[i];
				//update(i, z + a[i]);
			}
		}
		rep(i, n) {
			update(i, dp[i]);
		}
	}
	ll out = -1;
	Rep(i, n - k, n) {
		out = max(out, dat[i + nn - 1]);
	}
	cout << out << endl;
	return 0;
}