#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 400;
const int MAXT = 40;
const pii dir[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int n, ni, nj, nd;
int T[MAXT];
int ans;
bool f[MAXT][8][MAXN][MAXN];
bool used[MAXN][MAXN];

int main() {
	
	cin >> n;
	forn(i, n) {
		cin >> T[i];
	}
	
	f[0][0][MAXN / 2][MAXN / 2] = 1;
	for (int t = 0; t < n; t++) {
		forn(d, 8) {
			forn(i, MAXN) {
				forn(j, MAXN) {
					if (f[t][d][i][j]) {
						used[i][j] = 1;
						
						ni = i;
						nj = j;
						for (int step = 0; step < T[t] - 1; step++) {
							ni += dir[d].X;
							nj += dir[d].Y;
							used[ni][nj] = 1; 					
						}
						
						nd = (d + 1) & 7;
						f[t + 1][nd][ni + dir[nd].X][nj + dir[nd].Y] = 1;
						nd = (d + 7) & 7;
						f[t + 1][nd][ni + dir[nd].X][nj + dir[nd].Y] = 1;						
					}
				}
			}
		}
	}
		
	ans = 0;
	forn(i, MAXN) {
		forn(j, MAXN) {
			bool ok = used[i][j];
			ans += ok;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}