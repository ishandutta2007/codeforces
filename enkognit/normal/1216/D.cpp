#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second

using namespace std;

ll n, m, k, i, j, l, r;
ll a[1000001];

ll gcd(ll x,ll y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

int main()
{
    cin >> n;
    ll k=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k+=a[i];
    }
    sort(a,a+n);
    ll p=a[1]-a[0];
    for (int i = 1; i < n-1; i++)
    {
        p=gcd(p,a[i+1]-a[i]);
    }
    cout << (a[n-1]*n-k)/p << " " << p;
    return 0;
}