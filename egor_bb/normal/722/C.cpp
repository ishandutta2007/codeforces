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

int a[N], tSize;
ll tree1[4 * N], tree2[4 * N];

int getl(int v, int vl, int vr, int pos) {
	if (pos < vl)
		return N;
	if (tree2[v] == 0)
		return N;
	if (vl == vr - 1)
		return vl;
	int a1 = getl(2 * v + 1, (vl + vr) / 2, vr, pos);
	if (a1 != N)
		return a1;
	return getl(2 * v, vl, (vl + vr) / 2, pos);
}

int getr(int v, int vl, int vr, int pos) {
	if (vr <= pos)
		return N;
	if (tree2[v] == 0)
		return N;
	if (vl == vr - 1)
		return vl;
	int a1 = getr(2 * v, vl, (vl + vr) / 2, pos);
	if (a1 != N)
		return a1;
	return getr(2 * v + 1, (vl + vr) / 2, vr, pos);
}

ll getsum(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl)
		return 0;
	if (l <= vl && vr <= r)
		return tree1[v];
	return getsum(2 * v, vl, (vl + vr) / 2, l, r) +
		   getsum(2 * v + 1, (vl + vr) / 2, vr, l, r);
}

void set_val(int v, int vl, int vr, int pos) {
	if (pos < vl || vr <= pos)
		return;
	if (vl + 1 == vr) {
		tree2[v] = 1;
		tree1[v] = 0;
		return;
	}
	set_val(2 * v, vl, (vl + vr) / 2, pos);
	set_val(2 * v + 1, (vl + vr) / 2, vr, pos);
	tree1[v] = tree1[2 * v] + tree1[2 * v + 1];
	tree2[v] = tree2[2 * v] + tree2[2 * v + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	tSize = 1;
	while (tSize < n)
		tSize *= 2;
	multiset<ll> s;
	ll sum = 0;
	forn(i, n) {
		cin >> a[i];
		tree1[tSize + i] = a[i];
		sum += a[i];
	}	
	fornr(i, tSize)
		tree1[i] = tree1[2 * i] + tree1[2 * i + 1];
	s.insert(-sum);
	forn(i, n) {
		int id; cin >> id;
		id--;
		int l = getl(1, 0, tSize, id);
		int r = getr(1, 0, tSize, id);
		if (l == N)
			l = -1;
		if (r == N)
			r = n;
		s.erase(s.find(-getsum(1, 0, tSize, l + 1, r)));
		set_val(1, 0, tSize, id);
		s.insert(-getsum(1, 0, tSize, l + 1, id));
		s.insert(-getsum(1, 0, tSize, id + 1, r));
		cout << -(*s.begin()) << '\n';
	}
	return 0;
}