#include <bits/stdc++.h>
#define pb push_back
using namespace std;

long n,m,i,x,y,c[100001]={0},visi[100001]={0},ans=0;
map < long ,vector <long> > a;
void dfs(long node,long cou,long l)
{   long i;
    if(visi[node]==1) return;
    else if(a[node].size()==1 && node!=1) {if(c[node]+cou<=l)ans++;return;}
    else
    {
        visi[node]=1;
        if(c[node]==1) cou++;
        else cou=0;
        if(cou>l) return;
        for(i=0;i<a[node].size();++i)
        {
            dfs(a[node][i],cou,l);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>c[i];
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,0,m);
    cout<<ans;
    return 0;
}