#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,ta,x[101010],te;
unordered_map<ll,ll> d;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>ta;
        if(!d[ta])
        {
            x[++te]=ta;
        }
        d[ta]=1;
    }
    sort(x+1,x+1+te);
    for(i=1;i<=k;i++)
    {
        if(i>te)cout<<0<<"\n";
        else cout<<x[i]-x[i-1]<<"\n";
    }
}