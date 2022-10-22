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

const int N = 1e6+1;
int a[N], b[N], d[N], g[N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	For(i,m) {
		cin >> a[i] >> b[i];
		d[a[i]]++;
		d[b[i]]++;
	}

	g[0] = INF;
	FOR(i,1,n) {
		g[i] = (d[i]+1)/2;
	}

	for (int e = m - (n+m+1)/2; e > 0; e--) {
		int i = rng()%m;
		while (!(d[a[i]]>g[a[i]] && d[b[i]]>g[b[i]])) {
			i = rng()%m;
		}
		d[a[i]]--;
		d[b[i]]--;
		a[i] = b[i] = 0;
	}

	cout << min(m, (n+m+1)/2) << nl;
	For(i,m) {
		if (a[i]) {
			cout << a[i] << " " << b[i] << nl;
		}
	}

	return 0;
}