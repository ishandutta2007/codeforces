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
	int x, y, i;
	ll operator * (const Point& o) const {
		return (ll)x*o.y - (ll)y*o.x;
	}
	Point operator - (const Point& o) const {
		return {x-o.x, y-o.y};
	}
};

bool cmpx(const Point& a, const Point& b) {
	if (a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
}

Point base;

bool cmpl(const Point& a, const Point& b) {
	return (a-base)*(b-base) > 0;
}

bool cmpr(const Point& a, const Point& b) {
	return (a-base)*(b-base) < 0;
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

	Point p[n];
	for (int i=0; i<n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].i = i+1;
	}
	sort(p, p+n, cmpx);

	string s;
	cin >> s;

	for (int i=1; i<n-1; i++) {
		base = p[i-1];
		if (s[i-1] == 'L') {
			sort(p+i, p+n, cmpl);
		} else {
			sort(p+i, p+n, cmpr);
		}
	}

	for (int i=0; i<n; i++) {
		cout << p[i].i << " ";
	}
	cout << nl;

	return 0;
}