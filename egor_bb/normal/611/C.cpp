#include <bits/stdc++.h>                          

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef unsigned int uint;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int MAXN = int(3e2) + 10;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 
#define problem "test"
                            
      
const int N = (5e2) + 100;
const int magic = 1000;


int n, m;
string s[N];
ll dp[N][N];

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
	forab(i, 1, n + 1){
		forab(j, 1, m + 1){
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]; 
			if (s[i - 1][j - 1] == '.' && (i > 1 && s[i - 2][j - 1] == '.')) dp[i][j]++;
			if (s[i - 1][j - 1] == '.' && (j > 1 && s[i - 1][j - 2] == '.')) dp[i][j]++;
		//	cout << dp[i][j] <<  " " ;
		}
	//	cout << '\n';
	}	
	int q; cin >> q;
	while (q--){
		int x, y, xx, yy; cin >> x >> y >> xx >> yy;
		--x; --y;
		ll ans = dp[xx][yy] - dp[xx][y] - dp[x][yy] + dp[x][y];  
		if (x > 0){
			for (int i = y; i < yy; ++i){
				if (s[x][i] == '.' && s[x - 1][i] == '.') ans--;	
			}
		}
		if (y > 0){
			for (int i = x; i < xx; ++i){
				if (s[i][y - 1] == '.' && s[i][y] == '.') ans--;	
			}
		}
		cout << ans << '\n';
	}
}