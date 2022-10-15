#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)

#define forall(it, c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

using namespace std;

typedef long long tint;

const int MAXN = 512;

tint l[MAXN], c[MAXN];

tint mcd(tint a, tint b){ return (a==0)?b:mcd(b%a, a);}
map<int,tint> dp[MAXN];

const tint INF = 1000000000;

int main() 
{
    #ifdef ACMTUYO
        freopen("b.in","r",stdin);
    #endif
    int n; cin >> n;
    forn(i,n) cin >> l[i];
    forn(i,n) cin >> c[i];
    int res = INF;
    dp[n][0] = 0;
    dforn(x,n+1)
    forall(it, dp[x])
    {
        int d = it->first; int cost = it->second;
        if (d == 1) res = min(res, cost);
        forn(i, x)
        {
            int nd = mcd(l[i], d);
            if (dp[i].find(nd) == dp[i].end())
                dp[i][nd] = INF;
            dp[i][nd] = min(dp[i][nd], cost + c[i]);
        }
    }
    if (res == INF) res = -1;
    cout << res << endl;
    return 0;
}
// END CUT HERE