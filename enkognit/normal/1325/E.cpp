#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl = 0, m, ans = 1e9, p, w, hh[1000001];
vector<pll> c[1000001];
vector<ll> vv;
bool tt[1000001], tl[1000001];



void slv(int h)
{
    //cout << h << "\n";
    for (int i = 0; i < vv.size(); i++)
        tt[vv[i]] = 0, hh[vv[i]] = -1;
    for (int i = 1; i <= n; i++) tl[i] = 0;
    queue<ll> q;
    q.push(h);
    tt[h] = 1;
    hh[h] = 0;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        //cout << x << "\n";
        for (int i = 0; i < c[x].size(); i++)
            if (!tt[c[x][i].fi])
            {
                //cout << x << " " << c[x][i].first << "\n";
                tt[c[x][i].first] = 1;
                tl[c[x][i].second] = 1;
                hh[c[x][i].first] = hh[x] + 1;
                q.push(c[x][i].fi);
            }
            else
            if (!tl[c[x][i].second]) ans = min(ans, hh[x] + hh[c[x][i].first] + 1);
    }
    //cout << "----\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<ll> s;
    ll p;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        //p = max(p, (ll)sqrt(x));
        ll q = sqrt(x);
        if (q * q == x)
        {
            cout << "1\n";
            exit(0);
        }
        vector<ll> v;
        ll y = x;
        for (int i = 2; i <= q; i++)
            if (y % i == 0)
            {
                while (y % i == 0) v.pb(i), y /= i;
            }
        if (y > 1) v.pb(y);
        sort(all(v));
        vector<ll> p;
        for (int i = 0; i < v.size(); i++)
        {
            if (p.size() && p.back() == v[i]) p.pop_back(); else p.pb(v[i]);
        
        }
        if (p.size() == 1)
        {
            s.insert(p[0]);
            s.insert(1);
            //cout << 1 << " " << p[0] << "\n";
            //edges.pb(mp(1,p[0]));
            c[1].pb(mp(p[0],i));
            c[p[0]].pb(mp(1,i));
        }
        else
        {
            //cout << p[0] << " " << p[1] << "\n";
            s.insert(p[1]);
            s.insert(p[0]);
            //edges.pb(mp(p[1], p[0]));
            c[p[0]].pb(mp(p[1],i));
            c[p[1]].pb(mp(p[0],i));
        }
    }
    for (auto i : s) vv.pb(i);
    for (int i = 0; i < vv.size(); i++)
        if (c[vv[i]].size())
        {
            if (vv[i] * vv[i] > (ll)1e6) break;
            slv(vv[i]);
        }
    
    if (ans == 1e9) ans = -1;
    cout << ans;
    return 0;
}