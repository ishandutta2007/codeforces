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

const int N = 2e6 + 100;

int tree[4 * N], tSize = 1, n;

int get(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl)
		return 0;
	if (l <= vl && vr <= r)
		return tree[v];
	return get(2 * v, vl, (vl + vr) / 2, l, r) + get(2 * v + 1, (vl + vr) / 2, vr, l, r);
}

void add(int v) {
	int pos = v + tSize;
	tree[pos]++;
	pos /= 2;
	while(pos) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
	pos = v + tSize + n;
	tree[pos]++;
	pos /= 2;
	while(pos) {
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n >> k;
	if (n - k < k)
		k = n - k;
	while(tSize < n * 2)
		tSize *= 2;
	int now = 0;
	ll cnt = 1;
	forn(i, n) {
		if (now >= n)
			now -= n;
		int sum = get(1, 0, tSize, now + 1, now + k);
		if (now >= k - 1)
			sum += get(1, 0, tSize, now - k + 1, now);
		else
			sum += get(1, 0, tSize, now - k + n + 1, now + n);
		sum++;
		cnt += sum;
		add(now);
		now += k;
		cout << cnt << " ";
	}
	cout << '\n';
	return 0;
}