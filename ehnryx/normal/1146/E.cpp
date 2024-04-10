#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;
const int OFF = 1<<17;

int flip[2*N], lazy[2*N], setv[2*N];

void push(int i) {
	if (lazy[i]) {
		setv[2*i] = setv[2*i+1] = setv[i];
		flip[2*i] = flip[2*i+1] = false;
		lazy[2*i] = lazy[2*i+1] = true;
		lazy[i] = false;
	}
	flip[2*i] ^= flip[i];
	flip[2*i+1] ^= flip[i];
	flip[i] = false;
}

void tog(int l, int r, int i, int s, int e) {
	if (r<s || e<l) return;
	if (l<=s && e<=r) {
		flip[i] ^= 1;
		return;
	}
	push(i);
	int m = (s+e)/2;
	tog(l, r, 2*i, s, m);
	tog(l, r, 2*i+1, m+1, e);
}

void upd(int l, int r, int v, int i, int s, int e) {
	if (r<s || e<l) return;
	if (l<=s && e<=r) {
		lazy[i] = true;
		setv[i] = v;
		flip[i] = false;
		return;
	}
	push(i);
	int m = (s+e)/2;
	upd(l, r, v, 2*i, s, m);
	upd(l, r, v, 2*i+1, m+1, e);
}

int que(int x, int i, int s, int e) {
	if (s==e) {
		if (lazy[i]) return setv[i] ^ flip[i];
		else return flip[i];
	}
	push(i);
	int m = (s+e)/2;
	if (x<=m) return que(x, 2*i, s, m) ^ flip[i];
	else return que(x, 2*i+1, m+1, e) ^ flip[i];
}

void toggle(int l, int r) {
	//cerr << "toggle " << l << " " << r << endl;
	tog(l+OFF, r+OFF, 1, 0, N-1);
}
void update(int l, int r, int v) {
	//cerr << "update " << l << " " << r << " -> " << v << endl;
	upd(l+OFF, r+OFF, v, 1, 0, N-1);
}
int query(int x) {
	return que(x+OFF, 1, 0, N-1);
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

	const int BIG = 1e5+1;

	int n, q;
	cin >> n >> q;

	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<q; i++) {
		char c; int x;
		cin >> c >> x;
		int v = abs(x);
		if (c == '<') {
			if (x>0) {
				toggle(-v+1, v-1);
				update(-BIG, -v, 1);
				update(v, BIG, 0);
			} else {
				update(-BIG, -v-1, 1);
				update(v+1, BIG, 0);
			}
		} else {
			if (x<0) {
				toggle(-v+1, v-1);
				update(v, BIG, 1);
				update(-BIG, -v, 0);
			} else {
				update(v+1, BIG, 1);
				update(-BIG, -v-1, 0);
			}
		}
		//cerr << "DEBUG: " << nl; for (int j=0; j<n; j++) {
		//cerr << "  " << a[j] << " -> " << query(a[j]) << nl; }
		//cerr << nl;
	}

	for (int i=0; i<n; i++) {
		if (query(a[i])) a[i] = -a[i];
		cout << a[i] << " ";
	}
	cout << nl;

	return 0;
}