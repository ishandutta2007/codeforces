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
long n,m,s,x,y,w,l,i,ww[100005]={0};
vl a[100005];
mll mp;
void dijkstra(long root)
{
    long visi[100005]={0},i;
    set < pll > p;
    p.insert({0,root});
    while(!p.empty())
    {
        pll d=*p.begin();
        p.erase(p.begin());
        if(visi[d.y]==0)
        {
            ww[d.y]=d.x;
            visi[d.y]=1;
        }
        for(i=0;i<a[d.y].size();++i)
        if(!visi[a[d.y][i]])
        p.insert({ww[d.y]+mp[{d.y,a[d.y][i]}],a[d.y][i]});
    }
}
int main()
{
    io
    vll edge;
    long c=0;
    cin>>n>>m>>s;
    for(i=0;i<m;++i)
    {
        cin>>x>>y>>w;
        edge.pb({x,y});
        a[x].pb(y);
        a[y].pb(x);
        mp[{x,y}]=w;
        mp[{y,x}]=w;
    }
    cin>>l;
    dijkstra(s);
    for(i=1;i<=n;++i)
    if(ww[i]==l) c++;
    for(i=0;i<m;i++)
    {
        x=edge[i].x;
        y=edge[i].y;
        if(mp[{x,y}]==1) continue;
        if(abs(ww[x]-ww[y])==mp[{x,y}])
        {
            if(min(ww[x],ww[y])<l && max(ww[x],ww[y])>l) c++;
        }
        else
        {
            if(l>ww[x] && l-ww[x]<mp[{x,y}] && ww[y]+mp[{x,y}]-(l-ww[x])>=l) c++;
            if(l>ww[y] && l-ww[y]<mp[{x,y}] && mp[{x,y}]-(l-ww[x])!=l-ww[y] && ww[x]+mp[{x,y}]-(l-ww[y])>l) c++;
        }
    }
    cout<<c;
    return 0;
}