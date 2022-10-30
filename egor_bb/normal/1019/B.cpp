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


int ask(int pos) {
	cout << "? " << pos << endl;
	int x; cin >> x;
	return x; 
}

int finish(int pos) {
	cout << "! " << pos << endl;
	exit(0);
}

bool intersect(int l1, int r1, int l2, int r2) {
	if (l1 < l2) {
		return r1 > r2;
	} else {
		return r2 > r1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int p1 = ask(1), p2 = ask(1 + n / 2);
	if (p1 == p2) finish(1);
	int l1 = 1, r1 = 1 + n / 2, l2 = 1 + n / 2, r2 = n + 1;
	int pl1 = p1, pr1 = p2, pl2 = p2, pr2 = p1;
	while(1) {
		int addition = (r1 - l1) / 2;
		if (addition == 0) break;
		p1 = ask(l1 + addition);
		p2 = ask(l2 + addition);
		if (p1 == p2) finish(l1 + addition);
		if (intersect(pl1, p1, pl2, p2)) {
			r1 = l1 + addition;
			r2 = l2 + addition;
			pr1 = p1;
			pr2 = p2;
		} else {
			l1 = l1 + addition;
			l2 = l2 + addition;
			pl1 = p1;
			pl2 = p2;
		}
	}
	finish(-1);
	return 0;
}