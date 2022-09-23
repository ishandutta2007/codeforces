#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000000;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int s[N];
int ans;
int root;
int Sz;
bool dead[N];
vector < int > v[N];

int get(int x, int p)
{
        int cnt = 1;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                cnt += get(y, x);
        }
        return cnt;
}

void dfs(int x, int p)
{
        int mx = 0;
        s[x] = 1;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
                mx = max(mx, s[y]);
        }
        mx = max(mx, Sz - s[x]);
        if(mx <= Sz / 2){
                root = x;
        }
}

int S;
int del;

void upd(int x, int p, int g, int ty, int ss)
{
        if(g < 0)g += mod;
        s[x] = 1;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                upd(y, x, (g + a[y] * ty) % mod, - ty, ss);
                s[x] += s[y];
        }
        int l = g - del;
        if(l < 0)l += mod;
        if(ty == -1){
                ans = (ans + (1ll * (Sz - ss) * l % mod)) % mod;
                ans = (ans + S) % mod;
        }
        else{
                if(l > 0){
                        l = - l + mod;
                }
                else{
                        l = - l;
                }
                ans = (ans + (1ll * (Sz - ss) * l % mod)) % mod;
                ans = (ans - S) % mod;
                if(ans < 0)ans += mod;
        }
}

void add(int x, int p, int g, int ty, int o)
{
        if(g < 0)g += mod;
        S = (S + g * o) % mod;
        if(S < 0)S += mod;
        for(int y: v[x]){
                if(y == p || dead[y]){
                        continue;
                }
                add(y, x, (g + a[y] * ty) % mod, - ty, o);
        }
}

void go(int x)
{
        Sz = get(x, x); root = -1;
        dfs(x, x); x = root;dfs(x, x);
        del = a[x];
        S = 0;
        add(x, x, a[x], -1, 1);
        for(int y: v[x]){
                if(dead[y] || y == x){
                        continue;
                }
                add(y, x, a[x] - a[y], 1, -1);
                upd(y, x, a[x] - a[y], 1, s[y]);
                add(y, x, a[x] - a[y], 1, 1);
        }
        ans = (ans + S) % mod;
        dead[x] = 1;
        for(int y: v[x]){
                if(!dead[y]){
                        go(y);
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] < 0)a[i] += mod;
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        go(1);
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}