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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

bool check(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <int> p;
	forab(i, 2, 48) {
		if (check(i))
			p.pb(i);
	}
	forn(i, sz(p))
		cerr << p[i] << ' ';
	cerr << '\n';
	int cnt = 0;
	string s;
	for (int x : p) {
		cout << x << endl;
		cin >> s;
		if (s == "yes")
			cnt++;
	}
	forn(i, 4) {
		cout << p[i] * p[i] << endl;
		cin >> s;
		if (s == "yes") 
			cnt++;
	}
	if (cnt > 1)
		cout << "composite" << endl;
	else
		cout << "prime" << endl;
	
	return 0;
}