#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int s[N];
int mask[N];
int d[1 << 21];
char c[N];
bool dead[N];
long long f[N];
long long ans[N];
vector < int > v[N];

int dfs(int x, int p, int S)
{
        int mx = 0, g = -1;
        s[x] = 1;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                int gg = dfs(y, x, S);
                s[x] += s[y];
                mx = max(mx, s[y]);
                if(gg != -1){
                        g = gg;
                }
        }
        mx = max(mx, S - s[x]);
        if(mx <= S / 2){
                g = x;
        }
        return g;
}

void trace(int x, int p)
{
        f[x] = 0;
        s[x] = 1;
        mask[x] ^= (1 << (c[x] - 'a'));
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                mask[y] = mask[x];
                trace(y, x);
                s[x] += s[y];
        }
}

void upd(int x, int p, int g)
{
        d[mask[x]] += g;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                upd(y, x, g);
        }
}

int com;

void add(int x)
{
        f[x] += d[mask[x] ^ com];
        for(int i = 0; i < 20; i++){
                int nw = mask[x] ^ (1 << i) ^ com;
                f[x] += d[nw];
        }
}

void get(int x, int p)
{
        add(x);
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                get(y, x);
                f[x] += f[y];
        }
        ans[x] += f[x];
}

void go(int x, int S)
{
        x = dfs(x, x, S);
        com = (1 << (c[x] - 'a'));
        mask[x] = 0;
        trace(x, x);
        upd(x, x, 1);
        add(x);
        long long gg = 0;
        for(int y: v[x]){
                if(y == x || dead[y]){
                        continue;
                }
                upd(y, x, -1);
                get(y, x);
                gg += f[y];
                upd(y, x, 1);
        }
        ans[x] += (gg - (f[x] - 1)) / 2 + f[x];
        upd(x, x, -1);
        dead[x] = 1;
        for(int y: v[x]){
                if(!dead[y]){
                        go(y, s[y]);
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        go(1, n);
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}