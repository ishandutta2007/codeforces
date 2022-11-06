#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,a[202020],P[202020],has,ta,tb,tc,cal,taa,tbb;
vector<pair<ll,pair<ll,ll> > > E;
ll car(ll aa)
{
    if(P[aa]==aa)return aa;
    else
    {
        ll tem=car(P[aa]);
        P[aa]=tem;
        return P[aa];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)P[i]=i;
    for(i=1;i<=m;i++)
    {
        cin>>ta>>tb>>tc;
        E.pb(mp(tc,mp(ta,tb)));
    }
    cal=1;
    for(i=1;i<=n;i++)
        if(a[cal]>a[i])
            cal=i;
    for(i=1;i<=n;i++)
        if(i!=cal)
            E.pb(mp(a[cal]+a[i],mp(cal,i)));
    sort(E.begin(),E.end());
    for(i=0;i<E.size();i++)
    {
        ta=E[i].se.fi;
        tb=E[i].se.se;
        taa=car(ta);
        tbb=car(tb);
        if(taa!=tbb)
        {
  //          cout<<ta<<" "<<tb<<" "<<E[i].fi<<"\n";
            P[taa]=tbb;
            has+=E[i].fi;
        }
    }
    cout<<has<<"\n";
}