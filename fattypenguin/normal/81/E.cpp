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

PII operator + (const PII &a,const PII &b)
{
    return MP(a.first+b.first,a.second+b.second);
}

int from[200007],n;
PII p[200007];
vector<int> ch[200007];
PII F[200007][2];
bool vis[200007];

void fuck(int u)
{
    vis[u] = true;
    F[u][0] = F[u][1] = MP(0,0);
    from[u] = -1;
    TR(it,ch[u]) fuck(*it);
    TR(it,ch[u])
    {
        F[u][1] = F[u][1] + max(F[*it][0],F[*it][1]);
        PII delt = MP(1,(p[u].second!=p[*it].second));
        if (F[u][0]+F[*it][0]+delt > F[u][1])
        {
            F[u][1] = F[u][0]+F[*it][0]+delt;
            from[u] = *it;
        }
        F[u][0] = F[u][0]+max(F[*it][0],F[*it][1]);
    }
}

vector<PII> ansi;
vector<PII> res;

void gaogao(int u,bool can)
{
    TR(it,ch[u])
        if (*it == from[u] && !can && !(F[u][1]<F[u][0]))
        {
            res.PB(MP(u,*it));
            gaogao(*it,true);
        }
        else gaogao(*it,false);
}

PII ans = MP(0,0);

void gao(int u)
{
    int v = u;
    while (!vis[v])
    {
        vis[v] = true;
        v = p[v].first;
    }
    PII tmp = MP(0,0);
    REP(rep,2)
    {
        int w = p[v].first;
        ch[w].erase(find(ALL(ch[w]),v));
        fuck(v);
        if (max(F[v][0],F[v][1])>tmp)
        {
            tmp = max(F[v][0],F[v][1]);
            res.clear();
            gaogao(v,false);
        }
        ch[w].PB(v);
        v = w;
    }
    ans = ans + tmp;
    TR(it,res) ansi.PB(*it);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    CLEAR(vis);
    REP(i,n)
    {
        cin >> p[i].first >> p[i].second;
        --p[i].first;
        ch[p[i].first].PB(i);
    }
    ans=MP(0,0);
    REP(i,n) if (!vis[i]) gao(i);
    cout << ans.first << " " << ans.second << endl;
    TR(it,ansi) cout << it->first+1 << " " << it->second+1 << endl;
    return 0;
}