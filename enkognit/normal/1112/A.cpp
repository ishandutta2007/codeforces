#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, a[1000001];
string s, d;
pll v[1000001];
ll b[1000001];

template<typename T>
T sqr(T x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i]>v[b[i]].fi) v[b[i]]=mp(a[i],i+1);
    }
    ll ans=0;
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        if (v[b[x-1]].se!=x) ans++;
    }
    cout << ans;
    return 0;
}