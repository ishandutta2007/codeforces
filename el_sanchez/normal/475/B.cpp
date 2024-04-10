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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 411;

int n, m, V;
string s;
int g[MAXN][MAXN];

int get(int a, int b) {
	return a * m + b;	
}

int main() {

	cin >> n >> m;
	V = n * m;
	
	cin >> s;
	forn(i, n) {
		forn(j, m - 1)
			if (s[i] == '>') {
				g[get(i, j)][get(i, j + 1)] = 1;
			} else {
				g[get(i, j + 1)][get(i, j)] = 1;
			}
	}
	
	cin >> s;
	forn(j, m) {
		forn(i, n - 1)
			if (s[j] == 'v') {
				g[get(i, j)][get(i + 1, j)] = 1;
			} else {
				g[get(i + 1, j)][get(i, j)] = 1;
			}
	}
	
	forn(i, V)
		g[i][i] = 1;
		
	forn(k, V)
		forn(i, V)
			forn(j, V)
				g[i][j] |= (g[i][k] & g[k][j]);
				
	forn(i, V)
		forn(j, V)
			if (!g[i][j]) {
				cout << "NO\n";
				return 0;
			}
			
	cout << "YES\n";
	
	return 0;
}