#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define pi 3.14159265358979323846

using namespace std;

const ll mod=1e9+7;

ll n, m, j, ans, t, o, l, k, r, x[200001], y[200001], a[200001];
vector <pll> c[200001];
string s, d;
bool tt[1000001];

int main()
{
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
        a[x[i]]++;
        a[y[i]]++;
        c[x[i]].pb(mp(y[i],i));
        c[y[i]].pb(mp(x[i],i));
    }
    ll an=n;
    vector <ll> ans;
    set<pll> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(mp(a[i],i));
    }
    while ((*s.begin()).fi<k)
    {
        ll w=(*s.begin()).se;
        s.erase(s.begin());
        for (int i = 0; i < c[w].size(); i++)
            if (!tt[c[w][i].fi])
            {
                s.erase(mp(a[c[w][i].fi],c[w][i].fi));
                a[c[w][i].fi]--;
                s.insert(mp(a[c[w][i].fi],c[w][i].fi));
            }
        tt[w]=1;
    }
    for (int i = m-1; i > -1; i--)
    {
        ans.pb(s.size());
        if (!(tt[x[i]] || tt[y[i]]))
        {
            s.erase(mp(a[x[i]],x[i]));
            s.erase(mp(a[y[i]],y[i]));
            a[x[i]]--;
            a[y[i]]--;
            s.insert(mp(a[x[i]],x[i]));
            s.insert(mp(a[y[i]],y[i]));
            while ((*s.begin()).fi<k)
            {
                ll w=(*s.begin()).se;
                s.erase(s.begin());
                for (int j = 0; j < c[w].size(); j++)
                    if (!tt[c[w][j].fi] && c[w][j].se<i)
                    {
                        s.erase(mp(a[c[w][j].fi],c[w][j].fi));
                        a[c[w][j].fi]--;
                        s.insert(mp(a[c[w][j].fi],c[w][j].fi));
                    }
                tt[w]=1;
            }
        }
    }
    for (int i = ans.size()-1; i > -1; i--) cout << ans[i] << "\n";
    return 0;
}
/*
4 3
1 2 3 4
1 2
2 3
3 4
*/