#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,t,i,a[202020],p[202020],N,has,ST[4040404];
vector<ll> v;
unordered_map<ll,ll> me;
void upd(ll aa,ll bb,ll cc,ll dd,ll ee)
{
    if(aa==bb)
        ST[ee]+=dd;
    else
    {
        ll ce=(aa+bb)/2;
        if(cc<=ce)
            upd(aa,ce,cc,dd,ee*2);
        else
            upd(ce+1,bb,cc,dd,ee*2+1);
        ST[ee]=ST[ee*2]+ST[ee*2+1];
    }
}
ll que(ll aa,ll bb,ll cc,ll dd,ll ee)
{
    if(bb<cc||dd<aa)
        return 0;
    else
    if(cc<=aa&&bb<=dd)
        return ST[ee];
    else
    {
        ll ce=(aa+bb)/2;
        return (que(aa,ce,cc,dd,ee*2)+que(ce+1,bb,cc,dd,ee*2+1));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        p[i]=p[i-1]+a[i];
    for(i=0;i<=n;i++)
    {
        v.pb(p[i]);
        v.pb(p[i]+t-1);
    }
    sort(v.begin(),v.end());
    N=v.size();
    for(i=0;i<N;i++)
        me[v[i]]=i+1;
    for(i=0;i<=n;i++)
        upd(1,N,me[p[i]],1,1);
    for(i=0;i<=n;i++)
    {
        upd(1,N,me[p[i]],-1,1);
        has+=que(1,N,1,me[p[i]+t-1],1);
    }
    cout<<has<<"\n";
}