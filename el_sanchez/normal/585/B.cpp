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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int T, n, k;
string s[3];
int a[3][MAXN], dp[3][MAXN];

int main() {
	
	cin >> T;
	forn(tt, T) {
		cin >> n >> k;
		forn(i, 3)
			cin >> s[i];
		forn(i, 3)
			forn(j, n + 10) {
				a[i][j] = 0;
				dp[i][j] = 0;
			}
			
		forn(i, 3)
			forn(j, n)
				if ('A' <= s[i][j] && s[i][j] <= 'Z')
					a[i][j] = 1;

		forn(i, 3)
			if (s[i][0] == 's')
				dp[i][0] = 1;
				
		forn(i, n + 3)
			forn(j, 3)
				if (dp[j][i]) {
					if (!a[j][i] && !a[j][i + 1] && !a[j][i + 2] && !a[j][i + 3])
						dp[j][i + 3] = 1;
					if (j != 2)
						if (!a[j][i] && !a[j][i + 1] && !a[j + 1][i + 1] && !a[j + 1][i + 2] && !a[j + 1][i + 3])
							dp[j + 1][i + 3] = 1;
					if (j != 0)
						if (!a[j][i] && !a[j][i + 1] && !a[j - 1][i + 1] && !a[j - 1][i + 2] && !a[j - 1][i + 3])
							dp[j - 1][i + 3] = 1;
						
				}

		bool ans = 0;
		forn(j, 3)
			for (int i = n; i <= n + 8; i++)	
				if (dp[j][i])
					ans = 1;
		cout << (ans ? "YES\n" : "NO\n");
	}

	return 0;
}