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

struct Node {
	Node *l = NULL, *r = NULL;
	Node *par = NULL;
	int pos = -1;
};

const int N = 2e5 + 100;

int depth[8 * N], tSize, minPos[8 * N], a[2 * N], psh[8 * N];
Node vs[N];
int minElement[8 * N];

int getMinPos(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return -1;
	}
	if (l <= vl && vr <= r) {
		return minPos[v];
	}
	int m = (vl + vr) / 2;
	int il = getMinPos(2 * v, vl, m, l, r);
	int ir = getMinPos(2 * v + 1, m, vr, l, r);
	if (il == -1) return ir;
	if (ir == -1) return il;
	if (a[il] < a[ir]) return il;
	return ir;
}


void push(int v, int vl, int vr) {
	if (vl + 1 == vr) return;
	forn(i, 2) {
		depth[2 * v + i] += psh[v];
		psh[2 * v + i] += psh[v];
	}
	psh[v] = 0;
}

void addDepth(int v, int vl, int vr, int l, int r, int add) {
	if (vr <= l || r <= vl) {
		return;
	}
	if (l <= vl && vr <= r) {
		psh[v] += add;
		depth[v] += add;
		return;
	}
	push(v, vl, vr);
	addDepth(2 * v, vl, (vl + vr) / 2, l, r, add);
	addDepth(2 * v + 1, (vl + vr) / 2, vr, l, r, add);
	depth[v] = max(depth[2 * v], depth[2 * v + 1]);
}

int getDepth(int v, int vl, int vr, int pos) {
	if (vl + 1 == vr) return depth[v];
	push(v, vl, vr);
	int vm = (vl + vr) / 2;
	if (pos < vm) return getDepth(2 * v, vl, vm, pos);
	return getDepth(2 * v + 1, vm, vr, pos);
}

Node* buildTree(int l, int r) {
	addDepth(1, 0, tSize, l, r, 1);
	int posV = getMinPos(1, 0, tSize, l, r);
	Node *v = &vs[posV];
	v->pos = posV;
	if (posV > l) {
		v->l = buildTree(l, posV);
		v->l->par = v;
	}
	if (posV + 1 < r) {
		v->r = buildTree(posV + 1, r);
		v->r->par = v;
	}
	return v;
}

int minElementPos(int v, int vl, int vr, int l, int r, int val) {
	if (vr <= l || r <= vl) {
		return -1;
	}
	if (l <= vl && vr <= r) {
		if (minElement[v] >= val) return -1;
	}
	if (vl + 1 == vr) return v - tSize;
	int posR = minElementPos(2 * v + 1, (vl + vr) / 2, vr, l, r, val);
	if (posR != -1) return posR;
	return minElementPos(2 * v, vl, (vl + vr) / 2, l, r, val);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	tSize = 1;
	while(tSize < n * 2) tSize *= 2;
	forn(i, tSize) minPos[i + tSize] = -1;
	forn(i, n) minPos[i + tSize] = i;
	fornr(v, tSize) {
		int il = minPos[2 * v];
		int ir = minPos[2 * v + 1];
		if (il == -1) minPos[v] = ir;
		else if (ir == -1) minPos[v] = il;
		else if (a[il] < a[ir]) minPos[v] = il;
		else minPos[v] = ir;
	}
	
	forn(i, tSize) minElement[i + tSize] = n + 100;
	forn(i, 2 * n) minElement[i + tSize] = a[i];
	fornr(v, tSize) {
		minElement[v] = min(minElement[2 * v], minElement[2 * v + 1]);
	}
	
	Node *root = buildTree(0, n);
	//cout << depth[1] << '\n';
	int ans = depth[1], ansShift = 0;
	forn(i, n) {
		vs[i].pos += n;
		if (a[i] == 1) {
			addDepth(1, 0, tSize, i, i + 1, -1);
			addDepth(1, 0, tSize, i + n, i + n + 1, 1);
			swap(vs[i].l, vs[i].r);
			continue;
		}
		Node *par = vs[i].par;
		if (vs[i].r) vs[i].r->par = par;
		par->l = vs[i].r;
		vs[i].r = NULL;
		int rEdge = par->pos;
		addDepth(1, 0, tSize, i, i + 1, -getDepth(1, 0, tSize, i));
		addDepth(1, 0, tSize, i + 1, rEdge, -1);
		int minPos = minElementPos(1, 0, tSize, i + 1, i + n, a[i]);		
		assert(minPos != -1);
		vs[i].l = vs[minPos % n].r;
		vs[minPos % n].r = &vs[i];
		vs[i].par = &vs[minPos % n];
		if (vs[i].l) {
			cerr << "Updated l par " << a[vs[i].l->pos] << '\n';
			vs[i].l->par = &vs[i];
		}
		int depthMinPos = getDepth(1, 0, tSize, minPos);
		addDepth(1, 0, tSize, i + n, i + n + 1, depthMinPos);
		addDepth(1, 0, tSize, minPos + 1, i + n + 1, 1);
		if (ans > depth[1]) {
			ans = depth[1];
			ansShift = i + 1;
		}
	}
	cout << ans << " " << ansShift << '\n';
	return 0;
}