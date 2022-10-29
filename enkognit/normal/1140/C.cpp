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

ll n, i, j, m, ans, k, q, l, r, z;
pll a[500001];
multiset<ll> s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].se >> a[i].fi;
        ans=max(ans,a[i].fi*a[i].se);
    }
    sort(a,a+n);
    reverse(a,a+n);
    if (m-1)
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,(k+a[i].se)*a[i].fi);
        if (s.size()<m-1) s.insert(a[i].se), k+=a[i].se; else
        if (*s.begin()<a[i].se) k-=*s.begin(),s.erase(s.begin()),s.insert(a[i].se),k+=a[i].se;
        //cout << a[i].se << " " << a[i].fi << " " << k << "\n";
    }
    cout << ans << "\n";
    return 0;
}