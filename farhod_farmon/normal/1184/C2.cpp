#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int r;

int si(int x)
{
        return x % 2 ? 1 : 0;
}

int res;

void compress(vector < pair < pair < int, int >, pair < int, int > > > &v)
{
        vector < pair < int, int > > g;
        for(int i = 0; i < v.size(); i++){
                g.push_back({v[i].se.fi, i + 1});
                g.push_back({v[i].se.se, - i - 1});
        }
        sort(g.begin(), g.end());
        for(int i = 0, j = 1; i < g.size(); i++){
                if(i > 0 && g[i].fi != g[i - 1].fi){
                        j += 1;
                }
                int h = g[i].se;
                if(h > 0){
                        v[h - 1].se.fi = j;
                } else{
                        v[- h - 1].se.se = j;
                }
        }
}

int G = N * 2;
int t[8 * N];
int lz[8 * N];

void push(int x)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                lz[x * 2] += lz[x];
                t[x * 2 + 1] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] += g;
                lz[x] += g;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void solve(vector < pair < pair < int, int >, pair < int, int > > > v)
{
        for(int i = 1; i < 8 * N; i++) t[i] = 0;
        compress(v);
        sort(v.begin(), v.end());
        for(auto p: v){
                upd(1, 1, G, p.se.fi, p.se.se, p.fi.se);
                res = max(res, t[1]);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> r;
        vector < pair < pair < int, int >, pair < int, int > > > v[2];
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                int a = x - y, b = x + y;
                for(int j: {0, 1}){
                        int x1 = a - r, x2 = a + r, y1 = b - r, y2 = b + r;
                        if(si(x1) != j)x1 += 1;
                        if(si(x2) != j)x2 -= 1;
                        if(si(y1) != j)y1 += 1;
                        if(si(y2) != j)y2 -= 1;
                        if(x1 <= x2 && y1 <= y2){
                                v[j].push_back({{x1, 1}, {y1, y2}});
                                v[j].push_back({{x2 + 1, -1}, {y1, y2}});
                        }
                }
        }

        solve(v[0]);
        solve(v[1]);

        cout << res << "\n";
}