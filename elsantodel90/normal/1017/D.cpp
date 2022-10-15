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

const int MAX_MASK = 1<<13;
const int MAX_W = 1250;

int totalMask[MAX_MASK];
int histograma[MAX_MASK][MAX_W];
int xorWeight[MAX_MASK];

int getCad()
{
    string cad;
    cin >> cad;
    int num = 0;
    forn(i,cad.size())
        num = 2*num + cad[i] - '0';
    return num;
}

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("d.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M,Q; cin >> N >> M >> Q;
    int w[32];
    forn(i,N) cin >> w[N-1-i];
    forn(cant,M)
    {
        int num = getCad();
        totalMask[num]++;
    }
    forn(mask, 1<<N)
    {
        xorWeight[mask] = 0;
        forn(i,N)
        if (((mask >> i) & 1) == 0)
            xorWeight[mask] += w[i];
        
    }
    forn(baseMask,1<<N)
    if (totalMask[baseMask] > 0)
    {
        forn(otherMask, 1<<N)
            histograma[otherMask][xorWeight[baseMask^otherMask]] += totalMask[baseMask];
    }
    forn(mask,1<<N)
    forsn(we, 1, MAX_W)
        histograma[mask][we] += histograma[mask][we-1];
    forn(i,Q)
    {
        int num = getCad();
        int k; cin >> k;
        cout << histograma[num][k] << "\n";
    }
    return 0;
}