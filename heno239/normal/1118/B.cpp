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
ll a[1 << 18];
ll s[1 << 18][2];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		if (i % 2 == 0) {
			s[i + 1][0] = s[i][0] + a[i];
			s[i + 1][1] = s[i][1];
		}
		else {
			s[i + 1][0] = s[i][0];
			s[i + 1][1] = s[i][1] + a[i];
		}
	}
	int cnt = 0;
	rep(i, n) {
		ll x1 = s[i][0] + s[n][1] - s[i + 1][1];
		ll x2 = s[i][1] + s[n][0] - s[i + 1][0];
		if (x1 == x2)cnt++;
	}
	cout << cnt << endl;
	//stop
	return 0;
}