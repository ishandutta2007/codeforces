#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll n,m;
    cin>>n>>m;
    ll ad[n][n];
    REP(i,0,n) REP(j,0,n) ad[i][j]=0;
    REP(i,0,m)
    {
        ll t1,t2;
        cin>>t1>>t2;
        t1--;
        t2--;
        ad[t1][t2]=1;
        ad[t2][t1]=1;
    }
    if(n<=6)
    {
        cout<<m;
        return 0;
    }
    ll ans=0;
    REP(i,0,7)
    {
        REP(j,0,7)
        {
            if(i==j) continue;
            ll t=m;
            REP(k,0,7)
            {
                if(ad[i][k]==1&&ad[j][k]==1) t--;
            }
            ans=max(ans,t);
        }
    }
    cout<<ans;

    return 0;
}