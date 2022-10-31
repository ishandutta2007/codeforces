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

int a[N], b[N], used[N];
vector <int> pairs[N], delta;
map<int, int> ind;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int p = 0;
	forn(i, n) {
		int x; cin >> x;
		a[i] = x;
		while(x) {
			b[p++] = x;
			x /= 2;
		}
	}
	sort(a, a + n);
	sort(b, b + p);
	p = unique(b, b + p) - b;
	forn(i, p)
		ind[b[i]] = i;
	forn(i, n) {
		int x = a[i];
		while (x) {
			pairs[ind[x]].pb(i);
			x /= 2;
		}
	}
	int l = n - 1, r = p;
	while (r - l > 1) {
		int m = (l + r) / 2;
		memset(used, 0, sizeof(used));
		delta.assign(m, 1);
		fornr(i, m) {
			int size = sz(pairs[i]);
			while(delta[i] <= size) {
				if (!used[pairs[i][size - delta[i]]]) {
					used[pairs[i][size - delta[i]]] = 1;
					delta[i]++;
					break;
				}
				delta[i]++;
			}
		}
		bool ok = true;
		forn(i, n) {
			if (!used[i])
				ok = false;
		}
		if (ok)
			r = m;
		else
			l = m;
	}
	int m = r;
	memset(used, 0, sizeof(used));
	delta.assign(m, 1);
	vector <int> ans;
	fornr(i, m) {
		int size = sz(pairs[i]);
		while(delta[i] <= size) {
			if (!used[pairs[i][size - delta[i]]]) {
				used[pairs[i][size - delta[i]]] = 1;
				delta[i]++;
				ans.pb(b[i]);
				break;
			}
			delta[i]++;
		}
	}
	for(int x : ans)
		cout << x << " ";
	cout << '\n';
	return 0;
}