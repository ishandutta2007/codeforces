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

const int N = 1e5+1;
int x[N], y[N];
ll ans[N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	memset(ans, -1, sizeof ans);

	int n, m, k;
	cin >> n >> m >> k;

	unordered_map<int,set<int>> plus, minus;
	For(i,k) {
		cin >> x[i] >> y[i];
		plus[x[i]+y[i]].insert(i);
		minus[x[i]-y[i]].insert(i);
	}

	int cx = 0;
	int cy = 0;
	int dx = 1;
	int dy = 1;
	ll cur = 0;
	for(;;) {
		int tx = (dx==1 ? n-cx : cx);
		int ty = (dy==1 ? m-cy : cy);
		if (dx == dy) {
			for (int i : minus[cx-cy]) {
				ans[i] = cur + abs(x[i]-cx);
				plus[x[i]+y[i]].erase(i);
			}
			minus[cx-cy].clear();
		} else {
			for (int i : plus[cx+cy]) {
				ans[i] = cur + abs(x[i]-cx);
				minus[x[i]-y[i]].erase(i);
			}
			plus[cx+cy].clear();
		}
		if (tx < ty) {
			cur += tx;
			cx += dx*tx;
			cy += dy*tx;
			dx = -dx;
		} else {
			cur += ty;
			cx += dx*ty;
			cy += dy*ty;
			dy = -dy;
		}
		if (tx == ty) {
			break;
		}
	}

	For(i,k) {
		cout << ans[i] << nl;
	}

	return 0;
}