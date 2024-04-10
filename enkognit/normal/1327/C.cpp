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

ll n, m, k, l, r;
pll a[1000001], b[1000001];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i].fi >> b[i].se;
    }

    string s="";
    for (int i = 0; i < m-1; i++) s+='L';
    for (int i = 0; i < n-1; i++) s+='U';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m-1; j++)
            if (i%2) s+='R'; else s+='L';
        if (i<n) s+='D';
    }
    cout << s.size() << "\n";
    cout << s << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}