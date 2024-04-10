#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

struct e
{long w,nd,p;}t,q;

inline bool operator<(const e& lhs, const e& rhs)
{
  if(lhs.w!=rhs.w) return lhs.w<rhs.w;
  else return lhs.nd<rhs.nd;
}

set < struct e > s;
set < struct e > ::iterator it;
long visi[100005]={0},parent[100005];
map < pair< long, long > , long > ww;
map < long , vector < long > > a;

void dfs()
{
    long i;
    if(s.size()==0) return ;
    while(s.size()>0)
    {
        q=*s.begin();
        s.erase(s.begin());
        if(visi[q.nd]==0) break;
    }
    if(visi[q.nd]==1) return;
    visi[q.nd]=1;
    ww[mp(1,q.nd)]=q.w;
    ww[mp(q.nd,1)]=q.w;
    parent[q.nd]=q.p;
    for(i=0;i<a[q.nd].size();++i)
        if(visi[a[q.nd][i]]==0)
        {
            t.w=ww[mp(1,q.nd)]+ww[mp(a[q.nd][i],q.nd)];
            t.nd=a[q.nd][i];
            t.p=q.nd;
            s.insert(t);
        }
    dfs();
}
int main()
{
    long n,m,i,x,y,w,path[100005],l=0;
    cin>>n>>m;
    for(i=0;i<m;++i)
      {
        cin>>x>>y>>w;
        a[x].pb(y);
        a[y].pb(x);
        ww[mp(x,y)]=w;
        ww[mp(y,x)]=w;
      }
    t.w=0;t.nd=1;t.p=1;
    s.insert(t);
    dfs();
    if(visi[n]==0) {cout<<-1;exit(0);}
    i=n;
    while(i!=parent[i])
    {path[l++]=i;
    i=parent[i];}
    path[l]=1;
    for(i=0;i<=l;i++)
    cout<<path[l-i]<<" ";
    return 0;
}