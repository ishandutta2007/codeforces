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

const int N = 1005;

set<int> v[N], h[N];
string s[N];

bool checkh(int i, int l, int r) {
	if (l > r)
		swap(l, r);
	auto it = h[i].lower_bound(l);
	return (it == h[i].end() || *it > r);
}


bool checkv(int i, int l, int r) {
	if (l > r)
		swap(l, r);
	auto it = v[i].lower_bound(l);
	return (it == v[i].end() || *it > r);
}

void finish() {
	cout << "YES\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
	int xf, xs, yf, ys;
	forn(i, n) {
		forn(j, m) {
			if (s[i][j] == 'S') {
				ys = i, xs = j;
			} else if (s[i][j] == 'T') {
				yf = i, xf = j;
			} else if (s[i][j] == '*') {
				h[i].insert(j);
				v[j].insert(i);
			}
		}
	}		
	forn(i, m) {
		if (!checkv(i, ys, yf))
			continue;
		if (checkh(ys, xs, i) && checkh(yf, xf, i))
			finish();
	}
	forn(i, n) {
		if (!checkh(i, xs, xf))
			continue;
		if (checkv(xs, ys, i) && checkv(xf, yf, i))
			finish();
	}
	cout << "NO\n";
	return 0;
}