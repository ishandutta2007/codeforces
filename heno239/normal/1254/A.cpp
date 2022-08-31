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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

string alt;
void init() {
	rep(i, 10)alt.push_back('0' + i);
	rep(i, 26)alt.push_back('a' + i);
	rep(i, 26)alt.push_back('A' + i);
}
void solve() {
	int h, w; cin >> h >> w;
	int k; cin >> k;
	vector<vector<char>> mp(h),ans(h);
	int cnt = 0;
	rep(i, h){
		mp[i].resize(w);
		ans[i].resize(w);
		rep(j, w) {
			cin >> mp[i][j];
			if (mp[i][j] == 'R')cnt++;
		}
	}
	int tmp = 0;
	int num = 0;
	int d = cnt / k;
	int r = cnt % k;
	rep(i, h) {
		if (i % 2 == 0) {
			rep(j, w) {
				if (mp[i][j] == '.') {
					ans[i][j] = alt[tmp];
				}
				else {
					int rest = d; if (r > 0)rest++;
					if (rest < num + 1) {
						num = 0; tmp++; r--;
					}
					ans[i][j] = alt[tmp]; num++;
				}
			}
		}
		else {
			per(j, w) {
				if (mp[i][j] == '.') {
					ans[i][j] = alt[tmp];
				}
				else {
					int rest = d; if (r > 0)rest++;
					if (rest < num + 1) {
						num = 0; tmp++; r--;
					}
					ans[i][j] = alt[tmp]; num++;
				}
			}
		}
	}
	rep(i, h){
		rep(j, w) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
		return 0;
}