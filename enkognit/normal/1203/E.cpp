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
    cin>> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        if (i==0){if (a[i]>1) a[i]--;}else
        {
            if (a[i]-1>a[i-1]) a[i]--;
        }
    }
    for (int i = n-1; i > -1; i--)
    {
        if (i==n-1){a[i]++;}else
        {
            if (a[i]+1<a[i+1]) a[i]++;
        }
    }
    ll ans=1;
    for (int i = 1; i < n; i++) if (a[i]!=a[i-1]) ans++;
    cout << ans << "\n";
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