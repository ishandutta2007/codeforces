#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e4+1;
string grid[N];
int row[N], col[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		For(i,n) {
			cin >> grid[i];
			row[i] = 0;
			For(j,m) {
				row[i] += (grid[i][j]=='.');
			}
		}
		For(j,m) {
			col[j] = 0;
			For(i,n) {
				col[j] += (grid[i][j]=='.');
			}
		}
		int ans = INF;
		For(i,n) {
			For(j,m) {
				ans = min(ans, row[i]+col[j]-(grid[i][j]=='.'));
			}
		}
		cout << ans << nl;
	}

	return 0;
}