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
const long long MX = 11;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int tim;
int p[N];
int dip[N];
int tin[N];
int tout[N];
int up[N][20];
bool used[N];
vector < int > v[N], g[N], d[N], s[N];

int get(int x)
{
        if(x == p[x]){
                return x;
        }
        return p[x] = get(p[x]);
}

void dfs(int x, int p)
{
        tin[x] = ++tim;
        dip[x] = dip[p] + 1;
        used[x] = true;
        up[x][0] = p;
        for(int i = 1; i < 20; i++){
                up[x][i] = up[up[x][i - 1]][i - 1];
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
        tout[x] = ++tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        }
        if(isp(y, x)){
                return y;
        }
        for(int i = 19; i >= 0; i--){
                if(!isp(up[x][i], y)){
                        x = up[x][i];
                }
        }
        return up[x][0];
}

int len(int x, int y)
{
        int g = lca(x, y);
        return dip[x] + dip[y] - 2 * dip[g];
}

map < pair < int, int >, long double > hsh;

void solve()
{
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
                x = get(x);
                y = get(y);
                if(x != y){
                        p[x] = y;
                }
        }
        for(int i = 1; i <= n; i++){
                int x = get(i);
                g[x].pb(i);
                if(used[x] == false){
                        dfs(x, x);
                }
        }
        for(int i = 1; i <= n; i++){
                if(g[i].empty()){
                        continue;
                }
                pair < int, int > p = {i, i};
                for(int y: g[i]){
                        vector < pair < int, pair < int, int > > > gg;
                        gg.pb({len(p.fi, p.se), p});
                        gg.pb({len(p.fi, y), {p.fi, y}});
                        gg.pb({len(p.se, y), {p.se, y}});
                        sort(gg.begin(), gg.end());
                        p = gg.back().se;
                }
                for(int y: g[i]){
                        d[i].pb(max(len(p.fi, y), len(p.se, y)));
                }
                sort(d[i].begin(), d[i].end());
                s[i].resize(d[i].size());
                for(int j = d[i].size() - 1; j >= 0; j--){
                        s[i][j] = d[i][j];
                        if(j < d[i].size() - 1){
                                s[i][j] += s[i][j + 1];
                        }
                }
        }
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                x = get(x);
                y = get(y);
                if(x == y){
                        cout << -1 << endl;
                        continue;
                }
                if(g[x].size() > g[y].size() || g[x].size() == g[y].size() && x > y){
                        swap(x, y);
                }
                if(hsh.find({x, y}) != hsh.end()){
                        cout << fixed << setprecision(9) << hsh[{x, y}] << endl;
                        continue;
                }
                long long ans = 0;
                for(int cc: d[x]){
                        int l = 0, r = d[y].size() - 1;
                        int need = max(d[x].back(), d[y].back()) - cc - 1;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(d[y][m + 1] <= need){
                                        l = m + 1;
                                }
                                else{
                                        r = m;
                                }
                        }
                        if(d[y][l] <= need){
                                ans += 1ll * max(d[x].back(), d[y].back()) * (l + 1);
                        }
                        else{
                                ans += d[y][l] + cc + 1;
                        }
                        if(l + 1 < d[y].size() && d[y][l + 1] > need){
                                ans += 1ll * (d[y].size() - l - 1) * (cc + 1) + s[y][l + 1];
                        }
                }
                long long len = 1ll * g[x].size() * g[y].size();
                long double gg = 1.0 * ans / len;
                hsh[{x, y}] = gg;
                cout << fixed << setprecision(9) << gg << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}