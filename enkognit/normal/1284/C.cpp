#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(time(NULL));

ll n, m, k, i, j, mx=0, kl=0, T=0, fact[1000001];
vector <ll> b[200001];
vector <pll> v;

bool comp(pll x,pll y)
{
    return (x.fi>y.fi || (x.fi==y.fi && x.fi>y.fi));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fact[0]=1;
    for (int i = 1; i <= n; i++)
    {
        fact[i]=(fact[i-1]*i)%m;
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        ans=(ans+(n-i+1)%m*(n-i+1)%m*fact[i]%m*fact[n-i]%m)%m;
    }
    cout << ans;
    return 0;
}
/*
4
101
10001
1
10
1101
*/