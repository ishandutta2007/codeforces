#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,b,a) for (ll i = b - 1; i >= a; i--)
#define all(v) v.begin(), v.end()
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define pb push_back
#define pf push_front
#define rem 1000000007
#define cont continue
const ll INF=(1ll<<60)-1;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll modulo(ll a, ll b)
{
    ll r = a % b;
    return r < 0 ? r + b : r;
}
//ncr
ull ncr(ull n, ull r)
{
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    ull ans = 1;
    ull i;
 
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}
class abc
{
    public:
    ll val;
    ll ind;
};
bool fun1(abc x,abc y)
{
    return x.val>y.val;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}
ll fact[100000+2];
ll ncrfast(ll n, ll r, ll p)
{
   if (r==0)
      return 1;
    return (fact[n]* modInverse(fact[r], p) % p *
            modInverse(fact[n-r], p) % p) % p;
}
///////////////////////////////////////////////////////
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*ll tc;
    cin>>tc;
    while(tc--)
    {}*/
    ll n;
    cin>>n;
    ll a[n];
    vector<ll> v;
    ll freq[n+1]={};
    ll filled[n+1]={};
    ll ans[n];
    rep(i,0,n)
    {
        cin>>a[i];
        freq[a[i]]=1;
        if( a[i] )
        {
            filled[i+1]=1;
        }
    }
    vector<ll> v1,v2;
    rep(i,0,n)
    {
        if( freq[i+1]==0 )
        v1.pb(i+1);
        if( filled[i+1]==0 )
        v2.pb(i+1);
    }
    for(int k=0;k<1;k++)
    {
        ll flag=0;
        rep(i,0,v1.size())
        {
            if( v1[i]==v2[i] )
            {
                if( i < v1.size()-1 )
                swap(v1[i],v1[i+1]);
                else 
                swap( v1[i] , v1[0] );
                flag=1;
            }
        }
        if( flag==0 )
        break;
    }
    ll x=0;
    rep(i,0,n)
    {
        if( a[i]==0 )
        {
            a[i]=v1[x];
            x++;
        }
    }
    rep(i,0,n)
    cout<<a[i]<<' ';
}
// 1. "\"D:\\\\mingw\\\\mingw32\\\\lib\\\\gcc\\\\i686-w64-mingw32\\\\8.1.0\\\\include\\\\c++\""
// 2.  "D:\\mingw\\mingw32\\lib\\gcc\\i686-w64-mingw32\\8.1.0\\include\\c++"