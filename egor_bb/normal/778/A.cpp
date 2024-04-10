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

int p[N], a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = sz(s);
	forn(i, n)
		cin >> p[i];
	forn(i, n)
		a[p[i] - 1] = i + 1;
	int l = 0, r = n;	
	while(r - l > 1) {
		int m = (l + r) / 2;
		int now = 0;
		forn(i, n) {
			if (a[i] > m && now < sz(t) && s[i] == t[now])
				now++;
		}
		if (now == sz(t))
			l = m;
		else
			r = m;
	}	
	cout << l << '\n';	
	return 0;
}