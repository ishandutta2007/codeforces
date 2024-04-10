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
ll a[500001];
multiset<ll> s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll i=0, j=n-1;
    while (a[i]==1) i++;
    while (a[j]==1 && j>i) j--;
    ans=i+n-j-1;
    ll k=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]) k++; else k=0;
        ans=max(ans,k);
    }
    cout << ans;
    return 0;
}