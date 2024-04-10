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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int mostri[1 << 20];
int mostle[1 << 20];
bool exi[1 << 20];
void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	int le = 0, ri = x;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		bool f = true;
		int memo = 0;
		rep(i, n) {
			if (a[i] < mid)continue;
			if (memo > a[i]) {
				f = false; break;
			}
			memo = a[i];
		}
		if (f)ri = mid;
		else le = mid;
	}
	int c = ri;
	if (ri == 1) {
		ll ans = (ll)x*(x + 1) / 2;
		cout << ans << endl; return;
	}
	ll ans = x+2-c;
	int loc = 0;
	fill(mostri, mostri + (1 << 20), n);
	fill(mostle, mostle + (1 << 20), n);
	rep(i, n) {
		mostri[a[i]] = i; exi[a[i]] = true;
	}
	per(i, n) {
		mostle[a[i]] = i;
	}
	rep1(i, x) {
		c = max(c, i + 2);
		if (!exi[i]) {
			ans += x + 2 - c;
		}
		else {
			if (mostle[i] < loc)break;
			for (int j = loc; j < mostri[i]; j++) {
				c = max(c, a[j] + 1);
			}
			loc = mostri[i];
			ans += x + 2 - c;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}