#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,i,ta,d[202020],e[202020];
vector<ll> a[202020];
vector<ll> hs;
ll rmt(ll aa)
{
    if(aa>=0)
    {
        if(e[aa]<d[aa])
        {
            hs.pb(a[aa][e[aa]]);
            e[aa]++;
            rmt(aa+1);
        }
        else
            rmt(aa-3);
    }

}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        a[ta].pb(i);
        d[ta]++;
    }
    if(e[0]<d[0])
    {
        hs.pb(a[0][e[0]]);
        e[0]++;
        rmt(1);
    }
    if(hs.size()==n)
    {
        cout<<"Possible\n";
        for(i=0;i<n-1;i++)
            cout<<hs[i]<<" ";
        cout<<hs[n-1]<<"\n";
    }
    else
        cout<<"Impossible\n";
}