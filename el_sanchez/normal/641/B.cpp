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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 111;

int n, m, q;
pii a[MAXN][MAXN];
int res[MAXN][MAXN];
int id, p, r, x;

int main() {

	scanf("%d%d%d", &n, &m, &q);
	
	forn(i, n)
		forn(j, m)
			a[i][j] = {i, j};
			
	forn(i, q) {
		scanf("%d", &id);
		if (id == 1) {
			scanf("%d", &p);
			p--;
			
			pii tmp = a[p][0];
			for (int j = 0; j < m - 1; j++)
				a[p][j] = a[p][j + 1];
			a[p][m - 1] = tmp;
		} else if (id == 2) {
			scanf("%d", &p);
			p--;
			
			pii tmp = a[0][p];
			for (int j = 0; j < n - 1; j++)
				a[j][p] = a[j + 1][p];
			a[n - 1][p] = tmp;
		} else {
			scanf("%d%d%d", &p, &r, &x);
			p--, r--;
			res[a[p][r].X][a[p][r].Y] = x;	
		}
	}                                     		
	
	forn(i, n)
		forn(j, m)
			printf("%d%c", res[i][j], " \n"[j == m - 1]);
	return 0;
}