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

const int N = 1<<19;
struct SegTree {
	ll t[2*N];
	SegTree() {
		memset(t, 0, sizeof t);
	}
	void insert(int x, int v) {
		for (t[x+=N]+=v; x>1; x/=2) {
			t[x/2] = (t[x] + t[x^1]) % MOD;
		}
	}
	ll query(int l, int r) {
		ll res = 0;
		for (l+=N,r+=N+1; l<r; l/=2,r/=2) {
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		return res % MOD;
	}
};

SegTree Left, Right;

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

	vector<pii> p;
	for (int i=1; i<=n; i++) {
		int a;
		cin >> a;
		p.push_back(pii(a,i));
	}
	sort(p.begin(), p.end());

	ll ans = 0;
	for (const pii& it : p) {
		int v, x;
		tie(v,x) = it;
		Left.insert(x, x);
		ll lsum = Left.query(1,x);
		ll rsum = Right.query(x,n);
		ll cur = lsum*(n-x+1) % MOD + rsum*x % MOD;
		Right.insert(x, n-x+1);
		ans += cur * v % MOD;
	}
	cout << ans % MOD << nl;

	return 0;
}