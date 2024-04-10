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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n, a, b;
ll h[1 << 18], c[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll sum = 0;
	cin >> n >> a >> b; b = min(b, n);
	rep(i, n) {
		cin >> h[i] >> c[i]; sum += c[i];
	}
	if (b == 0) {
		cout << sum << endl; return 0;
	}
	vector<ll>v;
	rep(i, n)v.push_back(h[i] - c[i]);
	sort(v.begin(), v.end(), greater<ll>());
	rep(i, b) {
		if (v[i] < 0)break;
		sum += v[i];
	}
	ll z = max((ll)0,v[b - 1]);
	ll k = (1 << a);
	ll ans = sum;
	rep(i, n) {
		ll u = h[i] - c[i];
		ll csum = sum;
		if (u > z)csum -= u;
		else csum -= z;
		ll x = h[i] * k - c[i]; csum += x;
		ans = max(ans, csum);
	}
	cout << ans << endl;
	//stop
		return 0;
}