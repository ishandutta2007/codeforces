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
 
const int N = 1e6 + 100;
const int MOD = 1e9 + 7;
 
vector<pii> g[N];
int d[N], len[N], minD[N], pwr10[N], totalV = 0;
 
int added[N];
int ans[N];
int bs, be;
vector<int> buckets[N];
 
int mul(int a, int b) {
	return int((a * 1ll * b) % MOD);
}
 
int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}
 
vector<int> toDigits(int x) {
	vector<int> digits;
	while(x) {
		digits.pb(x % 10);
		x /= 10;
	}
	reverse(all(digits));
	return digits;
}
 
void addEdge(int v, int u, vector<int>& digits, bool print) {
	int pos = 0;
	while (pos + 1 != sz(digits)) {
		g[v].pb(mp(totalV, digits[pos]));
		v = totalV;
		totalV++;
		pos++;
	}
	g[v].pb(mp(u, digits.back()));
}
 
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forab(i, 0, 10) len[i] = 1;
	forab(i, 10, 100) len[i] = 2;
	forab(i, 100, 1000) len[i] = 3;
	forab(i, 1000, 10000) len[i] = 4;
	forab(i, 10000, 100000) len[i] = 5;
	forab(i, 100000, 1000000) len[i] = 6;
	
	pwr10[0] = 1;
	forab(i, 1, N) {
		pwr10[i] = mul(pwr10[i - 1], 10);
	}
	
	int n, m;
	cin >> n >> m;
	totalV = n;
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		vector<int> digits = toDigits(i + 1);
		addEdge(v, u, digits, true);
		addEdge(u, v, digits, false);
	}
	
	added[0] = 1;
	vector<int> BS;
	BS.pb(0);
	buckets[be++] = BS;
	while(bs < be) {
		vector<int> bucket = buckets[bs++];
		vector<int> nextBucket[10];
		forn(i, 10) nextBucket[i] = vector<int>(0);
 
		forn(dig, 10) {
			for (int v : bucket) {
				for (pii tod : g[v]) {
					int digit = tod.snd;
					if (digit != dig) continue;
					int to = tod.fst;
					if (!added[to]) {
						added[to] = 1;
						nextBucket[digit].pb(to);
						ans[to] = add(mul(ans[v], 10), digit);
					}
				}
			}
		}
		forn(i, 10) {
			if (sz(nextBucket[i]) > 0) {
				buckets[be++] = nextBucket[i];
			}
		}
	}
	forab(i, 1, n) {
		cout << ans[i] << '\n';
	}
	return 0;
}