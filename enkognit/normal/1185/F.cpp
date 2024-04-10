#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

ll n, m, i, j, k;
vector <ll> v, q;
bool tt[300001];
ll mask[300001], c[300001], pr[1050], pr2[1050], z[1050];
pll w[1050];

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            mask[i]^=(1<<(y-1));
        }
    }

    ll x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
        cin >> x;
        ll msk=0;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            msk^=(1<<(y-1));
        }
        if (pr[msk]==0) v.pb(msk), z[msk]=i+1, pr[msk]=c[i]; else
        if (pr[msk]>c[i]) pr[msk]=c[i], z[msk]=i+1;
    }
    if (v.size()==1) {cout << "1 2\n";exit(0);}
    for (int i = 0; i < v.size()-1; i++)
        for (int j = i+1; j < v.size(); j++)
        {
            ll o=v[i]|v[j];
            if (pr2[o]==0) q.pb(o), w[o]=mp(z[v[i]],z[v[j]]), pr2[o]=pr[v[i]]+pr[v[j]]; else
            if (pr[v[i]]+pr[v[j]]<pr2[o]) w[o]=mp(z[v[i]],z[v[j]]), pr2[o]=pr[v[i]]+pr[v[j]];
        }
    ll mx=0, mpr=1e18;
    pll ans;
    //for (int i = 0; i < q.size(); i++) cout << q[i] << "\n";

    for (int i = 0; i < q.size(); i++)
    {
        ll an=0;
        //cout << q[i] << " " << w[q[i]].fi << " " << w[q[i]].se << "\n";
        for (int j = 0; j < n; j++)
            if ((q[i]|mask[j])==q[i]) an++;
        if (an>mx) mx=an, mpr=pr2[q[i]], ans=w[q[i]];else
        if (an==mx && pr2[q[i]] < mpr) mx=an, mpr=pr2[q[i]], ans=w[q[i]];
    }
    //cout << mx << "\n";
    cout << ans.fi << " " << ans.se << "\n";
}