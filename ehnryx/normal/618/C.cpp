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

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }
ld lp_dist(const pt& a, const pt& b, const pt& p) {
	return cp(b-a,p-a) / abs(b-a);
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<pt> p;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back(pt(x,y));
	}

	int best = 1;
	for (int i=2; i<n; i++) {
		if (abs(p[0]-p[i]) < abs(p[0]-p[best])) {
			best = i;
		}
	}
	int memo = best;

	swap(p[1],p[best]);
	ld bestv = 1e42;
	for (int i=2; i<n; i++) {
		ld cur = abs(lp_dist(p[0],p[1],p[i]));
		if (cur > 0 && cur < bestv) {
			bestv = cur;
			best = i;
		}
	}
	if (best == memo) {
		best = 1;
	}

	cout << 1 << " " << memo+1 << " " << best+1 << nl;

	return 0;
}