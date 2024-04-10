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
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int h;
int w;
int l[N];
int r[N];
int u[N];
int s[N];
int a[N];
int top[N];
int t[4 * N];
pair < int, int > p[N];
vector < pair < int, int > > v[N];

int comb(int x, int y)
{
        if(x == -1)
        {
                return y;
        }
        if(y == -1)
        {
                return x;
        }
        if(top[x] < top[y])
        {
                return x;
        }
        return y;
}

void build(int x, int tl, int tr)
{
        if(tl == tr)
        {
                t[x] = tl;
                a[tl] = 1;
                top[tl] = h + 1;
                v[tl].pb({h + 1, 1});
                return;
        }
        int tm = (tl + tr) / 2;
        build(x * 2, tl, tm);
        build(x * 2 + 1, tm + 1, tr);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int tl, int tr, int nl, int nr)
{
        if(nl > nr)
        {
                return -1;
        }
        if(nl == tl && nr == tr)
        {
                return t[x];
        }
        int tm = (tl + tr) / 2;
        return comb(get(x * 2, tl, tm, nl, min(tm, nr)), get(x * 2 + 1, tm + 1, tr, max(tm + 1, nl), nr));
}

void upd(int x, int tl, int tr, int g, pair < int, int > y)
{
        if(tl == tr)
        {
                v[tl].pb(y);
                t[x] = tl;
                a[tl] = y.se;
                top[tl] = y.fi;
                return;
        }
        int tm = (tl + tr) / 2;
        if(g <= tm)
        {
                upd(x * 2, tl, tm, g, y);
        }
        else
        {
                upd(x * 2 + 1, tm + 1, tr, g, y);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void er(int x, int tl, int tr, int g)
{
        if(tl == tr)
        {
                v[tl].pop_back();
                if(v[tl].empty())
                {
                        t[x] = -1;
                        a[tl] = 0;
                        top[tl] = 2e9 + 1;
                }
                else
                {
                        t[x] = tl;
                        a[tl] = v[tl].back().se;
                        top[tl] = v[tl].back().fi;
                }
                return;
        }
        int tm = (tl + tr) / 2;
        if(g <= tm)
        {
                er(x * 2, tl, tm, g);
        }
        else
        {
                er(x * 2 + 1, tm + 1, tr, g);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void solve()
{
        cin >> h >> w >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> u[i] >> l[i] >> r[i] >> s[i];
                p[i] = {u[i], i};
        }
        build(1, 1, w);
        sort(p + 1, p + n + 1);
        for(int ii = n; ii >= 1; ii--)
        {
                int cnt = 0;
                int i = p[ii].se;
                int x = get(1, 1, w, l[i], r[i]);
                while(x != -1 && top[x] <= u[i] + s[i])
                {
                        cnt = (cnt + a[x]) % mod;
                        er(1, 1, w, x);
                        x = get(1, 1, w, l[i], r[i]);
                }
                if(cnt == 0)
                {
                        continue;
                }
                if(l[i] > 1 && r[i] < w)
                {
                        upd(1, 1, w, l[i] - 1, {u[i], cnt});
                        upd(1, 1, w, r[i] + 1, {u[i], cnt});
                }
                else if(l[i] > 1)
                {
                        upd(1, 1, w, l[i] - 1, {u[i], (cnt + cnt) % mod});
                }
                else
                {
                        upd(1, 1, w, r[i] + 1, {u[i], (cnt + cnt) % mod});
                }
        }
        int ans = 0;
        for(int i = 1; i <= w; i++)
        {
                while(!v[i].empty())
                {
                        ans = (ans + v[i].back().se) % mod;
                        v[i].pop_back();
                }
        }
        cout << ans << endl;
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