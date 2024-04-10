#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, m, k, l, r, a[100001], tt[1000001];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) tt[i]=0;
    ll u=-1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ll p=-1;
        for (int i = 0; i < x; i++)
        {
            ll y;
            cin >> y;
            if (!tt[y] && p==-1) p=y;
        }
        if (p!=-1)
        {
            tt[p]=1;
        } else u=i;
    }
    if (u!=-1)
    {
        ll o=-1;
        for (int i = 1; i <= n; i++)
            if (!tt[i]) {o=i;break;}
        cout << "IMPROVE\n";
        cout << u << " " << o << "\n";
    } else
    cout << "OPTIMAL\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}