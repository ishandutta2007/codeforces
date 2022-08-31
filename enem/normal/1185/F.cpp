#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VLL vector<long long>

ll modInverse(ll a, ll m);
ll gcd(ll a, ll b);
ll power(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

void pairsortll(ll a[], ll b[], ll n)
{
    pair<ll, ll> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (ll i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (ll i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<x;i++)
    {
        if(x<=a)
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

    ll n,m;
    cin>>n>>m;
    ll a[n],p[m],c[m];
    REP(i,0,n)
    {
        ll t=0;
        ll nv;
        cin>>nv;
        REP(j,0,nv)
        {
            ll x;
            cin>>x;
            x--;
            t=t|(1<<x);
        }
        a[i]=t;
    }
    ll b[(1<<9)]={};
    REP(i,0,1<<9)
    {
        REP(j,0,n)
        {
            if((i&a[j])==a[j])
            {
                b[i]++;
            }
        }
    }
    REP(i,0,m)
    {
        cin>>c[i];
        ll t=0;
        ll nv;
        cin>>nv;
        REP(j,0,nv)
        {
            ll x;
            cin>>x;
            x--;
            t=t|(1<<x);
        }
        p[i]=t;
    }
    ll lwst[1<<9],lwst2[1<<9],f[1<<9],x[1<<9],x2[1<<9];
    REP(i,0,1<<9) f[i]=-1;
    REP(i,0,m)
    {
        if(f[p[i]]==-1)
        {
            lwst[p[i]]=c[i];
            f[p[i]]=0;
            x[p[i]]=i;
        }
        else if(f[p[i]]==0)
        {
            lwst2[p[i]]=c[i];
            f[p[i]]=1;
            x2[p[i]]=i;
            if(lwst2[p[i]]<lwst[p[i]])
            {
                ll t=lwst2[p[i]];
                lwst2[p[i]]=lwst[p[i]];
                lwst[p[i]]=t;
                t=x2[p[i]];
                x2[p[i]]=x[p[i]];
                x[p[i]]=t;
            }
        }
        else
        {
            if(c[i]<lwst2[p[i]])
            {
                lwst2[p[i]]=c[i];
                x2[p[i]]=i;
            }
            if(lwst2[p[i]]<lwst[p[i]])
            {
                ll t=lwst2[p[i]];
                lwst2[p[i]]=lwst[p[i]];
                lwst[p[i]]=t;
                t=x2[p[i]];
                x2[p[i]]=x[p[i]];
                x[p[i]]=t;
            }
        }
    }
    ll ans[2]={};
    ll cost=1e10;
    REP(i,0,1<<9)
    {
        if(f[i]==-1) continue;
        if(f[i]==1)
        {
            if(b[i]>b[p[ans[0]]|p[ans[1]]])
            {
                ans[0]=x[i];
                ans[1]=x2[i];
                cost=lwst[i]+lwst2[i];
            }
            else if(b[i]==b[p[ans[0]]|p[ans[1]]])
            {
                if(lwst[i]+lwst2[i]<cost)
                {
                    ans[0]=x[i];
                    ans[1]=x2[i];
                    cost=lwst[i]+lwst2[i];
                }
            }
        }
        REP(j,i+1,1<<9)
        {
            if(f[j]==-1) continue;
            if(b[i|j]>b[p[ans[0]]|p[ans[1]]])
            {
                ans[0]=x[i];
                ans[1]=x[j];
                cost=lwst[i]+lwst[j];
            }
            else if(b[i|j]==b[p[ans[0]]|p[ans[1]]])
            {
                if(lwst[i]+lwst[j]<cost)
                {
                    ans[0]=x[i];
                    ans[1]=x[j];
                    cost=lwst[i]+lwst[j];
                }
            }
        }
    }
    cout<<ans[0]+1<<' '<<ans[1]+1;

    return 0;
}