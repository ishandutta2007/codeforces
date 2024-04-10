#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl ad[505];
long type[100005]={0},ww[505][505],j,p[100005],pp;
long n,m,k,c[505],u,v,x,i,s=0;
mll mp;
void dijkstra(long node)
{
    multiset < pll > q;
    long i,v[505]={0};
    q.insert({0,node});
    while(!q.empty())
    {
        pll d=*q.begin();
        q.erase(q.begin());
        if(ww[node][d.y]!=-1)
        ww[node][d.y]=min(ww[node][d.y],d.x);   
        else ww[node][d.y]=d.x;
        v[d.y]=1;
        for(i=0;i<ad[d.y].size();++i)
        if(!v[ad[d.y][i]])
        q.insert({ww[node][d.y]+mp[{d.y,ad[d.y][i]}],ad[d.y][i]});
    }
}
long fp(long x)
{
    if(p[x]==x) return x;
    else return p[x]=fp(p[x]);
}
void merge(long u,long v)
{
    long p1=fp(u),p2=fp(v);
    p[p1]=p2;
}
int main()
{
    io
    cin>>n>>m>>k;
    for(i=0;i<k;++i)
    cin>>c[i];
    for(i=1;i<=n;++i)
    p[i]=i;
    for(i=1;i<=k;++i)
    {
        for(j=1;j<=c[i-1];++j)
        type[s+j]=i;
        s+=c[i-1];
    }
    for(i=0;i<m;++i)
    {
        cin>>u>>v>>x;
        if(x==0) merge(u,v);
        if(type[u]==type[v] && x!=0) continue;
        if(mp.find({type[u],type[v]})==mp.end() && type[u]!=type[v])
        {
            ad[type[u]].pb(type[v]);
            ad[type[v]].pb(type[u]);
            mp[{type[u],type[v]}]=x;
            mp[{type[v],type[u]}]=x;
        }
        else if(type[u]!=type[v])
        {
            mp[{type[u],type[v]}]=min(mp[{type[u],type[v]}],x);
            mp[{type[v],type[u]}]=mp[{type[u],type[v]}];
        }
    }
    s=0;
    for(i=1;i<=k;++i)
    {
        pp=fp(s+1);
        for(j=1;j<=c[i-1];++j)
        if(fp(s+j)!=pp) {cout<<"No";exit(0);}
        s+=c[i-1];
    }
    memset(ww,-1,sizeof(ww));
    for(i=1;i<=k;++i)
    dijkstra(i);
    cout<<"Yes\n";
    for(i=1;i<=k;++i)
    ww[i][i]=0;
    for(i=1;i<=k;++i)
    {
        for(j=1;j<=k;++j)
        cout<<ww[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}