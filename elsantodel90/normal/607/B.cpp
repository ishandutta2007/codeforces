#include <cstdio>
#include <cstdlib>
#include <cassert>
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
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;
typedef pair<int,int> pint;

const int MAXN = 1024;

int v[MAXN];

int dp[MAXN][MAXN];

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("b.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    while (scanf("%d", &N) != EOF)
    {
        forn(i,N) _sc = scanf("%d", &v[i]);
        forn(i,N+1) {dp[i][i] = 0; dp[i][i+1] = 1;}
        dforn(i,N)
        forsn(j, i+2, N+1)
        {
            int &ret = dp[i][j] = j-i;
            ret = min(ret, 1 + dp[i+1][j]);
            forsn(k, i+1, j)
            if (v[k] == v[i])
                ret = min(ret, dp[k+1][j] + dp[i+1][k] + (k-(i+1) == 0));
        }
        printf("%d\n", dp[0][N]);
    }
    if (_sc) return 0;
    return 0;
}