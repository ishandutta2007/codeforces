#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
#define MOD 1000000007
#define ll long long
ll extgcd(ll a,ll b,ll&x,ll&y)
{
    ll d=a;
    if(b)d=extgcd(b,a%b,y,x),y-=(a/b)*x;else x=1,y=0;
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return ((ll)m+x%m)%m;
}
inline ll mod_pow(ll x,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}
int k;
string a;
int main()
{
    cin>>a>>k;
    ll ans=0,p2=1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0'||a[i]=='5')
        {
            ans=(ans+p2)%MOD;
        }
        p2=p2*2%MOD;
    }
    cout<<ans*(mod_pow(p2,k)-1+MOD)%MOD*mod_inverse(p2-1,MOD)%MOD;
    return 0;
}