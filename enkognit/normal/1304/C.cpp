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

ll n, kl, m, k, i, j, h;
string s[100001];
bool tt[1000001];
pair<ll,pll> a[1000001];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    a[n+1]=mp(0,mp(m,m));
    for (int i = 1; i <= n; i++)
    {
        ll p=a[i].fi-a[i+1].fi;
        a[i+1].se.fi=max(a[i+1].se.fi,a[i].se.fi-p);
        a[i+1].se.se=min(a[i+1].se.se,a[i].se.se+p);
        if (a[i+1].se.fi>a[i+1].se.se) {cout << "NO\n";return;}
    }
    cout << "YES\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}
/*
*/