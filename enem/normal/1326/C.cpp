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
//#define minn 999999999
//#define maxx 0
class abc
{
    public:
    ll ind;
    ll val;
};
bool fun1(abc x,abc y)
{
    return x.val<y.val;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    abc arr[n];
    rep(i,0,n)
    {
        cin>>arr[i].val;
        arr[i].ind=i;
    }
    sort(arr,arr+n,fun1);
    vector<ll> v;
    ll ans1=0;
    ll x=k;
    for(ll i=n;x>0 ; i--,x-- )
    {
        ans1+=i;
        v.pb(arr[i-1].ind);
    }
    sort(all(v));
    vector<ll> ans;
    ll sum=1;
    rep(i,1,v.size())
    {
        ll xd=v[i]-v[i-1];
        sum*=xd;
        sum%=(ll)998244353;
    }
    
    // rep(i,0,ans.size())
    // {
    //     sum+=ans[i];
    //     sum%=998244353;
    // }
    // rep(i,0,v.size())
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    cout<<ans1<<" "<<sum;
}