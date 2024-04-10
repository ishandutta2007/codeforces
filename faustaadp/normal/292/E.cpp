#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,i,a[202020],ST[404040],ta,tb,tc,b[404040],LZ[404040];
void upd(ll aa,ll bb,ll cc,ll dd,ll ee,ll ff)
{
    if(b[ee]==1)
    {
        ST[ee]=LZ[ee];
        if(aa!=bb)
        {
            LZ[ee*2]=LZ[ee];
            b[ee*2]=1;
            LZ[ee*2+1]=LZ[ee];
            b[ee*2+1]=1;
        }
        b[ee]=0;
    }
    if(bb<cc||dd<aa)return ;
    else if(cc<=aa&&bb<=dd)
    {
        ST[ee]=ff;
        if(aa!=bb)
        {
            LZ[ee*2]=ff;
            b[ee*2]=1;
            LZ[ee*2+1]=ff;
            b[ee*2+1]=1;
        }
    }
    else
    {
        ll ce=(aa+bb)/2;
        upd(aa,ce,cc,dd,ee*2,ff);
        upd(ce+1,bb,cc,dd,ee*2+1,ff);
    }
}
ll que(ll aa,ll bb,ll cc,ll ee)
{
    if(b[ee]==1)
    {
        ST[ee]=LZ[ee];
        if(aa!=bb)
        {
            LZ[ee*2]=LZ[ee];
            b[ee*2]=1;
            LZ[ee*2+1]=LZ[ee];
            b[ee*2+1]=1;
        }
        b[ee]=0;
    }
    if(aa==bb)return a[aa-ST[ee]];
    else
    {
        ll ce=(aa+bb)/2;
        if(cc<=ce)return que(aa,ce,cc,ee*2);
        else    return que(ce+1,bb,cc,ee*2+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(i=1;i<=n*2;i++)cin>>a[i];
    for(i=1;i<=n*4;i++)ST[i]=-n;
    while(q--)
    {
        cin>>ta;
        if(ta==1)
        {
            cin>>ta>>tb>>tc;
            upd(1,n,tb,tb+tc-1,1,tb-ta);
        }
        else
        {
            cin>>ta;
            cout<<que(1,n,ta,1)<<"\n";
        }
    }
}