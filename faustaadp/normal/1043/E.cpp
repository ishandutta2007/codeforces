#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[303030],b[303030],x[303030],h1,h2,ta,tb;
pair<ll,ll> X[303030];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        X[i]=mp(b[i]-a[i],i);
        h1+=a[i];
    }
    sort(X+1,X+1+n);
    for(i=1;i<=n;i++)
    {
        h1-=a[X[i].se];
        x[X[i].se]+=h2;
        x[X[i].se]+=h1;
        x[X[i].se]+=(i-1)*a[X[i].se];
        x[X[i].se]+=(n-i)*b[X[i].se];
        h2+=b[X[i].se];
    }
    for(i=1;i<=m;i++)
    {
        cin>>ta>>tb;
        x[ta]-=min(a[ta]+b[tb],a[tb]+b[ta]);
        x[tb]-=min(a[ta]+b[tb],a[tb]+b[ta]);
    }
    for(i=1;i<=n;i++)
        if(i<n)
            cout<<x[i]<<" ";
        else
            cout<<x[i]<<"\n";
}