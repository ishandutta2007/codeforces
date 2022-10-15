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

const int MAXN = 1000000;

pint v[MAXN];

int dp[MAXN];

#define a first
#define b second

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("a.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    while (scanf("%d", &N) != EOF)
    {
        forn(i,N) _sc = scanf("%d%d", &v[i].a, &v[i].b);
        sort(v, v+N);
        forn(i,N)
        {
            int K = v[i].a - v[i].b;
            int a = -1, b = i;
            while (b-a > 1)
            {
                int c = (a+b)/2;
                if (v[c].a >= K)
                    b = c;
                else
                    a = c;
            }
            dp[i] = i - b;
            if (a >= 0) dp[i] += dp[a];
        }
        int best = N;
        forn(i,N) best = min(best, dp[i] + N-1-i);
        printf("%d\n", best);
    }
    if (_sc) return 0;
    return 0;
}