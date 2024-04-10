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

struct pto
{
    int x;
    tdbl y;
    tdbl inter(int otherX, int R)
    {
        if (otherX > x + 2*R ||
            otherX < x - 2*R)
            return 0;
        return y + sqrt(4*R*R - (x-otherX)*(x-otherX));
    }
};

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("c.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int R;
    while (cin >> N >> R)
    {
        vector<pto> centros;
        forn(i,N)
        {
            int x; cin >> x;
            tdbl y = R;
            forn(j,i)
                y = max(y, centros[j].inter(x,R));
            centros.push_back({x, y});
        }
        forn(i, centros.size())
        {
            if (i > 0) cout << " ";
            cout << fixed << setprecision(10) << centros[i].y;
        }
        cout << endl;
    }
    return 0;
}