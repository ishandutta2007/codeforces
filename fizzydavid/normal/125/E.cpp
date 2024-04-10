#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct DSU
{
    int f[5111];
    void init()
    {
        for(int i=1;i<=5000;i++)
            f[i]=i;
    }
    int gf(int x)
    {
        if(x==f[x])
            return x;
        return f[x]=gf(f[x]);
    }
    bool un(int x,int y)
    {
        x=gf(x),y=gf(y);
        if(x==y)
            return true;
        f[x]=y;
        return false;
    }
}dsu;
int n,m,k;
struct edge
{
    int u,v,id;
    double c;
    bool operator<(const edge&tmp)const
    {
        return c<tmp.c;
    }
};
edge make_edge(int u,int v,int c,int id)
{
    edge tmp;tmp.u=u;tmp.v=v;tmp.c=c;tmp.id=id;
    return tmp;
}
bool cmp(const edge &x,const edge &y)
{
    return x.id<y.id;
}
vector<edge>E;
vector<int>ans;
int check(double v)
{
    for(int i=0;i<E.size();i++)
        if(E[i].u==1||E[i].v==1)
            E[i].c+=v;
    sort(E.begin(),E.end());
    dsu.init();
    ans.clear();
    int cnt=0;
    for(int i=0;i<E.size();i++)
    {
        if(dsu.un(E[i].u,E[i].v))
            continue;
        ans.PB(E[i].id);
        if(E[i].u==1||E[i].v==1)
            cnt++;
    }
    for(int i=0;i<E.size();i++)
        if(E[i].u==1||E[i].v==1)
            E[i].c-=v;
    sort(E.begin(),E.end(),cmp);
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    int x,y,w;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        E.PB(make_edge(x,y,w,i));
    }
    double l=-10000000,r=10000000,mid;
    for(int _=1;_<=100;_++)
    {
        mid=(l+r)/2;
        int tmp=check(mid);
        if(tmp==k)
        {
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            return 0;
        }
        if(tmp>k)l=mid;else r=mid;
    }
    puts("-1");
    return 0;
}