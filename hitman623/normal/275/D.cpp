#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
vector < long > a[100005];
long n,i,x,y,v[100005];
long visi[100005]={0};
pair < long , long > dfs(long node)
{
    long i,mxp=0,mnm=0;
    pair < long ,long > u;
    visi[node]=1;
    for(i=0;i<a[node].size();++i)
    if(!visi[a[node][i]])
    {
        u=dfs(a[node][i]);
        mxp=max(mxp,u.first);
        mnm=max(mnm,u.second);
    }
    v[node]+=mxp-mnm;
    if(v[node]>0)
    return {mxp,mnm+v[node]};
    else return {mxp+abs(v[node]),mnm};
}
int main()
{
    pair < long ,long > u;
    cin>>n;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(i=1;i<=n;++i)
    cin>>v[i];
    u=dfs(1);
    cout<<u.first+u.second<<endl;
    return 0;
}