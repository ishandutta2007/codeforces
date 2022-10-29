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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-11;
const int INF = 1E9;
const ll LINF = 1E18;     
const int MAXN = 111;

int n, m, ans;
string s[MAXN];
ll a[MAXN][MAXN], v;

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
	forn(i, n)
		forn(j, m)
			if (s[i][j] == 'B')
				a[i][j] = -1;
			else
				a[i][j] = 1;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (a[i][j] == 0)
				continue;

			v = a[i][j];
			forn(k, i + 1)
				forn(l, j + 1)
					a[k][l] -= v;
			//cout << v << '\n';
			assert(v <= LINF);
			ans++;		
		}
	}
	cout << ans;
	return 0;
}