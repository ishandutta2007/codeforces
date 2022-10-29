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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
                                     
int n;
string s[MAXN], ans[MAXN];
bool used[MAXN][MAXN];
bool fig[MAXN][MAXN];

int main() {
                
	cin >> n;
	forn(i, n)
		cin >> s[i];
	
	forn(i, n)
		forn(j, n)
			if (s[i][j] == 'o')
				fig[i][j] = 1;
				
	for (int i = -n + 1; i <= n - 1; i++)
		for (int j = -n + 1; j <= n - 1; j++) {
			ans[i + n - 1] += '.';

			//try
			bool ok = 1;
			forn(i1, n)
				forn(j1, n) {
					int i2 = i1 + i;
					int j2 = j1 + j;
					if (fig[i1][j1]) {
						if (i2 < 0 || n <= i2 || j2 < 0 || n <= j2)
							continue;
						if (s[i2][j2] == '.') {
							ok = 0;
							break;
						}
					}
				}								
			if (!ok)
				continue;
			forn(i1, n)
				forn(j1, n) {
					int i2 = i1 + i;
					int j2 = j1 + j;
					if (fig[i1][j1]) {
						if (i2 < 0 || n <= i2 || j2 < 0 || n <= j2)
							continue;
						used[i2][j2] = 1;
					}
				}
			
			if (i == 0 && j == 0)
				ans[i + n - 1][j + n - 1] = 'o';
			else
				ans[i + n - 1][j + n - 1] = 'x';	
		}
	
	forn(i, n)
		forn(j, n)
			if (s[i][j] == 'x' && !used[i][j]) {
				cout << "NO";
				return 0;
			}
			
	cout << "YES\n";
	forn(i, 2 * n - 1)
		cout << ans[i] << '\n';
	
	return 0;
}