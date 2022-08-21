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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9) + 7;
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
int main() {
	ll n; int q; cin >> n >> q;
	rep(i, q) {
		int x, y; cin >> x >> y;
		ll d = (x-1) / 2;
		ll r = (x - 1) % 2;
		ll dy = y / 2;
		ll ry = y % 2;
		ll out = 0;
		if ((x + y) % 2) {
			out += (n*n + 1) / 2;
			if (r) {
				out += n / 2;
			}
			if (ry&&x%2==0)out++;
		}
		else {
			if (r) {
				out += (n + 1) / 2;
			}
			if (ry&&x%2)out++;
		}
		out += d * n;
		out += dy;
		cout << out << endl;
	}
	return 0;
}