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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

struct Edge
{
    int u,v,w;
    Edge() {}
    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
} edge[100007];

vector<Edge> e[100007];
int n,m,s,d[100007];
bool in[100007];
queue<int> Q;

void bellman(int s)
{
    REP(i,n) in[i] = false, d[i] = 0x7f7f7f7f;
    d[s] = 0;
    Q.push(s);
    in[s] = 1;
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        TR(it,e[now])
            if (d[it->v] > d[now] + it->w)
            {
                d[it->v] = d[now] + it->w;
                if (!in[it->v])
                {
                    in[it->v] = 1;
                    Q.push(it->v);
                }
            }
        in[now] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >>n >> m >> s;
    REP(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i] = Edge(a-1,b-1,c);
        e[a-1].PB(Edge(a-1,b-1,c));
        e[b-1].PB(Edge(b-1,a-1,c));
    }
    int len;
    cin>>len;
    bellman(s-1);
    s = len;
    int answer = 0;
  //  REP(i,n) cout<<d[i]<<endl;
    REP(i,n) if (d[i] == s) ++answer;
    REP(i,m)
    {
        int a1 = 0x7f7f7f7f, a2 = 0x7e7e7e7e;
        a1 = s-d[edge[i].u];
        a2 = (s-d[edge[i].v]);
        if (d[edge[i].u]<s&&d[edge[i].u]+edge[i].w>s && d[edge[i].v]+edge[i].w-a1 >= s) ++answer;
        if (d[edge[i].v]+edge[i].w>s&&d[edge[i].v]<s && d[edge[i].u]+edge[i].w-a2 >= s) ++answer;
        if (d[edge[i].u]<s&&d[edge[i].u]+edge[i].w>s &&
            d[edge[i].v]+edge[i].w-a1 >= s &&
            d[edge[i].v]+edge[i].w>s&&d[edge[i].v]<s &&
            d[edge[i].u]+edge[i].w-a2 >= s &&
            a1+a2==edge[i].w) --answer;

    }
    cout << answer << endl;
    return 0;
}