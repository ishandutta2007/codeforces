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
const ll INF = 1e+14;
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

void solve() {
	ll n, m; cin >> n >> m;
	if (m%n != 0) {
		cout << -1 << endl; return;
	}
	ll d = m / n;
	int ans = 0;
	while (d % 2 == 0) {
		d /= 2; ans++;
	}
	while (d % 3 == 0) {
		d /= 3; ans++;
	}
	if (d > 1) {
		cout << -1 << endl; return;
	}
	else {
		cout << ans << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}