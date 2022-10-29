//#define _GLIBCXX_DEBUG
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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 1111111;
    
int n, k, ans;
int dp[MAXN];
int a[MAXN];

int main() {

    scanf("%d", &n);
    forn(i, n) {
    	scanf("%d", &k);
    	a[k]++;
    }
    
    ans = 0;
    for (int i = 1; i < MAXN; i++) {
    	dp[i] = max(dp[i], a[i]);
    	ans = max(ans, dp[i]);
    	for (int k = i * 2; k < MAXN; k += i) 
    		if (a[k] > 0)
    			dp[k] = max(dp[k], dp[i] + a[k]);	
    }
	
    cout << ans;
    
	return 0;
}