
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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	int n, d, b; cin >> n >> d >> b;
	vector<int > a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<int> ra(n + 1);
	rep(i, n) {
		ra[i + 1] += ra[i] + a[i];
	}
	int hn = n / 2;
	int le = -1, ri = hn + 1;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		bool valid = true;
		Rep(j, mid, hn) {
			int l = 0, r = min((ll)n, j + (ll)(j + 1)*d+1);
			ll sum = ra[r] - ra[l];
			//cout << mid << " " << j << " " << sum << endl;
			sum -= (j-mid)*b;
			//cout << mid << " "<<j<<" " << sum << endl;
			if (sum < b) {
				valid = false; break;
			}
		}
		Rep(j, mid, hn) {
			int rj = n - 1 - j;
			int l = max((ll)0, rj - (ll)(j + 1)*d);
			int r = n;
			ll sum = ra[r] - ra[l];
			sum -= (j-mid)*b;
			//cout << mid << " " << j << " " << sum << endl;
			if (sum < b) {
				valid = false; break;
			}
		}
		if (valid) {
			ri = mid;
		}
		else {
			le = mid;
		}
	}
	cout << ri << endl;
	//int ans = hn - ri;
	//cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}