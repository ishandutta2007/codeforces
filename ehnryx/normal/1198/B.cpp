#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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

const int N = 1<<18;
int segt[2*N], maxv[2*N];

void build() {
}

void push(int i) {
	if (maxv[i]) {
		maxv[2*i] = max(maxv[2*i], maxv[i]);
		segt[2*i] = max(segt[2*i], maxv[i]);
		maxv[2*i+1] = max(maxv[2*i+1], maxv[i]);
		segt[2*i+1] = max(segt[2*i+1], maxv[i]);
		maxv[i] = 0;
	}
}

void setv(int x, int v, int i=1, int s=0, int e=N-1) {
	if (s==e) {
		segt[i] = v;
		maxv[i] = 0;
		return;
	}
	push(i);
	int m = (s+e)/2;
	if (x<=m) setv(x, v, 2*i, s, m);
	else setv(x, v, 2*i+1, m+1, e);
}

void update(int x) {
	maxv[1] = max(maxv[1], x);
}

int query(int x, int i=1, int s=0, int e=N-1) {
	if (s==e) {
		return segt[i];
	}
	push(i);
	int m = (s+e)/2;
	if (x<=m) return query(x, 2*i, s, m);
	else return query(x, 2*i+1, m+1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	FOR(i,1,n) {
		cin >> segt[N+i];
	}
	build();

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			setv(p,x);
		}
		else {
			int x;
			cin >> x;
			update(x);
		}
	}

	FOR(i,1,n) {
		cout << query(i) << " ";
	}
	cout << nl;

	return 0;
}