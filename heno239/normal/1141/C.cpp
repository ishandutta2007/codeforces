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

ll ans[1 << 18];
ll dif[1 << 18];
bool exi[1 << 18];
void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		cin >> dif[i];
	}
	ll mi = 2 * n;
	ans[0] = 0;
	rep(i, n - 1) {
		ans[i + 1] = ans[i] + dif[i];
	}
	rep(i, n) {
		mi = min(mi, ans[i]);
	}
	rep(i, n) {
		ans[i] += 1 - mi;
		if (ans[i]>n || exi[ans[i]]) {
			cout << -1 << endl; return;
		}
		exi[ans[i]] = true;
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}