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
#include<cassert>
using namespace std;

typedef long long ll;

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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;

const int mn = 500001;
int nex[mn][20];
int ri[mn];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, mn) {
		ri[i] = i+1;
	}
	rep(i, n) {
		int l, r; cin >> l >> r;
		ri[l] = max(ri[l], r+1);
	}
	int r = -1;
	rep(i, mn) {
		r = max(r, ri[i]);
		nex[i][0] = r-1;
	}
	rep1(i, 19) {
		rep(j, mn) {
			nex[j][i] = nex[nex[j][i - 1]][i - 1];
		}
	}
	rep(i, m) {
		int x, y; cin >> x >> y;
		int ans = mod;
		int sum = 0;
		per(j, 20) {
			if (nex[x][j] >= y) {
				ans = min(ans, sum + (1 << j));
			}
			else {
				sum += (1 << j);
				x = nex[x][j];
			}
		}
		if (ans == mod)ans = -1;
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n>>h>>m>>s,n)solve();
	solve();
	//stop
	return 0;
}