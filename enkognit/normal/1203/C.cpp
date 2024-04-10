#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y, kol=0, a[1000001];
vector <ll> c[300001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll p;
    cin >> p;
    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        p=__gcd(x,p);
    }
    ll w=sqrt(p), ans=0;
    for (int i = 1; i <= w; i++)
    {
        if (p%i==0) ans+=2;
    }
    if (w*w==p) ans--;
    cout << ans;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/