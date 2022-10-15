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

const int OR_RULE = 0;
const int AND_RULE = 1;
const int NOT_RULE = 2;
const int BASE = 3;

const int TOT = 256;
string bestExp[2][TOT];

#define menor(a,b) (b.empty() || a.length() < b.length() || (a.length() == b.length() && a < b) )

void calc()
{
    forn(i,2)
    forn(j,TOT)
        bestExp[i][j] = "";
    bestExp[0][0x0F] = {"x"};
    bestExp[0][0xF0] = {"!x"};
    bestExp[0][0x33] = {"y"};
    bestExp[0][0xCC] = {"!y"};
    bestExp[0][0x55] = {"z"};
    bestExp[0][0xAA] = {"!z"};
    bool better = true;
    while (better)
    {
        better = false;
        forn(a1,2)
        forn(m1,TOT)
        if (!bestExp[a1][m1].empty())
        {
            int newMask = (~m1)&0xFF;
            string newExp = string("!(") + bestExp[a1][m1] + ")";
            #define mejora(hasOr) menor(newExp, bestExp[hasOr][newMask])
            #define update(hasOr) {bestExp[hasOr][newMask] = newExp; better = true;}
            if (mejora(false))
                update(false);
            forn(a2,2)
            forn(m2,TOT)
            if (!bestExp[a2][m2].empty())
            {
                newMask = m1|m2;
                newExp = bestExp[a1][m1] + "|" + bestExp[a2][m2];
                if (mejora(true))
                    update(true);
                newMask = m1&m2;
                newExp = (a1 ? ("(" + bestExp[a1][m1] + ")") : bestExp[a1][m1]) + "&" + 
                         (a2 ? ("(" + bestExp[a2][m2] + ")") : bestExp[a2][m2]);
                if (mejora(false))
                    update(false);
                
            }
        }
    }
}

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("e.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    calc();
    tint N;
    cin >> N;
    forn(i,N)
    {
        string binary; cin >> binary;
        int val = 0;
        for (char c : binary)
            val = (val*2) + c - '0';
        if (menor(bestExp[0][val],bestExp[1][val]))
            cout << bestExp[0][val] << "\n";
        else
            cout << bestExp[1][val] << "\n";
    }        
    return 0;
}