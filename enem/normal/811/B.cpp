#include <bits/stdc++.h>
using namespace std;
#define ll int
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll ntc=1;
    //cin>>ntc;
    REP(tc,1,ntc+1)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n+1];
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            a[t]=i+1;
        }
        REP(i,0,m)
        {
            ll t1,t2,t3;
            cin>>t1>>t2>>t3;
            ll k=0;
            ll flag=0;
            REP(j,1,n+1)
            {
                if(a[j]<=t2&&a[j]>=t1) k++;
                if(k==t3-t1+1)
                {
                    if(a[j]==t3) flag=1;
                    break;
                }
            }
            if(flag) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

    return 0;
}