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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;



void solve() {
	int n; cin >> n;
	bool exi[26]; rep(i, 26)exi[i] = true;
	bool detected = false;
	int ans = -1;
	rep(i, n) {
		char t; cin >> t;
		if (t == '.') {
			string s; cin >> s;
			rep(j, s.size()) {
				exi[s[j] - 'a'] = false;
			}
		}
		else if (t == '!') {
			if (detected)ans++;
			string s; cin >> s;
			bool b[26]; rep(j, 26)b[j] = false;
			rep(j, s.size()) {
				b[s[j] - 'a'] = true;
			}
			rep(j, 26) {
				if (!b[j]) {
					exi[j] = false;
				}
			}
		}
		else {
			if (detected)ans++;
			char c; cin >> c;
			exi[c - 'a'] = false;
		}
		int cnt = 0;
		rep(j, 26)if (exi[j])cnt++;
		if (cnt == 1)detected = true;
	}
	if (ans < 0)ans = 0;
	cout << ans << endl;
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