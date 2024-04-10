#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long,long>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);


ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}

ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}

ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}

void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}

ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}

int main()
{

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll ntc=1;
    //cin>>ntc;
    REP(tc,1,ntc+1)
    {
        //cout<<"Case #"<<tc<<": ";

        ll n;
        cin>>n;
        ll a[n];
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            a[i]=t;
        }
        ll ans=0;
        ll sum=0;
        map<ll,ll> mp;
        REP(i,0,n)
        {
            if(mp.count(a[i])==0) mp.insert(MP(a[i],1));
            else  mp[a[i]]++;
            if(mp.count(a[i]-1)!=0) ans-=mp[a[i]-1];
            if(mp.count(a[i]+1)!=0) ans+=mp[a[i]+1];
        }
        ll ans2=0;
        REP(i,0,n)
        {
            sum+=a[i];
            ans+=((i+1)*a[i]-sum);
            ans+=1e17;
            ans2-=100;
            ans2+=ans/((ll)1e15);
            ans%=((ll)1e15);
        }
        if(ans2==0) cout<<ans;
        else if(ans2==-1) cout<<ans-((ll)1e15);
        else if(ans2>0) 
        {
            cout<<ans2;
            printf("%.15lld",ans);
        }
        else if(ans2<-1)
        {
            if(ans!=0)
            {
                cout<<ans2+1;
                printf("%.15lld",((ll)1e15)-ans);
            }
            else
            {
                cout<<ans2;
                printf("%.15lld",ans);
            }
        }

        cout<<'\n';
    }

    return 0;
}