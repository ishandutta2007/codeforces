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

tint MODU = 1000000007;

int main() 
{
    
    #ifdef ACMTUYO
        if (!freopen("b.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int iP,iK;
    while (scanf("%d%d", &iP, &iK) != EOF)
    {
        tint P = iP;
        tint K = iK;
        tint c0 = 1;
        if (K == 1) c0 = P;
        tint main;
        if (K == 0)
        {
            main = 1;
            forn(i,P-1) main = (main * P) % MODU;
        }
        else
        {
            int o = 1;
            tint X = K;
            while (X != 1)
            {
                o++;
                X = (X*K) % P;
            }
            assert((P-1) % o == 0);
            int e = (P-1) / o;
            main = 1;
            forn(i,e) main = (main * P) % MODU;
        }
        int finalRet = (main * c0) % MODU;
        printf("%d\n", finalRet);
    }
    if (_sc) return 0;
    return 0;
}