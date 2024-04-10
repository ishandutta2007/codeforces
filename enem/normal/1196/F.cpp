#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define VI vector<int>
#define VLL vector<long long>

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll q=1;
    //cin>>q;
    while(q--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        VLL ad[n];
        VLL w[n];
        set<tuple<ll,ll,ll>> dx;
        REP(i,0,m)
        {
            ll t1,t2,t3;
            cin>>t1>>t2>>t3;
            dx.insert(MT(t3,t1-1,t2-1));
            if(dx.size()>2*k)
            {
                auto it=dx.end();
                it--;
                dx.erase(it);
            }
            dx.insert(MT(t3,t2-1,t1-1));
            if(dx.size()>2*k)
            {
                auto it=dx.end();
                it--;
                dx.erase(it);
            }
        }
        for(auto it:dx)
        {
            ad[G(1,it)].PB(G(2,it));
            w[G(1,it)].PB(G(0,it));
        }
        set<ll> dn[n];
        priority_queue<tuple<ll,ll,ll>> hp;
        REP(i,0,n)
        {
            set<pair<ll,ll>> t;
            set<ll> dd;
            REP(j,0,ad[i].size())
            {
                t.insert(MP(w[i][j],ad[i][j]));
            }
            dd.insert(i);
            while(hp.size()<k)
            {
                if(t.size()==0) break;
                auto it=t.begin();
                ll xd=(*it).F;
                ll re=(*it).S;
                t.erase(it);
                if(dd.count(re)==1) continue;
                if(dn[i].count(re)==0)
                {
                    hp.push(MT(xd,i,re));
                    dn[i].insert(re);
                    dn[re].insert(i);
                }
                dd.insert(re);
                REP(j,0,ad[re].size())
                {
                    if(dd.count(ad[re][j])==0) t.insert(MP(xd+w[re][j],ad[re][j]));
                }
            }
            if(t.size()==0) continue;
            while(((*(t.begin())).F)<(G(0,hp.top())))
            {
                if(t.size()==0) break;
                auto it=t.begin();
                ll xd=(*it).F;
                ll re=(*it).S;
                t.erase(it);
                if(dd.count(re)==1) continue;
                if(dn[i].count(re)==0)
                {
                    hp.pop();
                    hp.push(MT(xd,i,re));
                    dn[i].insert(re);
                    dn[re].insert(i);
                }
                dd.insert(re);
                REP(j,0,ad[re].size())
                {
                    if(dd.count(ad[re][j])==0) t.insert(MP(xd+w[re][j],ad[re][j]));
                }
            }
        }
        cout<<G(0,hp.top());
    }

    return 0;
}