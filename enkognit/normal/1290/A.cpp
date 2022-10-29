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

using namespace std;

ll md1=1e9+9, md2=998244357, p1=8244357, p2=3131313;

ll n, m, k, i, j, h, a[1000001];
pll b[1000001];
string s, d;
vector<ll> v;

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
        cin >> n >> m >> k;
        if (k>=m) k=m-1;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll p=n-k;
        ll ans=0, an2=1e18;
        for (int i = 1; i <= n-p+1; i++)
        {
            ll an=1e18;
            ll u=p-max((m-k-1),0ll);
            //cout << i << " " << i+p-1 << " " << u << "\n";
            for (int j = i; j+u-1 <= (i+p-1); j++)
            {
                an=min(an,max(a[j],a[j+u-1]));
            }
            if (an!=1e18)
            ans=max(ans,an);
        }
        p=n-(m-k-1);
        cout << ans << "\n";
    }
    return 0;
}
/*
*/