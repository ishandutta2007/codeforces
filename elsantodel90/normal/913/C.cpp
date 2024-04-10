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
#define dforn(i,n) for(int i=int(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;


int main() 
{
    #ifdef ACMTUYO
        assert(freopen("c.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tint N;
    while (cin >> N)
    {
        tint L;
        cin >> L;
        
        vector<tint> c(N);
        forn(i,N) cin >> c[i];
        tint cantLast = 1;
        vector<int> utiles = {0};
        int last = 0;
        forsn(i,1,N)
        {
            cantLast *= 2;
            assert(c[last] > 0);
            if (cantLast > c[i] / c[last])
            {
                utiles.push_back(i);
                cantLast = 1;
                last = i;
            }
        }
        tint best = 1100000000000000000;
        tint previousCost = 0;
        dforn(index,utiles.size())
        {
            tint value = 1LL<<utiles[index];
            tint cost = c[utiles[index]];
            best = min(best, previousCost + ((L+value-1) / value) * cost); 
            previousCost += (L/value)*cost;
            L %= value;
        }
        cout << best << endl;
    }
    return 0;
}