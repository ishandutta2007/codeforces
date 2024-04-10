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

const int MAXN = 100000;

vector<int> g[MAXN];

int c[MAXN];
map<int,int> compo;

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("a.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int n,m,k;
    _sc = scanf("%d%d%d", &n, &m, &k);
    vector<int> v(k);
    forn(i,k)
    {
        _sc = scanf("%d", &v[i]);
        v[i]--;
    }
    forn(i,m)
    {
        int x,y;
        _sc = scanf("%d%d", &x, &y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    forn(i,n) c[i] = -1;
    int CS = 0;
    forn(i,n)
    if (c[i] < 0)
    {
        c[i] = CS;
        queue<int> q; q.push(i);
        compo[CS] = 1;
        while (!q.empty())
        {
            int x  = q.front(); q.pop();
            for (int y : g[x])
            if (c[y] < 0)
            {
                c[y] = CS;
                q.push(y);
                compo[CS]++;
            }
        }
        CS++;
    }
    set<int> useful;
    forn(i,n) useful.insert(i);
    tint maxSize = 0;
    tint total = 0;
    forn(i,k)
    {
        int cid = c[v[i]];
        useful.erase(cid);
        maxSize = max(maxSize, tint(compo[cid]));
        total += (tint(compo[cid]) * (tint(compo[cid]) - 1)) / 2;
    }
    total -= (maxSize * (maxSize-1)) / 2;
    for (int x : useful)
        maxSize += compo[x];
    total += (maxSize * (maxSize-1)) / 2;
    total -= m;
    cout << total << "\n";
    if (_sc) return 0;
    return 0;
}