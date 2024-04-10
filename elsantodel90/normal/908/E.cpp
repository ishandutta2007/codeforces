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

const int MAXM = 1024;
tint ster[MAXM][MAXM];
tint bell[MAXM];

void initBell()
{
    forn(n,MAXM)
    {
        ster[n][n] = ster[n][1] = 1;
        forsn(k, 2, n)
            ster[n][k] = (ster[n-1][k-1] + (k * ster[n-1][k])%MOD)%MOD;
    }
    forn(i,MAXM)
    forn(j,i+1)
    {
        bell[i] += ster[i][j];
        bell[i] %= MOD;
    }
}

int main() 
{
    initBell();
    #ifdef ACMTUYO
        assert(freopen("e.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    while (cin >> m >> n)
    {
        vector<tint> colMask(m,0);
        forn(i,n)
        {
            string s; cin >> s;
            forn(j,m)
            if (s[j] == '1')
                colMask[j] |= 1LL<<i;
        }
        sort(all(colMask));
        tint ret = 1;
        for (int i=0;i<m;)
        {
            int j=i;
            while (j<m && colMask[j] == colMask[i]) j++;
            ret *= bell[j-i];
            ret %= MOD;
            i = j;
        }
        cout << ret << endl;
    }
    return 0;
}