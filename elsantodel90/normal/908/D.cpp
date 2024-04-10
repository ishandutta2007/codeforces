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
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;
typedef long double tdbl;

const tint MOD = 1000000007;

tint potlog(tint A, tint B)
{
    tint ret = 1;
    while (B != 0)
    {
        if (B%2) ret = (ret*A)%MOD;
        A = (A*A)%MOD;
        B /= 2;
    }
    return ret;
}

tint inverse(tint X)
{
    return potlog(X, MOD-2);
}

const int MAX = 1024;

tint dp[MAX][MAX];

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("d.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tint K,Pa,Pb;
    while (cin >> K >> Pa >> Pb)
    {
        
        const tint cPa = (Pa * inverse(Pa+Pb))%MOD;
        const tint cPb = (Pb * inverse(Pa+Pb))%MOD;
        forn(i,K+1)
            dp[i][i] = ((i-1 + ((Pa+Pb)*inverse(Pb))%MOD)%MOD+MOD)%MOD;
        forn(k,K+1)
        dforsn(a,1,k)
        {
            if (k-a < a)
                dp[k][a] = ((cPb * ((a + (a - (k-a)) + dp[k-a][k-a])%MOD))%MOD + (cPa * dp[k][a+1])%MOD)%MOD;
            else
                dp[k][a] = ((cPb * ((a + dp[k-a][a])%MOD))%MOD + (cPa * dp[k][a+1])%MOD)%MOD;
        }
        cout << dp[K][1] % MOD << endl;
    }
    return 0;
}