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

const int MAXN = 1000000;

int v[MAXN], dp[MAXN], where[MAXN];

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("a.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    while (scanf("%d", &N) != EOF)
    {
        forn(i,N)
        {
            _sc = scanf("%d", &v[i]);
            v[i]--;
        }
        forn(i,N+1) where[i] = N;
        int best = 0;
        dp[N] = 0;
        dforn(i,N)
        {
            dp[i] = 1+dp[where[v[i]+1]];
            best = max(best, dp[i]);
            where[v[i]] = i;
        }
        printf("%d\n", N - best);
    }
    if (_sc) return 0;
    return 0;
}