#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3+1;
string grid[N];
int pre[N][N], inv[N][N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m, q;
	cin >> n >> m >> q;

	For(i,n) {
		cin >> grid[i];
	}

	For(i,n) {
		For(j,m) {
			pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + (grid[i][j]=='1');
			inv[i+1][j+1] = inv[i][j+1] + inv[i+1][j] - inv[i][j] + (grid[i][j]=='0');
		}
	}

	function<ll(ll,ll)> get = [&] (ll x, ll y) {
		ll bigx = x/n;
		ll bigy = y/m;
		ll dx = x%n;
		ll dy = y%m;
		ll res = ((__builtin_popcount(bigx)+__builtin_popcount(bigy))%2==0 ? pre[dx][dy] : inv[dx][dy]);
		if (bigx%2 && bigy%2) {
			res += (bigx*bigy-1)*(pre[n][m]+inv[n][m])/2;
			if ((__builtin_popcount(bigx)+__builtin_popcount(bigy))%2) {
				res += inv[n][m];
			} else {
				res += pre[n][m];
			}
		} else {
			res += bigx*bigy*(pre[n][m]+inv[n][m])/2;
		}
		if (bigx%2) {
			res += (bigx-1)*(pre[n][dy]+inv[n][dy])/2;
			res += ((__builtin_popcount(bigx)+__builtin_popcount(bigy))%2 ? pre[n][dy] : inv[n][dy]);
		} else {
			res += bigx*(pre[n][dy]+inv[n][dy])/2;
		}
		if (bigy%2) {
			res += (bigy-1)*(pre[dx][m]+inv[dx][m])/2;
			res += ((__builtin_popcount(bigx)+__builtin_popcount(bigy))%2 ? pre[dx][m] : inv[dx][m]);
		} else {
			res += bigy*(pre[dx][m]+inv[dx][m])/2;
		}
		return res;
	};

	while (q--) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//cerr << get(x1-1,y1-1) << " + " << get(x2,y2) << " - " << get(x1-1,y2) << " - " << get(x2,y1-1) << " = " << nl;
		cout << get(x1-1,y1-1) + get(x2,y2) - get(x1-1,y2) - get(x2,y1-1) << nl;
		//cerr << nl;
	}

	return 0;
}