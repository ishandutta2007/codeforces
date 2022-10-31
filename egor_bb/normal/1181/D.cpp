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
typedef pair <ll, ll> pll;


const int N = 5e5;

int tree[4 * N], ans[N], tSize;
pii cnt[N];
pair<ll, int> query[N];

void inc(int v, int vl, int vr, int pos) {
	tree[v]++;
	if (vl + 1 == vr) {
		return;
	}
	int vm = (vl + vr) / 2;
	if (pos < vm) {
		inc(2 * v, vl, vm, pos);
	} else {
		inc(2 * v + 1, vm, vr, pos);
	}
}

void activate(int pos) {
	inc(1, 0, tSize, pos);
}

int getK(int v, int vl, int vr, int pos) {
	if (vl + 1 == vr) {
		return vl;
	}
	int leftSum = tree[2 * v], vm = (vl + vr) / 2;
	if (pos < leftSum) {
		return getK(2 * v, vl, vm, pos);
	} else {
		return getK(2 * v + 1, vm, vr, pos - leftSum);
	}
}

int getK(int k) {
	return getK(1, 0, tSize, k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	forn(i, m) {
		cnt[i].snd = i;
	}
	forn(i, n) {
		int pos;
		cin >> pos;
		pos--;
		cnt[pos].fst++;
	}
	sort(cnt, cnt + m);
	tSize = 1;
	while(tSize < m) {
		tSize *= 2;
	}
	
	forn(i, q) {
		ll pos;
		cin >> pos;
		pos--;
		query[i] = mp(pos, i);
	}
	sort(query, query + q);
	int iter = 0;
	ll prev = n, nxt = n;
	int p = 0;
	forn(i, q) {
		ll cur = query[i].fst;
		int ansPos = query[i].snd;
		while(p < m && cur >= nxt) {
			prev = nxt;
			while(p < m && cnt[p].fst == iter) {
				activate(cnt[p].snd);
				p++;
			}
			nxt += tree[1];
			iter++;
		}
		if (cur >= nxt) {
			ans[ansPos] = (cur - nxt) % m;
		} else {
			ans[ansPos] = getK(cur - prev);
		}
	}
	forn(i, q) {
		cout << ans[i] + 1 << "\n";
	}
	return 0;
}