#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, k, a, b;

ll lcd(ll x,ll y)
{
    return y/__gcd(x,y);
}

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    cin >> a >> b;

    ll p=b-a, ans1=1e18, ans2=0;

    for (ll i = 0; i <= n; i++) if (i*k+p>0)
    {
        ll u=lcd(i*k+p,n*k);
        if (u>0)
        ans2=max(ans2,u), ans1=min(ans1,u);
    }

    for (ll i = 0; i <= n; i++) if (i*k-p>0)
    {
        ll u=lcd(i*k-p,n*k);
        if (u>0)
        ans2=max(ans2,u), ans1=min(ans1,u);
    }

    ll o=k-b-a;

    for (ll i = 0; i <= n; i++) if (i*k+o>0)
    {
        ll u=lcd(i*k+o,n*k);
        if (u>0)
        ans2=max(ans2,u), ans1=min(ans1,u);
    }

    o=a+b;

    for (ll i = 0; i <= n; i++) if (i*k+o>0)
    {
        ll u=lcd(i*k+o,n*k);
        if (u>0)
        ans2=max(ans2,u), ans1=min(ans1,u);
    }
    cout << ans1 << " " << ans2 << "\n";

    return 0;
}