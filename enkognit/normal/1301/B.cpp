#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 shue_ppsh
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, a[1000001];
string s;
vector<ll> v;

void solve()
{
    cin >> n;
    ll mx=0, mn=1e18;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0]=-1;a[n+1]=-1;
    for (int i = 1; i <= n; i++)
        if (a[i]==-1)
        {
            if (a[i-1]!=-1)
            {
                mn=min(mn,a[i-1]);
                mx=max(mx,a[i-1]);
            }
            if (a[i+1]!=-1)
            {
                mn=min(mn,a[i+1]);
                mx=max(mx,a[i+1]);
            }
        }
    ll p=0, m=0;
    if (mn==1e18) mn=0, p=0, mx=0; else p=(mx+mn)/2;
    m=max(m,max(mx-p,p-mn));
    for (int i = 1; i <= n; i++)
        if (a[i]!=-1 && a[i+1]!=-1) m=max(m,abs(a[i+1]-a[i]));
    cout << m << " " << p << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/