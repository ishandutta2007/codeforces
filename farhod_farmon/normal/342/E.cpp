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
const long long MX = sqrt(N);
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int s[N];
int ans[N];
bool dead[N];
vector < int > v[N];
vector < int > r[N];
vector < int > g[N];
set < pair < int, int > > t[N];

void add(int x, pair < int, int > p)
{
        while(x < N){
                t[x].insert(p);
                x += x & -x;
        }
}

void del(int x, pair < int, int > p)
{
        while(x < N){
                t[x].erase(p);
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 1e9;
        while(x > 0){
                if(!t[x].empty()){
                        cnt = min(cnt, t[x].begin()->fi);
                }
                x -= x & -x;
        }
        return cnt;
}

void upd(int x, int l, bool f)
{
        for(int y: r[x]){
                if(f){
                        add(y, {l,  x});
                }
                else{
                        del(y, {l, x});
                }
        }
}

void dfs(int x, int p, bool f, int g = 1)
{
        upd(x, g, f);
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                dfs(y, x, f, g + 1);
        }
}

void trace(int x, int p, int l = 1)
{
        for(int y: g[x]){
                ans[y] = min(ans[y], get(y) + l);
        }
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                trace(y, x, l + 1);
        }
}

void con(int x)
{
        upd(x, 0, 1);
        for(int i = 0; i < v[x].size(); i++){
                int y = v[x][i];
                if(y == x || dead[y]){
                        continue;
                }
                trace(y, x);
                dfs(y, x, 1);
        }
        for(int y: g[x]){
                ans[y] = min(ans[y], get(y));
        }
        for(int i = 0; i < v[x].size(); i++){
                int y = v[x][i];
                if(y == x || dead[y]){
                        continue;
                }
                dfs(y, x, 0);
                trace(y, x);
        }
        upd(x, 0, 0);
}

void dfs_s(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                dfs_s(y, x);
                s[x] += s[y];
        }
}

int get_c(int x, int p, int sz)
{
        int mx = sz - s[x];
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                int g = get_c(y, x, sz);
                mx = max(mx, s[y]);
                if(g != -1){
                        return g;
                }
        }
        if(mx <= sz / 2){
                return x;
        }
        return -1;
}

void dv(int x)
{
        dfs_s(x, x);
        int root = get_c(x, x, s[x]);
        dead[root] = true;
        con(root);
        for(int y: v[root]){
                if(dead[y] == false){
                        dv(y);
                }
        }
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        r[1].pb(1);
        for(int i = 1; i <= q; i++){
                int t, x;
                cin >> t >> x;
                if(t == 1){
                        r[x].pb(i);
                        ans[i] = -1;
                }
                else{
                        g[x].pb(i);
                        ans[i] = 1e9;
                }
        }
        dv(1);
        for(int i = 1; i <= q; i++){
                if(ans[i] != -1){
                        cout << ans[i] << endl;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}