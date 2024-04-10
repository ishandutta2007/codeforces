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

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const tint MOD = 1000000007;

const int MAX = 710;

const int FREE = 0;
const int COPY = 1;
const int BASE = 10;
tint dp[BASE+1][2][MAX][MAX];
tint pot10[MAX];

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("g.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string number;
    while (cin >> number)
    {
        const int N = int(number.size());
        forn(d,BASE)
        {
            // Al menos cant digitos son >= d
            dp[d][FREE][0][N] = 1;
            dp[d][COPY][0][N] = 1;
            dforn(pos,N)
            forn(cant,N+1)
            {
                const tint cant1 = min(d, number[pos]-'0'); // Los  < d
                const tint cant2 = number[pos]-'0' - cant1; // Los >= d
                dp[d][FREE][cant][pos] = (((BASE-d) * dp[d][FREE][max(0,cant-1)][pos+1]) % MOD + (d * dp[d][FREE][cant][pos+1]) % MOD) % MOD;
                dp[d][COPY][cant][pos] = (dp[d][COPY][max(0, cant - (number[pos]-'0' >= d))][pos+1] + 
                                          (cant1 * dp[d][FREE][cant][pos+1])%MOD +
                                          (cant2 * dp[d][FREE][max(0,cant-1)][pos+1])%MOD) % MOD;
            }
        }
        pot10[0] = 1;
        forn(i,MAX-1)
            pot10[i+1] = (pot10[i]*10)%MOD;
        tint ret = 0;
        forn(i,N)
        forn(d,BASE)
        {
            ret += ((((d * pot10[i]))%MOD) * ((dp[d][COPY][i+1][0] - dp[d+1][COPY][i+1][0])%MOD + MOD)%MOD)%MOD; 
            ret %= MOD;
        }
        cout << ret % MOD << endl;
    }
    return 0;
}