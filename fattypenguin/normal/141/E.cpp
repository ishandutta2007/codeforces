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
    int u,v,w,c;
    Edge() {}
    Edge(int u,int v,int w,int c)
    {
        this->u = u;
        this->v = v;
        this->w = w;
        this->c = c;
    }
    Edge* reverse()
    {
        return new Edge(v,u,w,c);
    }
};
bool use[133007];
vector<Edge> e[1007];
vector<Edge> es,et,ee;
int n,m;
char s[20];

int fa[1007];

void init() {REP(i,n) fa[i] = i; }
int get(int u) {return fa[u]==u?u:fa[u]=get(fa[u]); }
void un(int u,int v) {fa[get(u)]=get(v); }
bool same(int u,int v) {return get(u)==get(v); }

bool used[1007];
int path;

int dfs(int u,int v,int now)
{
    if (v == u)
        return path;
    used[u] = true;
    TR(it,e[u])
        if (use[it->w] && !used[it->v])
        {
            int tmp1 = path;
            if (it->c==0) path = it->w;
            int tmp = dfs(it->v,v,now+1);
            if (tmp!=-1) return tmp;
            path = tmp1;
        }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    REP(i,m)
    {
        int a,b,c;
        cin>>a>>b>>s;
        if (s[0] == 'S') ee.PB(Edge(a-1,b-1,i,0)),es.PB(Edge(a-1,b-1,i,0)); else ee.PB(Edge(a-1,b-1,i,1)),et.PB(Edge(a-1,b-1,i,1));
    }
    if (n%2==1)
    {
        init();
        int now = 0;
        CLEAR(use);
        TR(it,es)
        {
            if (same(it->u,it->v)) continue;
            ++now;
            use[it->w] = true;
            un(it->u,it->v);
            e[it->u].PB(*it);
            e[it->v].PB(*it->reverse());
        }
        if (now < n/2) goto sgn;
        int now1 = 0;
        TR(it,et)
        {
            if (same(it->u,it->v)) continue;
            ++now1;
            un(it->u,it->v);
            use[it->w] = true;
            e[it->u].PB(*it);
            e[it->v].PB(*it->reverse());
        }
        if (now + now1 != n-1) goto sgn;
        if (now > now1)
        {
            TR(it,et)
            {
                if (use[it->w]) continue;
                if (now == now1) break;
                CLEAR(used); path = -2;
                int pth = dfs(it->u,it->v,0);
                if (pth < 0) { use[it->w] = false; continue;}
                e[it->u].PB(*it);
                e[it->v].PB(*it->reverse());
                use[it->w] = true;
                use[pth] = false;
                --now; ++now1;
            }
        }
        if (now == now1)
        {
            cout << n-1 << endl;
            bool first = true;
            REP(i,m) if (use[i])
            {
                if (!first) cout << " ";
                first = false;
                cout << i+1;
            }
            cout << endl;
            return 0;
        }
    }
sgn:
    printf("-1\n");
    return 0;
}