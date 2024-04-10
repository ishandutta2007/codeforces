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

const int N = 2e5 + 100;

vector <pii> v;
int a[N], last[N];

bool emul(int c) {
	int p = last[c];
	while(p != -1 && c > 0) {
		int k = c / v[p].fst;
		c -= v[p].fst * min(v[p].snd, k);
		p = min(last[c], p - 1);
	}
	return c == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c; cin >> c;
	int n; cin >> n;
	forn(i, n) {
		cin >> a[i];
	}	
	sort(a, a + n);
	v.pb(mp(a[0], 0));
	forn(i, n) {
		if (v.back().fst != a[i])
			v.pb(mp(a[i], 0));
		v.back().snd++;
	}
	int p = sz(v) - 1;
	fornr(i, c + 1) {
		while(p >= 0 && v[p].fst > i)
			p--;
		last[i] = p;
	}
	p = sz(v) - 1;
	int mn = 1e9;
	fornr(add, c) {
		while(p >= 0 && v[p].fst > add) {
			while(c >= v[p].fst && v[p].snd)
				c -= v[p].fst, v[p].snd--;	
			p--;	
		}
		if (add > c)
			continue;
		if (!emul(c - add)) {
			mn = min(add, mn);
		}
	}
	if (mn < 1e9)
		cout << mn << '\n';
	else
		cout << "Greed is good\n";
	return 0;
}