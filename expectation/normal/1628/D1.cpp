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

int n;
const int C = 2047;
LL d2[C];
LL dp[C][C];

LL mpow(LL a, LL c) {
    LL res = 1;
    while (c) {
        if (c&1) {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        c /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed; cout.precision(10);
    
    d2[1] = 1;
    FOR (i,2,C) d2[i] = (d2[i-1]*2)%mod;
    dp[1][0] = 0;
    dp[1][1] = 1;
    FOR (i,2,C) {
        dp[i][0] = 0;
        dp[i][i] = (i*d2[i])%mod;
        FOR (j,1,i) dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
    }
    int t;
    cin >> t;
    FOR (tst,0,t) {
        int n,m,k;
        cin >> n >> m >> k;
        LL RES = (dp[n][m]*mpow(d2[n],mod-2))%mod;
        cout << (RES*k)%mod << "\n";
    }
    return 0;
}