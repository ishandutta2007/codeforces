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

struct Point {
	int i, x, t;
	bool operator < (const Point& o) const {
		if (x != o.x) return x < o.x;
		else return t > o.t;
	}
};

const int N = 2e5+1;
const int L = 18;
int l[N], r[N], x[N], y[N];
int par[N][L];
int start[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	vector<Point> p;
	FOR(i,1,n) {
		cin >> l[i] >> r[i];
		p.push_back({i,l[i],1});
		p.push_back({i,r[i],-1});
	}
	FOR(i,1,m) {
		cin >> x[i] >> y[i];
		p.push_back({i,x[i],0});
	}
	sort(p.begin(), p.end());

	int best = 0;
	r[0] = -1;
	for (const Point& it : p) {
		if (it.t == 1) {
			if (r[it.i] > r[best]) {
				best = it.i;
			}
		} else if (it.t == -1) {
			if (r[best] > it.x) {
				par[it.i][0] = best;
			}
		} else {
			if (r[best] >= it.x) {
				start[it.i] = best;
			}
		}
	}

	FOR(j,1,L-1) {
		FOR(i,1,n) {
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}

	FOR(i,1,m) {
		int ans = 1;
		int u = start[i];
		if (r[u] < y[i]) {
			Down(j,L) {
				if (par[u][j] != 0 && r[par[u][j]] < y[i]) {
					u = par[u][j];
					ans += 1<<j;
				}
			}
			if (r[par[u][0]] < y[i]) {
				ans = -1;
			} else {
				ans++;
			}
		}
		cout << ans << nl;
	}

	return 0;
}