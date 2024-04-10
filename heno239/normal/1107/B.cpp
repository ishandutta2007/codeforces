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
const ll mod = 998244353;
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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
ll c[15][10];
ll time10[15];
void init() {
	rep(i, 10) {
		c[0][i] = 1;
	}
	rep(i, 14) {
		rep(j, 10) {
			rep(k, 10) {
				c[i + 1][(j + k) % 10] += c[i][j];
			}
		}
	}
	time10[0] = 1;
	rep(i, 14) {
		time10[i + 1] = time10[i] * 10;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int q; cin >> q;
	rep(aa, q) {
		ll k; int x;
		cin >> k >> x;
		cout << x + 9 * (k - 1) << endl;
	}
	//stop
	return 0;
}