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
#define next nnnnext

const int N = 1e5 + 100;

int next[N], pos[N];

int main() {
	int n, k;
	int a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	a--, b--, c--, d--;
	if (k <= n || n == 4) {
		puts("-1");
		return 0;
	}
	forn(i, n) {
		next[i] = i;
		pos[i] = i;
	}
	swap(pos[a], pos[0]);
	swap(next[a], next[0]);
	swap(pos[b], pos[next[n - 1]]);
	swap(next[pos[next[n - 1]]], next[n - 1]);
	swap(pos[c], pos[next[1]]);
	swap(next[pos[next[1]]], next[1]);
	swap(pos[d], pos[next[n - 2]]);
	swap(next[pos[next[n - 2]]], next[n - 2]);
	
	forn(i, n) {
		cout << next[i] + 1 << " ";
	}
	cout << '\n';
	
	cout << c + 1 << " " << a + 1 << " ";
	forab(i, 2, n - 2)
		cout << next[i] + 1 << " ";
	cout << b + 1 << " " << d + 1 << '\n';
	return 0;
}