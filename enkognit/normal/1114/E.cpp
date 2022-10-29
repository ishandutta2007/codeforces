#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, i, j, k, l, r, a[500001];
vector <pll> b;
bool t[500001];

ll gcd(ll a,ll b)
{
    if (a==0 || b==0) return a+b; else return __gcd(a,b);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll l=0, r=1e9+1;
    while (l<r)
    {
        ll w=(l+r)/2+(l+r)%2;
        ll t=0;
        cout << "> " << w << "\n";
        cin >> t;
        if (t) l=w; else r=w-1;
    }
    ll ans=0, k=l+1;
    for (int i = 1; i < 30; i++)
    {
        ll p=(rand()*rand())%n;
        ll t;
        cout << "? " << p+1 << "\n";
        cin >> t;
        ans=gcd(ans,k-t);
    }
    cout << "! " << k-ans*(n-1) << " " << ans << "\n";
    return 0;
}