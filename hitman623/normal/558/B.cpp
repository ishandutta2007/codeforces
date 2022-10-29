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
long ans=1e9,n,a[100005],v[1000006],i,g[1000006][2]={0},l,r,m=0;
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i],v[a[i]]++;
        if(g[a[i]][0]==0)
        g[a[i]][0]=i;
        g[a[i]][1]=i;
    }
    vl vv;
    for(i=0;i<=1e6;++i)
    m=max(m,v[i]);
    for(i=0;i<=1e6;++i)
    if(v[i]==m) vv.pb(i);
    for(i=0;i<vv.size();++i)
    {
        if(g[vv[i]][1]-g[vv[i]][0]+1<ans)
        {
            ans=min(ans,g[vv[i]][1]-g[vv[i]][0]+1);
            l=g[vv[i]][0];
            r=g[vv[i]][1];
        }
    }
    cout<<l<<" "<<r;
    return 0;
}