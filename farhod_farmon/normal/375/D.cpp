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
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int f[N];
int c[N];
int s[N];
int ans[N];
vector < int > v[N];
vector < int > *chil[N];
vector < pair < int, int > > g[N];

int get(int x)
{
        int cnt = 0;
        while(x > 0){
                cnt += f[x];
                x -= x & -x;
        }
        return cnt;
}

void upd(int x, int g)
{
        while(x < N){
                f[x] += g;
                x += x & -x;
        }
}

void add(int x)
{
        upd(n - c[x] + 1, -1);
        c[x]++;
        upd(n - c[x] + 1, 1);
}

void del(int x)
{
        upd(n - c[x] + 1, -1);
        c[x]--;
        upd(n - c[x] + 1, 1);
}

int query(int x)
{
        return get(n - x + 1);
}

void dfs(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
        }
}

void trace(int x, int p, int cl)
{
        int big = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                if(s[y] > s[big]){
                        big = y;
                }
        }
        for(int y: v[x]){
                if(y == p || y == big){
                        continue;
                }
                trace(y, x, 1);
        }
        if(big){
                trace(big, x, 0);
                chil[x] = chil[big];
        }
        else{
                chil[x] = new vector < int >;
        }
        add(a[x]);
        chil[x]->pb(a[x]);
        for(int y: v[x]){
                if(y == p || y == big){
                        continue;
                }
                for(int h: *chil[y]){
                        add(h);
                        chil[x]->pb(h);
                }
        }
        for(auto p: g[x]){
                ans[p.se] = query(p.fi);
        }
        if(cl){
                for(int y: *chil[x]){
                        del(y);
                }
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                g[x].pb({y, i});
        }
        dfs(1, 1);
        trace(1, 1, 0);
        for(int i = 1; i <= m; i++){
                cout << ans[i] << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("curling.in");
        //fout("curling.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}