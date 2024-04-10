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
const int INF = 1E9;
const int MAXN = 128;

int n, x;
ld p[MAXN], a[MAXN][MAXN], b[MAXN][MAXN], v[MAXN], w[MAXN];

int main() {
	
	cin >> n >> x;
	forn(i, x + 1)
		cin >> p[i];
	
	memset(v, 0, sizeof(v));
	v[0] = 1;
	forn(i, MAXN)
		forn(j, MAXN)
			a[i][j] = p[j ^ i];
		
	while (n > 0) {
		if (n & 1) {
			forn(i, MAXN)
				w[i] = v[i];
			forn(i, MAXN) {
				v[i] = 0;
				forn(j, MAXN)
					v[i] += a[i][j] * w[j];
			}
		}
		
		forn(i, MAXN)
			forn(j, MAXN)
				b[i][j] = a[i][j];
				
		forn(i, MAXN)
			forn(j, MAXN) {
				a[i][j] = 0;
				forn(k, MAXN)
					a[i][j] += b[i][k] * b[k][j];	
			}

		n >>= 1;			
	}
	
	cout.precision(20);
	cout << (ld)1.0 - v[0] << '\n';
	return 0;
}