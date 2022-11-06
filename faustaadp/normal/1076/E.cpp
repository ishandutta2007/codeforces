#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,tb,tc,q,dep[303030],BIT[303030],a[303030];
vector<ll> v[303030];
vector<pair<ll,ll> > isi[303030];
void dfs(ll aa,ll bb)
{
    dep[aa]=bb;
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
        if(!dep[v[aa][ii]])
            dfs(v[aa][ii],bb+1);
}
void upd(ll aa,ll bb)
{
    if(aa>n)return ;
    BIT[aa]+=bb;
    upd(aa+(aa&(-aa)),bb);
}
ll que(ll aa)
{
    if(aa==0)return 0;
    else return BIT[aa]+que(aa-(aa&(-aa)));
}
ll dfs2(ll aa,ll bb)
{
    ll ii;
    for(ii=0;ii<isi[aa].size();ii++)
    {
        upd(dep[aa]+isi[aa][ii].fi+1,-isi[aa][ii].se);
        upd(dep[aa],isi[aa][ii].se);
    }
    a[aa]=que(dep[aa]);
    for(ii=0;ii<v[aa].size();ii++)
        if(v[aa][ii]!=bb)
            dfs2(v[aa][ii],aa);
    for(ii=0;ii<isi[aa].size();ii++)
    {
        upd(dep[aa]+isi[aa][ii].fi+1,isi[aa][ii].se);
        upd(dep[aa],-isi[aa][ii].se);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>ta>>tb;
        v[ta].pb(tb);
        v[tb].pb(ta);
    }
    dfs(1,1);
    //return 0;
    cin>>q;
    while(q--)
    {
        cin>>ta>>tb>>tc;
        isi[ta].pb(mp(tb,tc));
    }
    dfs2(1,0);
    for(i=1;i<=n;i++)
        if(i<n)cout<<a[i]<<" ";
        else    cout<<a[i]<<"\n";
}