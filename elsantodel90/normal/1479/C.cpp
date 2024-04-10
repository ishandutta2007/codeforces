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

struct Edge
{
    int a,b;
    int c;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L,R;
    cin >> L >> R;
    const int tam = R-L;
    
    cout << "YES\n";
    
    vector<Edge> edges;
    
    int n = 1;
    
    int nextPow = 1;
    while (tam > nextPow / 2)
    {
        edges.push_back({n,0,1});
        int pot = 1;
        forn(i,n-1)
        {
            edges.push_back({n,i+1,pot});
            pot *= 2;
        }
        n++;
        nextPow *= 2;
    }
    
    edges.push_back({n,0,L});
    
    int base = L;
    forn(bitIndex, 30)
    if ((tam >> bitIndex) & 1)
    {
        assert(bitIndex+1 < n);
        edges.push_back({n,bitIndex+1,base});
        base += 1<<bitIndex;
    }
    
    n++;
    
    cout << n << " " << edges.size() << "\n";
    
    
    for (Edge p : edges)
        cout << n-p.a << " " << n-p.b << " " << p.c << "\n";
    
    return 0;
}