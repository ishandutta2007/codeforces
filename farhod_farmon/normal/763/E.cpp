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
int k;
int m;
int l[4 * N];
int r[4 * N];
int c[4 * N];
vector < int > g;
vector < int > v[N];
vector < int > p[4 * N];
vector < bool > used[4 * N];
vector < pair < int, int > > rl[4 * N];

void build(int x, int tl, int tr)
{
        l[x] = tl;
        r[x] = tr;
        if(tl == tr)
        {
                c[x] = 1;
                p[x].pb(tl);
                used[x].pb(0);
                return;
        }
        int tm = (tl + tr) / 2;
        build(x * 2, tl, tm);
        build(x * 2 + 1, tm + 1, tr);
        for(int i = tl; i <= tm; i++)
        {
                p[x].pb(p[x * 2][i - tl]);
                used[x].pb(0);
        }
        for(int i = tm + 1; i <= tr; i++)
        {
                p[x].pb(p[x * 2 + 1][i - tm - 1]);
                used[x].pb(0);
        }
        c[x] = c[x * 2] + c[x * 2 + 1];
        for(int i = tl; i <= tr; i++)
        {
                for(int j: v[i])
                {
                        if(j < tl || j > tr)
                        {
                                continue;
                        }
                        int pi = i;
                        int pj = j;
                        while(p[x][pi - tl] != pi)
                        {
                                pi = p[x][pi - tl];
                        }
                        while(p[x][pj - tl] != pj)
                        {
                                pj = p[x][pj - tl];
                        }
                        if(pi != pj)
                        {
                                p[x][pi - tl] = p[x][pj - tl];
                                c[x]--;
                        }
                }
        }
        for(int i = tl; i <= tr; i++)
        {
                int pi = i;
                while(p[x][pi - tl] != pi)
                {
                        pi = p[x][pi - tl];
                }
                p[x][i - tl] = pi;
        }
}

void get(int x, int tl, int tr)
{
        if(tl > tr)
        {
                return;
        }
        if(l[x] == tl && r[x] == tr)
        {
                g.pb(x);
                return;
        }
        get(x * 2, tl, min(tr, r[x * 2]));
        get(x * 2 + 1, max(tl, l[x * 2 + 1]), tr);
}


void upd(int x, int tl, int tr)
{
        if(tl > tr)
        {
                return;
        }
        if(tl == l[x] && tr == r[x])
        {
                for(auto f: rl[x])
                {
                        p[x][f.fi] = f.se;
                        used[x][f.fi] = 0;
                }
                rl[x].clear();
                return;
        }
        upd(x * 2, tl, min(tr, r[x * 2]));
        upd(x * 2 + 1, max(tl, l[x * 2 + 1]), tr);
}

int get_group(int x)
{
        for(int i = 0; i < g.size(); i++)
        {
                int f = g[i];
                if(l[f] <= x && x <= r[f])
                {
                        return f;
                }
        }
}

void solve()
{
        cin >> n >> k >> m;
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        build(1, 1, n);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++)
        {
                g.clear();
                int tl, tr;
                cin >> tl >> tr;
                get(1, tl, tr);
                int cnt = c[g.back()];
                for(int gg = 0; gg + 1 < g.size(); gg++)
                {
                        int group = g[gg];
                        cnt += c[group];
                        for(int x = r[group]; x >= max(l[group], r[group] - k); x--)
                        {
                                for(int y: v[x])
                                {
                                        if(y <= r[group] || y > tr || y < tl)
                                        {
                                                continue;
                                        }
                                        int px = x;
                                        int py = y;
                                        int gx = get_group(px);
                                        int gy = get_group(py);
                                        while(p[gx][px - l[gx]] != px)
                                        {
                                                px = p[gx][px - l[gx]];
                                                gx = get_group(px);
                                        }
                                        while(p[gy][py - l[gy]] != py)
                                        {
                                                py = p[gy][py - l[gy]];
                                                gy = get_group(py);
                                        }
                                        if(px != py)
                                        {
                                                if(!used[gx][px - l[gx]])
                                                {
                                                        used[gx][px - l[gx]] = true;
                                                        rl[gx].pb({px - l[gx], p[gx][px - l[gx]]});
                                                }
                                                p[gx][px - l[gx]] = p[gy][py - l[gy]];
                                                cnt--;
                                        }
                                }
                        }
                }
                upd(1, tl, tr);
                cout << cnt << endl;
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