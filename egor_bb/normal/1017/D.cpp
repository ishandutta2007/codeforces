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

const int N = 14;
const int M = 1 << N;

int cnt[M], cost[M];
int c[N];
int got[M][101];
int n, m, q;

int to_num(string &s) {
	int x = 0;
	forn(j, n) {
		x = x * 2 + int(s[j] - '0');
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	forn(i, n) cin >> c[n - i - 1];
	forn(i, m) {
		string s;
		cin >> s;
		cnt[to_num(s)]++;
	}
	forn(mask, 1 << n) {
		int sum = 0;
		forn(j, n) {
			if ((1 << j) & mask) sum += c[j];
		}
		cost[mask] = sum;
	}
	int full_mask = (1 << n) - 1;
	forn(main_mask, 1 << n) {
		forn(mask, 1 << n) {
			int diff = full_mask ^ main_mask ^ mask;
			int cs = cost[diff];
			if (cs > 100) continue;
			got[main_mask][cs] += cnt[mask];
		}
		forn(i, 100) {
			got[main_mask][i + 1] += got[main_mask][i];
		}
	}
	forn(i, q) {
		string t;
		int k;
		cin >> t >> k;
		int x = to_num(t);
		cout << got[x][k] << '\n';
	}
	return 0;
}