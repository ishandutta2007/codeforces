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

const int N = 4;
const int M = 2005;

int a[N][M];
int tmp[N];

int n, m;

int dp[M][1 << N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	forn(tt, t) {
		cin >> n >> m;
		forn(i, n) {
			forn(j, m) {
				cin >> a[i][j];	
			}	
		}
		forn(i, 1 << n) {
			forn(j, m + 1) {
				dp[j][i] = 0;
			}
		}

		forn(i, m) {
			forn(rep, n) {
				forn(t, n) {
					tmp[t] = a[(t + 1) % n][i];
				}
				forn(t, n) {
					a[t][i] = tmp[t];
				}
			
				forn(mask, 1 << n) {
					forn(subMask, 1 << n) {
						if ((subMask & mask) != subMask) continue;
						int sum = 0;
						forn(j, n) {
							if ((1 << j) & subMask) {
								sum += a[j][i];
							}
						}
						dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask ^ subMask] + sum);
					}
				}
			}
		}
		cout << dp[m][(1 << n) - 1] << '\n';
	}
	return 0;
}