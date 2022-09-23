#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int s;
int o[N];
ll d[N];
ll t[4 * N];
ll in[4 * N];
set < pair < int, int > > ed[4 * N];
vector < pair < pair < int, int >, int > > v[N];

void add(int x, int l, int r, int g, int tl, int tr, int w)
{
        if(tl > tr)
        {
                return;
        }
        if(l == tl && r == tr)
        {
                ed[x].insert({g, w});
                return;
        }
        int m = (l + r) / 2;
        add(x * 2, l, m, g, tl, min(m, tr), w);
        add(x * 2 + 1, m + 1, r, g, max(m + 1, tl), tr, w);
}

int comb(int x, int y)
{
        if(d[x] > d[y])
        {
                return x;
        }
        return y;
}

void upd(int x)
{
        for(int i = o[x] / 2; i > 0; i /= 2)
        {
                t[i] = comb(t[i * 2], t[i * 2 + 1]);
        }
}

set < pair < ll, int > > f;

ll get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr)
        {
                return 0;
        }
        if(l == tl && r == tr)
        {
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void build(int x, int l, int r)
{
        if(l == r)
        {
                o[l] = x;
                t[x] = l;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void go(int g)
{
        for(int x = o[g]; x > 0; x /= 2)
        {
                if(!ed[x].empty())
                {
                        for(auto p: ed[x])
                        {
                                if(d[g] + p.se < d[p.fi])
                                {
                                        f.erase({d[p.fi], p.fi});
                                        d[p.fi] = d[g] + p.se;
                                        upd(p.fi);
                                        f.insert({d[p.fi], p.fi});
                                }
                        }
                        ed[x].clear();
                }
        }
}

void solve()
{
        cin >> n >> q >> s;
        for(int i = 1; i <= q; i++)
        {
                int x, l, r, t, w;
                cin >> t;
                if(t == 1)
                {
                        cin >> x >> l >> w;
                        r = l;
                }
                else
                {
                        cin >> x >> l >> r >> w;
                }
                if(t <= 2)
                {
                        v[x].pb({{l, r}, w});
                }
                else
                {
                        add(1, 1, n, x, l, r, w);
                }
        }
        for(int i = 1; i <= n; i++)
        {
                d[i] = 1e18;
        }
        build(1, 1, n);
        d[s] = 0;
        upd(s);
        f.insert({0, s});
        while(!f.empty())
        {
                int x = f.begin()->se;
                f.erase(f.begin());
                for(int i = 0; i < v[x].size(); i++)
                {
                        int l = v[x][i].fi.fi, r = v[x][i].fi.se, w = v[x][i].se;
                        int y = get(1, 1, n, l, r);
                        while(d[x] + w < d[y])
                        {
                                f.erase({d[y], y});
                                d[y] = d[x] + w;
                                upd(y);
                                f.insert({d[y], y});
                                y = get(1, 1, n, l, r);
                        }
                }
                go(x);
        }
        for(int i = 1; i <= n; i++)
        {
                if(d[i] == 1e18)
                {
                        d[i] = -1;
                }
                cout << d[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}