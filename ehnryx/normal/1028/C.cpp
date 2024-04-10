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

struct Segment {
	int a, b, v;
	Segment(int a, int b, int v): a(a), b(b), v(v) {}
};

const int N = 1<<19;
map<int,vector<Segment>> segs; // inclusive
int val[2*N];
int lazy[2*N];
int decmpr[N];
map<int,int> cmpr;

void push(int i) {
	val[2*i] += lazy[i];
	val[2*i+1] += lazy[i];
	lazy[2*i] += lazy[i];
	lazy[2*i+1] += lazy[i];
	lazy[i] = 0;
}

void pull(int i) {
	val[i] = max(val[2*i], val[2*i+1]);
}

void update(int l, int r, int v, int s=0, int e=N-1, int i=1) {
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		val[i] += v;
		lazy[i] += v;
		return;
	}
	else {
		push(i);
		int mid = (s+e)/2;
		update(l, r, v, s, mid, 2*i);
		update(l, r, v, mid+1, e, 2*i+1);
		pull(i);
		return;
	}
}

void sweep(int goal) {
	for (const pair<int,vector<Segment>>& it : segs) {
		for (const Segment& s : it.second) {
			update(cmpr[s.a], cmpr[s.b], s.v);
		}
		if (val[1] >= goal) {
			for (int i = 1; i < N; i++) {
				push(i);
			}
			for (int i = 0; i < N; i++) {
				if (val[i+N] >= goal) {
					cout << it.first << " " << decmpr[i] << nl;
					return;
				}
			}
		}
	}
	assert(false);
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

	int n, a, b, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> x >> y;
		cmpr[b] = cmpr[y] = 0;
		segs[a].push_back(Segment(b,y,1));
		segs[x+1].push_back(Segment(b,y,-1));
	}

	int cnt = 0;
	for (auto& it : cmpr) {
		decmpr[cnt] = it.first;
		it.second = cnt++;
	}

	sweep(n-1);

	return 0;
}