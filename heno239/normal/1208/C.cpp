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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
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

void solve(){
	int n; cin >> n;
	vector<vector<int>> ans(n);
	rep(i, n) {
		ans[i].resize(n);
	}
	rep(i, n / 4) {
		rep(j, n / 4) {
			int c = i * (n / 4) + j;
			rep(k, 4) {
				rep(l, 4) {
					int x = 4 * i + k;
					int y = 4 * j + l;
					ans[x][y] = 16 * c + 4 * k + l;
				}
			}
		}
	}
	/*rep(j, n) {
		int s = 0;
		rep(i, n) {
			s ^= ans[i][j];
		}
		cout << s << endl;
	}*/
	rep(i, n) {
		rep(j, n) {
			if (j > 0)cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}