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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n;
ll a[1 << 18], b[1 << 18];
map<LP, int> mp;
ll gcd(ll a, ll b) {
	a = abs(a), b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int ans = 0;
	int cnt = 0;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	rep(i, n) {
		if (a[i] == 0) {
			if (b[i] == 0)cnt++;
		}
		else {
			ll g = gcd(a[i], b[i]);
			a[i] /= g; b[i] /= g;
			if (a[i] < 0) {
				a[i] = -a[i]; b[i] = -b[i];
			}
			mp[{a[i], b[i]}]++;
			ans = max(ans, mp[{a[i], b[i]}]);
		}
	}
	cout << ans + cnt << endl;
	//stop
		return 0;
}