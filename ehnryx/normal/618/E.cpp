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

const ld PI = acos((ld)-1);
inline pt unit(const pt& x) { return x/abs(x); }

const int N = 1<<19;
pt st[2*N], az[2*N], rz[2*N];

void push(int i) {
	if (rz[i] != pt(1,0)) {
		az[2*i] *= rz[i];
		rz[2*i] *= rz[i];
		st[2*i] *= rz[i];
		az[2*i+1] *= rz[i];
		rz[2*i+1] *= rz[i];
		st[2*i+1] *= rz[i];
		rz[i] = 1;
	}
	if (az[i] != pt(0,0)) {
		az[2*i] += az[i];
		st[2*i] += az[i];
		az[2*i+1] += az[i];
		st[2*i+1] += az[i];
		az[i] = 0;
	}
}

void add(int l, int r, const pt& v, int i=1, int s=0, int e=N-1) {
	if (r<s || e<l) return;
	if (l<=s && e<=r) {
		az[i] += v;
		st[i] += v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	add(l,r,v,2*i,s,m);
	add(l,r,v,2*i+1,m+1,e);
}

void rot(int l, int r, const pt& v, int i=1, int s=0, int e=N-1) {
	if (r<s || e<l) return;
	if (l<=s && e<=r) {
		rz[i] *= v;
		az[i] *= v;
		st[i] *= v;
		return;
	}
	push(i);
	int m = (s+e)/2;
	rot(l,r,v,2*i,s,m);
	rot(l,r,v,2*i+1,m+1,e);
}

pt query(int x, int i=1, int s=0, int e=N-1) {
	if (s==e) {
		return st[i];
	}
	push(i);
	int m = (s+e)/2;
	if (x<=m) return query(x, 2*i, s, m);
	else return query(x, 2*i+1, m+1, e);
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

	fill(rz, rz+2*N, 1);
	fill(az, az+2*N, 0);
	fill(st, st+2*N, 0);

	int n, m;
	cin >> n >> m;

	For(i,n+1) {
		st[i+N] = pt(i,0);
	}

	For(i,m) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			pt a = query(x-1);
			pt b = query(x);
			add(x, n, (ld)y*unit(b-a));
		} else {
			pt c = query(x-1);
			add(x, n, -c);
			rot(x, n, exp(pt(0,-y*PI/180)));
			add(x, n, c);
		}
		pt ans = query(n);
		cout << ans.real() << " " << ans.imag() << nl;
	}

	return 0;
}