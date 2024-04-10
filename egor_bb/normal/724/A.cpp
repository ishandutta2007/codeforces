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

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string a[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int d1, d2;
	forn(i, 7) {
		if (s == a[i])
			d1 = i;
		if (t == a[i])
			d2 = i;
	}
	forn(i, 11) {
		if ((d1 + days[i]) % 7 == d2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	
		
	return 0;
}