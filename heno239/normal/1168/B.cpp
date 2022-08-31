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
typedef long long  ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
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


void solve() {
	string s; cin >> s;
	int n = s.length();
	ll ans = 0;
	if (n > 8) {
		ans += (ll)(n - 8)*(ll)(n - 7) / 2;
	}
	Rep1(l,3, 8) {
		if (l > n) break;
		rep(j, n - l + 1) {
			bool f = false;
			rep(x, l) {
				for (int k = 1; x + 2 * k < l; k++) {
					if (s[j + x] == s[j + x + k] && s[j + x] == s[j + x + 2 * k]) {
						f = true;
					}
				}
			}
			if (f)ans++;
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