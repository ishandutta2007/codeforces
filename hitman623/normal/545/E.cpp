#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

struct e
{long long w,nd,p;}t,q;

inline bool operator<(const e& lhs, const e& rhs)
{
  if(lhs.w!=rhs.w) return lhs.w<rhs.w;
  else return lhs.nd<=rhs.nd;
}

set < struct e > s;
set < struct e > ::iterator it;
long long visi[300005]={0},parent[300005],source;
map < pair< long long, long long > , long long > ww;
vector < long long > a[300005];

void dfs()
{
    long long i;
    if(s.size()==0) return ;
    while(s.size()>0)
    {
        q=*s.begin();
        s.erase(s.begin());
        if(visi[q.nd]==0) break;
    }
    if(visi[q.nd]==1) return;
    visi[q.nd]=1;
    ww[mp(source,q.nd)]=q.w;
    ww[mp(q.nd,source)]=q.w;
    parent[q.nd]=q.p;
    for(i=0;i<a[q.nd].size();++i)
        if(visi[a[q.nd][i]]==0)
        {
            t.w=ww[mp(source,q.nd)]+ww[mp(a[q.nd][i],q.nd)];
            t.nd=a[q.nd][i];
            t.p=q.nd;
            s.insert(t);
        }
    dfs();
}
long long check[300005]={0};
long long n,m,i,x[300005],y[300005],w,path[300005],l=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=0;i<m;++i)
      {
        cin>>x[i]>>y[i]>>w;
        a[x[i]].pb(y[i]);
        a[y[i]].pb(x[i]);
        ww[mp(x[i],y[i])]=w;
        ww[mp(y[i],x[i])]=w;
      }
    cin>>source;
    t.w=0;t.nd=source;t.p=source;
    s.insert(t);
    dfs();
    long long ans=0;
    if(visi[n]==0) {cout<<-1;exit(0);}
    for(i=0;i<=m;++i)
    {
        if(parent[y[i]]==x[i] || parent[x[i]]==y[i])
        {check[i]=1;ans+=ww[{x[i],y[i]}];}
    }
    cout<<ans<<endl;
    for(i=0;i<m;++i)
    if(check[i]) cout<<i+1<<" ";
    return 0;
}