#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[550],XS,te,gagal,b[550],hx,bes[550],aduh[550],nx=-1;
vector<ll> v[550],X,Y;
void dfs(ll aa)
{
    b[aa]=1;
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
    {
        if(b[v[aa][ii]]==0)
        {
            cout<<aa<<" "<<v[aa][ii]<<"\n";
            dfs(v[aa][ii]);
        }
    }
}
void dfs1(ll aa,ll bb)
{
    bes[aa]=bb;
    if(nx==-1)nx=aa;
    if(bes[nx]<bes[aa])
        nx=aa;
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
    {
        if(bes[v[aa][ii]]==0&&v[aa][ii]!=1)
        {
            dfs1(v[aa][ii],bb+1);
        }
    }
}
void dfs2(ll aa,ll bb)
{
    aduh[aa]=bb;
    hx=max(hx,bb);
    ll ii;
    for(ii=0;ii<v[aa].size();ii++)
    {
        if(aduh[v[aa][ii]]==0&&v[aa][ii]!=nx)
        {
            dfs2(v[aa][ii],bb+1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            X.pb(i);
        }
        else
        {
            Y.pb(i);
        }
    }
    for(i=0;i<X.size();i++)
        if(a[X[i]]>2)
        {
            swap(X[0],X[i]);
            break;
        }
    ll XS=X.size();
    for(i=(XS-1);i>=0;i--)
        if(a[X[i]]>2)
        {
            swap(X[XS-1],X[i]);
            break;
        }
    for(i=1;i<XS;i++)
    {
        a[X[i]]--;
        a[X[i-1]]--;
        v[X[i]].pb(X[i-1]);
        v[X[i-1]].pb(X[i]);
    }
    if(XS==0)gagal=1;
    te=0;
    for(i=0;i<Y.size();i++)
    {
        if(gagal)break;
        if(i==0)
        {
            v[Y[i]].pb(X[0]);
            v[X[0]].pb(Y[i]);
            a[X[0]]--;
            if(a[X[0]]<0)gagal=1;
        }
        else
        if(i==1)
        {
            v[Y[i]].pb(X[XS-1]);
            v[X[XS-1]].pb(Y[i]);
            a[X[XS-1]]--;
            if(a[X[XS-1]]<0)gagal=1;
        }
        else
        {
            //cout<<a[X[te]]<<"\n";
            while(te<XS&&a[X[te]]==0)te++;
            if(te>=XS){gagal=1;break;}
            a[X[te]]--;
            v[Y[i]].pb(X[te]);
            v[X[te]].pb(Y[i]);
        }
    }
    if(gagal)cout<<"NO\n";
    else
    {
        dfs1(1,0);
        //cout<<nx<<"\n";
        dfs2(nx,0);
        cout<<"YES ";
        cout<<hx<<"\n";
        cout<<n-1<<"\n";
        dfs(1);
    }
}