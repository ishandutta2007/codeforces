#include<bits/stdc++.h>
#include<assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,s,n) for(int i=s;i<n;i++)
#define mod 1000000007
void fun();
ll digit(ll num,ll d);
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        fun();
    }
    return 0;
}
void fun()
{
    ll n,k;
    cin>>n>>k;
    double arr[n];
    fo(i,0,n)
    {
        cin>>arr[i];
    }
    double price=arr[0];
    ll ans=0;
    fo(i,1,n)
    {
        if((arr[i]/price) > (k*1.0/100*1.0))
        {
            ll a=ceil(100*arr[i]/k);
            ans+=abs(a-price);
            price+=abs(a-price);
            //cout<<a<<" "<<ans<<" "<<price<<endl;
        }
        price+=arr[i];
    }
    cout<<ans<<endl;
    return;
}