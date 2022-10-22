#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct suff_array {
  const int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
  suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
    for (i = 0; i < L-(L==1); i++) P[0][i] = int(s[i]);
    for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
      P.push_back(vi(L, 0));
      for (int i = 0; i < L; i++)
        M[i] = {{P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000}, i};
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
        P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?
            P[lvl][M[i-1].second] : i; } }
  const vi& get_sarray() { return P.back(); }
  //returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
  int lcp(int i, int j) {
    int len = 0; if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
      if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1 << k; }
    return len; }
};

const int N = 3e3+1;
ll tot[N][N]; // id, == len

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	int v[n+1];
	string s;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
		s.push_back(v[i]);
	}
	reverse(s.begin(), s.end());
	suff_array sa(s);

	set<int> bad;
	bad.insert(0b0011);
	bad.insert(0b0101);
	bad.insert(0b1110);
	bad.insert(0b1111);

	auto match = [&] (int id, int len, int bm) {
		if (len > id) return false;
		for (int i=0; i<len; i++) {
			if (v[id-i] != (bm>>i&1)) {
				return false;
			}
		}
		return true;
	};

	ll ans = 0;
	tot[0][0] = 1;
	for (int i=1; i<=n; i++) {
		int maxv = 0;
		for (int j=1; j<i; j++) {
			maxv = max(maxv, sa.lcp(n-i,n-j));
		}
		//cerr << i << " -> lcp: " << maxv << nl;

		tot[i][0] = 1;
		for (int j=1; j<=4; j++) {
			for (int bm=0; bm<1<<j; bm++) {
				if (j==4 && bad.count(bm)) continue;
				if (match(i,j,bm)) {
					for (int len=j; len<=i; len++) {
						tot[i][len] = (tot[i][len] + tot[i-j][len-j]) % MOD;
					}
					break;
				}
			}
		}

		for (int len=maxv+1; len<=i; len++) {
			ans = (ans + tot[i][len]) % MOD;
		}
		cout << ans << nl;
	}

	return 0;
}