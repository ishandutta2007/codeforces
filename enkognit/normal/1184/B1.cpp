#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, p, ans, l, r, i, j, k1, k0, pr[200001], a[200001];
vector <ll> c[300005];
map<ll, ll> t;
vector <pll> v;
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    v.pb(mp(0,0));
    sort(v.begin(),v.end());
    for (int i = 1; i < v.size(); i++) pr[i]=pr[i-1]+v[i].se;
    for (int i = 0; i < n; i++)
    {
        ll l=0, r=v.size()-1;
        while (l<r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (v[w].fi<=a[i]) l=w; else r=w-1;
        }
        cout << pr[l] << " ";
    }
    return 0;
}