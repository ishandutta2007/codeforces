#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e5 + 100;
const int INF = 1e9 + 7;

int tree[4 * N], tSize;
int psh[4 * N], a[N];

void push(int v) {
	if (v >= tSize)
		return;
	forn(i, 2) {
		tree[2 * v + i] += psh[v];
		psh[2 * v + i] += psh[v];
	}
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	psh[v] = 0;
}

int get(int v, int vl, int vr, int l, int r) {
	if (r <= vl || vr <= l)
		return -INF;
	if (l <= vl && vr <= r)
		return tree[v];
	push(v);
	return max(get(2 * v, vl, (vl + vr) / 2, l, r), get(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

void update(int v, int vl, int vr, int l, int r, int val) {
	if (r <= vl || vr <= l)
		return;
	if (l <= vl && vr <= r) {
		psh[v] += val;
		tree[v] += val;
		return;
	}
	push(v);
	update(2 * v, vl, (vl + vr) / 2, l, r, val);
	update(2 * v + 1, (vl + vr) / 2, vr, l, r, val);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	tSize = 1;
	while (tSize < n) {
		tSize *= 2;
	}
	forn(i, n) {
		int pos; cin >> pos;
		pos--;
		int type; cin >> type;
		if (type == 1) {
			int x; cin >> x;
			a[pos] = x;
			update(1, 0, tSize, 0, pos + 1, 1);
		} else {
			update(1, 0, tSize, 0, pos + 1, -1);
		}
		if (get(1, 0, tSize, 0, n) < 1) {
			cout << -1 << '\n';
			continue;
		}
		int l = 0, r = n;
		while(r - l > 1) {
			int m = (l + r) / 2;
			int p = get(1, 0, tSize, m, n);
			if (p < 1)
				r = m;
			else
				l = m;
		}
		cout << a[l] << '\n';
	}	
	return 0;
}