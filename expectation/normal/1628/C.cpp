#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<int> VI;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int i = (a)-1; (i) >= (b); --(i))
#define For(i, a, b) for (int i = (a); i < (b); ++(i))
#define FoR(i, a, b) for (int i = (a)-1; (i) >= (b); --(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000001
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define x first
//#define __float128 long double
#define y second

int n, t;
int a[1000][1000];
int x[1000][1000];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    FOR (tst,0,t) {
        cin >> n;
        int res = 0;
        FOR (i,0,n) FOR (j,0,n) cin >> a[i][j], x[i][j] = 0;
        FOR (i,1,n)
        FOR (j,0,n)
            if (x[i-1][j] == 0) {
                //cout <<i<<" "<<j<<endl;
                res ^= a[i][j];
                FOR (k,0,4) {
                    int nx = i+dx[k], ny = j+dy[k];
                    if (nx >= 0 && ny >= 0 && ny < n && nx < n) x[nx][ny] ^= 1;
                }
            }
        cout << res << "\n";
        //FOR (i,0,n) FOR (j,0,n) cout << x[i][j]; cout << "\n";
    }
}
/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed; cout.precision(10);
    
    cin >> t;
    FOR (tst,0,t) {
        cin >> n;
        FOR (i,0,30) FOR (j,0,30) dp[0][0] = 0;
        bool ok = false;
        FOR (i,0,n) {
            string s;
            cin >> s;
            if (s.size() == 1) {
                dp[0][0] = 0;
            }
            if (s.size() == 2) {
                if (s[0] == s[1]) dp[0][0] = 0;
                FOR ()
            }
            if (s.size() == 3) {
                if (s[0] == s[2]) dp[0][0] = 1;
            }
        }
        if (dp[0][0] != -1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
*/