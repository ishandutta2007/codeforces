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

int n[3];
double dp[MAXN][MAXN][MAXN];
double answer[3];

int main() {
                              
    forn(i, 3)
    	cin >> n[i];
    dp[n[0]][n[1]][n[2]] = 1;

    for (int i = n[0]; i >= 0; i--)
    	for (int j = n[1]; j >= 0; j--)
    		for (int k = n[2]; k >= 0; k--) {
    			if ((i != 0) + (j != 0) + (k != 0) <= 1)
    				continue;
    				
    			double S = i * j + j * k + k * i;
    			if (i > 0 && j > 0)
    				dp[i][j - 1][k] += double(i * j) * dp[i][j][k] / S;
    			if (j > 0 && k > 0)
    				dp[i][j][k - 1] += double(k * j) * dp[i][j][k] / S;
    			if (k > 0 && i > 0)
    				dp[i - 1][j][k] += double(k * i) * dp[i][j][k] / S;     				
    		}
    for (int i = 1; i <= n[0]; i++)
    	answer[0] += dp[i][0][0];
    for (int i = 1; i <= n[1]; i++)
    	answer[1] += dp[0][i][0];
    for (int i = 1; i <= n[2]; i++)
    	answer[2] += dp[0][0][i];
    
   	cout.precision(20);
   	forn(i, 3)
   		cout << answer[i] << ' ';    
    return 0;
}