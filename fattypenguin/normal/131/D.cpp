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
#include <cassert>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
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

bool u(char x) {return x>='A'&&x<='Z';}

vector<int> e[3007],ch[3007];
bool v[3007],c[3007];
int n,d[3007],fa[3007];
int an[3007];
queue<int> Q;

void gao(int u,int d)
{
    an[u]=d;
    TR(it,ch[u])
        if (c[*it])
            gao(*it,d+1);
}

int wh=-1;

void finds(int u,int Fa)
{
    v[u]=true;
    TR(it,e[u])
    if(*it!=Fa)
    {
        if (v[*it])
            wh = *it;
        else finds(*it,u);
    }
}

void dfs(int u,int Fa)
{
 //   cout<<u<<" "<<Fa<<endl;
    if (v[u])
    {
     //   cout<<u<<" "<<Fa<<endl;
        assert(u==wh);
        fa[wh]=Fa;
        return;
    }
    v[u]=true;
    fa[u]=Fa;
    TR(it,e[u])
        if (*it!=Fa && (!v[*it]||*it==wh))
        {
            ch[u].PB(*it);
            dfs(*it,u);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    CLEAR(v);
    REP(u,n) ch[u].clear(),e[u].clear();
    REP(i,n) {int x,y;cin>>x>>y;--x;--y;e[x].PB(y);e[y].PB(x);}
    finds(0,-1);
    CLEAR(v);
    assert(wh!=-1);
    dfs(wh,-1);
    while (Q.size()) Q.pop();
    CLEAR(d);
    REP(i,n) if(fa[i]>=0) ++d[fa[i]]; else assert(false);
    REP(i,n) if(!d[i]) Q.push(i);
    CLEAR(c);
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        c[now]=true;
        --d[fa[now]];
        if (!d[fa[now]]) Q.push(fa[now]);
    }
    CLEAR(an);
    REP(i,n) if (!c[i]) {gao(i,0);}
    REP(i,n)
    {
        if (i) cout<<" ";
        cout<<an[i];
    }
    cout<<endl;
    return 0;
}