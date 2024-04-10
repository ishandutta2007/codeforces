#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

typedef pair<int,pair<int,int> > gType;

int value[1007];
gType BIT[1007];
int a[507],b[507];
gType f[507][507];
gType g[507][507];
int n,m;
int total = 0;
map<int,int> has;

#define lb(x) (x&-x)

gType max(gType a,gType b) {return a > b ? a : b;}

void I(int where,gType value)
{
    ++where;
    while (where <= total)
    {
        BIT[where] = max(BIT[where],value);
        where += lb(where);
    }
}

gType Q(int where)
{
    if (where < 0)
    {
        return MP(0,MP(-1,-1));
    }
    gType ret = MP(0,MP(-1,-1));
    ++where;
    while (where)
    {
        ret = max(ret,BIT[where]);
        where -= lb(where);
    }
    return ret;
}

void init_BIT()
{
    REP(i,total+5) BIT[i] = MP(0,MP(-1,-1));
}

int main()
{
    cin >> n;
    total = 0;
    has.clear();
    REP(i,n)
    {
        cin >> a[i];
        has[a[i]] = 1;
    }
    cin >> m;
    REP(i,m)
    {
        cin >> b[i];
        has[b[i]] = 1;
    }
    TR(it,has)
    {
        value[total] = it->first;
        it->second = total++;
    }
    CLEAR(f);
    CLEAR(g);
    int ans = 0;
    pair<int,int> where = MP(-1,-1);
    REP(i,m)
    {
        g[0][i] = MP(0,MP(-1,-1));
        if (b[i]==a[0]) f[0][i] = MP(1,MP(-1,-1)),g[0][i] = MP(1,MP(0,i));
        if (f[0][i].first > ans)
            ans = f[0][i].first,
            where = MP(0,i);
    }
    for (int i = 1;i < n;++i)
    {
        init_BIT();
        for (int j = 0;j < m;++j)
        {
            if (a[i]==b[j])
            {
                f[i][j] = Q(has[a[i]]-1);
                ++f[i][j].first;
            }
            if (f[i][j].first > g[i-1][j].first)
                g[i][j] = MP(f[i][j].first,MP(i,j));
            else
                g[i][j] = g[i-1][j];
            I(has[b[j]],g[i-1][j]);
            if (f[i][j].first > ans)
            {
                where = MP(i,j);
                ans = f[i][j].first;
            }
        }
    }
    vector<int> res;
    while (-1 != where.first)
    {
        res.PB(a[where.first]);
        where = f[where.first][where.second].second;
    }
    cout << ans << endl;
    REP(i,res.size())
    {
        if (i) cout << " ";
        cout << res[ans-1-i];
    }
    return 0;
}