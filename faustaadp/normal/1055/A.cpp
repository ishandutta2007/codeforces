#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,a[1010],b[1010],B[1010],i;
vector<ll> x,y,v[1010];
void dfs(ll aa)
{
    B[aa]=1;
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
        if(!B[v[aa][ii]])
            dfs(v[aa][ii]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    for(i=1;i<=n;i++)if(a[i]==1)x.pb(i);
    for(i=1;i<=n;i++)if(b[i]==1)y.pb(i);
    for(i=1;i<x.size();i++)v[x[i-1]].pb(x[i]);
    for(i=1;i<y.size();i++)v[y[i]].pb(y[i-1]);
    dfs(1);
    if(B[k])cout<<"YES\n";
    else    cout<<"NO\n";
}