#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll n, m, k, q, p, ans, l, r, i, j, x, y;
pair<ll,pll> a[200001];
vector <pll> c[200001];
vector <ll> v;
ll d[200001];
bool t[1000001], tt[1000001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].se.fi >> a[i].se.se >> a[i].fi;
    }
    sort(a,a+m);
    for (int i = 0; i < k; i++)
    {
        c[a[i].se.fi].pb(mp(a[i].se.se,a[i].fi));
        c[a[i].se.se].pb(mp(a[i].se.fi,a[i].fi));
        ll x=a[i].se.fi;
        ll y=a[i].se.se;
        if (!t[x]) v.pb(x), t[x]=1;
        if (!t[y]) v.pb(y), t[y]=1;
    }
    //while ()
    vector <ll> z;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++) d[v[j]]=1e18;
        set<pll> q;
        d[v[i]]=0;
        q.insert(mp(0,v[i]));
        while (q.size())
        {
            ll x=(*q.begin()).se, h=(*q.begin()).fi;
            q.erase(q.begin());
            for (int j = 0; j < c[x].size(); j++)
                if (d[c[x][j].fi] > h + c[x][j].se)
                {
                    q.erase(mp(d[c[x][j].fi], c[x][j].fi));
                    d[c[x][j].fi]=h+c[x][j].se;
                    q.insert(mp(d[c[x][j].fi], c[x][j].fi));
                }

        }
        for (int j = i+1; j < v.size(); j++)
        {
            z.pb(d[v[j]]);
            //cout << v[i] << " " << v[j] << ":" << d[v[j]] << "\n";
        }
    }
    sort(z.begin(),z.end());
    cout << z[k-1] << "\n";
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