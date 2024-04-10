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

int main() 
{
    int _sc;
    #ifdef ACMTUYO
        if (!freopen("b.in" ,"r",stdin)) return 1;
    #endif
    int N, iR, iV;
    _sc = scanf("%d%d%d", &N, &iR, &iV);
    const double R = iR, V = iV;
    forn(i,N)
    {
        int si, fi; _sc = scanf("%d%d", &si, &fi);
        const double L = fi - si;
        
        double totalT = 1.0 / 0.0;
        forn(kfactor, 2)
        {
            double tA = max(L / (2*V), (L - 2*R) / V), tB = (L + 2 * R) / V;
            while (0.5 * (tB - tA) / tA > 0.5e-6)
            {
                const double tC = (tB / tA > 2.0) ? sqrt(tA * tB) : (0.5 * (tA + tB));
                const double x = V * tC + 2.0 * R * sin(M_PI * kfactor + 0.5 * V / R * tC);
                if (x < L) tA = tC;
                else tB = tC;
            }
            totalT = min(totalT, (tA + tB) * 0.5);
        }
        printf("%.15lf\n", totalT);
    }
    if (_sc) return 0;
    return 0;
}