#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[202020],nx[202020],JK,kel[202020],b[202020],buk[202020],co[202020],has;
vector<ll> v[202020],isi;
ll dfs1(ll aa)
{
    b[aa]=1;
    ll ii;
    if(b[nx[aa]]==0)
        dfs1(nx[aa]);
    isi.pb(aa);
}
ll dfs2(ll aa)
{
    kel[aa]=JK;
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
        if(kel[v[aa][ii]]==0)
            dfs2(v[aa][ii]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        cin>>nx[i];
        v[nx[i]].pb(i);
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
            dfs1(i);
    }
    for(i=n-1;i>=0;i--)
    {
        if(kel[isi[i]]!=0)   continue;
       // cout<<isi[i]<<"\n";
        JK++;
        dfs2(isi[i]);
    }
    for(i=1;i<=JK;i++)
        co[i]=1e18;
    for(i=1;i<=n;i++)
        co[kel[i]]=min(co[kel[i]],a[i]);
    for(i=1;i<=n;i++)
        if(kel[i]!=kel[nx[i]])
            buk[kel[i]]=1;
//    for(i=1;i<=n;i++)
//        cout<<i<<" "<<kel[i]<<"\n";
    for(i=1;i<=JK;i++)
        if(buk[i]==0)
            has+=co[i];
    cout<<has<<"\n";
}