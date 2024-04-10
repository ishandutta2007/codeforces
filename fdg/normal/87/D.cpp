#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

struct edge{
    edge(int _x = 0,int _y = 0,int _num = 0,ll _d = 0) : x(_x), y(_y), num(_num), d(_d) {};
    int x,y,num;
    ll d;
};

bool operator < (const edge & a,const edge & b)
{
    return a.d<b.d||a.d==b.d&&a.num<b.num||a.d==b.d&&a.num==b.num&&a.y<b.y||a.d==b.d&&a.num==b.num&&a.y==b.y&&a.x<b.x;
}

edge edges[100001];
int color[100001]={0},cnt[100001]={0};

int repr(int x)
{
    if (x==color[x]) return x;
    return color[x]=repr(color[x]);
}

void un(int x,int y)
{
    int x1=repr(x),y1=repr(y);
    if (x1!=y1)
    {
        color[x1]=y1;
        cnt[y1]+=cnt[x1];
    }
}

vector <edge> v;
vector <edge> r;
vector < vector <int> > g;
vector <int> used;
int num[100001]={0};
int top[100001]={0};
map <int,int> f,f1;

int dfs(int cur,int tp,int par = -1)
{
    used[cur]=1;
    top[cur]=tp;
    int ret=cnt[repr(f1[cur])];
    for(int i=0;i<g[cur].size();i++)
        if (g[cur][i]!=par) ret+=dfs(g[cur][i],tp,cur);
    return num[cur]=ret;
}

void solve()
{
    vector <int> tmp;
    for(int i=0;i<r.size();i++)
    {
        tmp.push_back(repr(r[i].x));
        tmp.push_back(repr(r[i].y));
    }
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
    f.clear();
    f1.clear();
    for(int i=0;i<tmp.size();i++)
    {
        f[tmp[i]]=i;
        f1[i]=tmp[i];
    }
    int n=tmp.size();
    g.clear();
    g.resize(n);
    for(int i=0;i<r.size();i++)
    {
        r[i].x=f[repr(r[i].x)];
        r[i].y=f[repr(r[i].y)];
        g[r[i].x].push_back(r[i].y);
        g[r[i].y].push_back(r[i].x);
    }
    used.clear();
    used.resize(n,0);
    for(int i=0;i<n;i++)
        if (!used[i]) dfs(i,i);
    for(int i=0;i<r.size();i++)
    {
        int a=min(num[r[i].x],num[r[i].y]),b=num[top[r[i].x]]-a;
        v.push_back(edge(r[i].x,r[i].y,r[i].num,2LL*a*b));
        un(f1[r[i].x],f1[r[i].y]);
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n); n--;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].d);
        edges[i].x--; edges[i].y--; edges[i].num=i+1;
        color[i]=i;
        cnt[i]=1;
    }
    color[n]=n;
    cnt[n]=1;
    sort(edges,edges+n);
    for(int i=0;i<n;i++)
    {
//      ll res=2LL*cnt[repr(edges[i].x)]*cnt[repr(edges[i].y)];
//      v.push_back(edge(edges[i].x,edges[i].y,edges[i].num,res));
//      un(edges[i].x,edges[i].y);
        r.clear();
        r.push_back(edges[i]);
        for(i=i+1;i<n;i++)
            if (edges[i].d==edges[i-1].d) r.push_back(edges[i]);
            else
            {
                i--;
                break;
            }
        solve();
    }
    sort(v.rbegin(),v.rend());
    int kol=1;
    for(int i=1;i<n;i++)
        if (v[i].d==v[0].d) kol++;
        else break;
    cout << v[kol-1].d << " " << kol << endl;
    cout << v[kol-1].num;
    for(int i=kol-2;i>=0;i--)
        printf(" %d",v[i].num);
    printf("\n");
    return 0;
}