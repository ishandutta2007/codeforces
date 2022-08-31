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
const ld eps = 1e-3;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; ll c[30]; ll l;
ll mi[31];
void calcmi() {
	mi[0] = c[0];
	rep1(i, n - 1) {
		mi[i] = min(c[i], mi[i - 1] * 2);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> l;
	rep(i, n) {
		cin >> c[i];
	}
	calcmi();
	ll ans = INF;
	ll sum = 0;
	per(i, n) {
		ll d = ((ll)1 << i);
		ll dd = l / d;
		ans = min(ans, sum+(dd + 1)*mi[i]);
		sum += dd * mi[i];
		l %= d;
	}
	ans = min(ans, sum);
	cout << ans << endl;
	//stop
	return 0;
}