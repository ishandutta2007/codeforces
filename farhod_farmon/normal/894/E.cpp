#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;
int m;
int c[N];
bool used[N];
long long f[N];
long long d[N];
vector < int > order;
map < pair < int, int >, int > cost;
vector < pair < int, int > > new_v[N], v[N], g[N];

void dfs(int x)
{
        used[x] = true;
        for(auto y: v[x]){
                if(used[y.fi]){
                        continue;
                }
                dfs(y.fi);
        }
        order.push_back(x);
}

void trace(int x, int col)
{
        c[x] = col;
        used[x] = true;
        for(auto y: g[x]){
                if(used[y.fi]){
                        continue;
                }
                trace(y.fi, col);
        }
}

long long go(int x)
{
        used[x] = true;
        for(auto y: new_v[x]){
                if(!used[y.fi]){
                        go(y.fi);
                }
                d[x] = max(d[x], d[y.fi] + y.se);
        }
        d[x] += f[x];
        return d[x];
}

long long get(int w)
{
        int l = 0, r = 2e4;
        while(l < r){
                int m = (l + r) / 2 + 1;
                if(m * (m + 1) / 2 <= w){
                        l = m;
                }
                else{
                        r = m - 1;
                }
        }
        return 1ll * w * (l + 1) - d[l];
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                g[y].push_back({x, w});
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
        }
        for(int i = 1; i < N / 10; i++){
                d[i] = d[i - 1] + 1ll * i * (i + 1) / 2;
        }
        for(int i = 1; i <= n; i++){
                used[i] = false;
        }
        int C = 0;
        for(int i = n - 1; i >= 0; i--){
                if(!used[order[i]]){
                        trace(order[i], ++C);
                }
        }
        for(int i = 1; i <= n; i++){
                used[i] = false;
                for(auto y: v[i]){
                        if(c[i] != c[y.fi]){
                                new_v[c[i]].push_back({c[y.fi], y.se});
                        }
                        else{
                                f[c[i]] += get(y.se);
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                d[i] = 0;
        }
        int s;
        cin >> s;
        cout << go(c[s]) << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}