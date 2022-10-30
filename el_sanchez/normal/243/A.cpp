#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 100500;

int n, a[MAXN];
int nxt[MAXN][22], cur;
int res[MAXN * 22], sz;
int nexts[22];

int main() { 

	memset(nxt, -1, sizeof(nxt));
	cin >> n;
	forn(i, n)
		cin >> a[i];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < 22; j++)
			nxt[i][j] = nxt[i + 1][j];
		for (int j = 0; j < 22; j++)
			if ((a[i + 1] >> j) & 1)
				nxt[i][j] = i + 1;
	}
	
	sz = 0;
	for (int i = 0; i < n; i++) {
		cur = a[i];
		res[sz++] = cur;
		forn(j, 22)
			nexts[j] = (((cur >> j) & 1) ? -1 : nxt[i][j]);
		sort(nexts, nexts + 22);
		int j = 0;
		while (j < 22 && nexts[j] == -1)
			j++;
		while (j < 22) {
			//cerr << i << ' ' << j << endl;
			cur |= a[nexts[j]];
			if (j < 21 && nexts[j] == nexts[j + 1])
				j++;
			else {
			    res[sz++] = cur;
				j++;
			}
		}
	}
	
	sort(res, res + sz);
	sz = unique(res, res + sz) - res;
	cout << sz;
			
	return 0;
}