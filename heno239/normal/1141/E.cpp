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

ll h; int n;
ll d[1 << 18];
ll rd[1 << 18];
void solve() {
	cin >> h >> n;
	ll mi = INF;
	rep(i, n) {
		cin >> d[i];
	}
	rep(i, n) {
		rd[i + 1] = rd[i] + d[i];
		mi = min(mi, rd[i+1]);
	}

	//check
	rep1(i, n) {
		if (h+rd[i] <= 0) {
			cout << i << endl; return;
		}
	}
	if (rd[n] >= 0) {
		cout << -1 << endl; return;
	}
	//cout << -rd[n] << endl;
	ll dif = h + mi;
	//cout << dif << endl;
	ll d = (dif -rd[n] - 1) / (-rd[n]);
	ll ans = d * n; h += d * rd[n];
	//cout << h << endl;
	rep1(i, n) {
		if (h + rd[i] <= 0) {
			cout << ans + i << endl; return;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}