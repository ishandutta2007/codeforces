#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int l[N];
int r[N];
int tim;
int tin[N];
int tout[N];
long long res[N];
long long d[N];
vector < int > ch;
vector < int > qu[N];
vector < pair < int, int > > v[N];
int gg;

pair < int, int > dfs(int x, long long len)
{
        tin[x] = ++tim;
        auto p = make_pair(tin[x], tin[x]);
        for(auto y: v[x]){
                auto g = dfs(y.fi, len + y.se);
                p.fi = min(p.fi, g.fi);
                p.se = max(p.se, g.se);
        }
        tout[x] = tim;
        assert(p.fi == tin[x]);
        assert(p.se == tout[x]);
        if(v[x].size() == 0){
                assert(ch[gg] == x);
                gg++;
                d[gg] = len;
        }
        return p;
}

long long t[4 * N];
long long lz[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = d[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = min(t[x * 2], t[x * 2 + 1]);
}

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = min(t[x * 2], t[x * 2 + 1]);
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 1e18;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        push(x);
        int m = (l + r) / 2;
        return min(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void solve(int x)
{
        for(int i: qu[x]){
                res[i] = get(1, 1, m, l[i], r[i]);
        }
        for(auto y: v[x]){
                upd(1, 1, m, 1, m, y.se);
                upd(1, 1, m, tin[y.fi], tout[y.fi], - 2 * y.se);
                solve(y.fi);
                upd(1, 1, m, 1, m, - y.se);
                upd(1, 1, m, tin[y.fi], tout[y.fi], + 2 * y.se);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 2; i <= n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({i, y});
        }
        for(int i = 1; i <= n; i++){
                if(v[i].size() == 0){
                        ch.push_back(i);
                }
                else{
                        sort(v[i].begin(), v[i].end());
                }
        }
        m = ch.size();
        dfs(1, 0);
        for(int i = 1; i <= q; i++){
                int x;
                cin >> x >> l[i] >> r[i];
                qu[x].push_back(i);
                l[i] = lower_bound(ch.begin(), ch.end(), l[i]) - ch.begin() + 1;
                r[i] = lower_bound(ch.begin(), ch.end(), r[i] + 1) - ch.begin();
        }
        for(int i = 1; i <= n; i++){
                tin[i] = lower_bound(ch.begin(), ch.end(), tin[i]) - ch.begin() + 1;
                tout[i] = lower_bound(ch.begin(), ch.end(), tout[i] + 1) - ch.begin();
        }
        build(1, 1, m);
        solve(1);
        for(int i = 1; i <= q; i++){
                cout << res[i] << "\n";
        }
}