#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150500;
const long long mod = 998244353;
const int MAGIC = 222;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        x %= mod;
        while(n > 0){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int n;
int q;
int tim;
int s[N];
int tin[N];
int tout[N];
int f[N][20];
int dip[N];
vector < int > v[N];
vector < pair < int, int > > group[N];

void trace(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                trace(y, x);
                s[x] += s[y];
        }
        sort(v[x].begin(), v[x].end(), [&](int x, int y){
             return s[x] < s[y];
             });
}

void dfs(int x, int p)
{
        tin[x] = ++tim;
        f[x][0] = p;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dip[y] = dip[x] + 1;
                dfs(y, x);
        }
        tout[x] = tim;
        for(int i = 0, j = -1; i < v[x].size(); i++){
                if(v[x][i] == p){
                        continue;
                }
                if(j != s[v[x][i]]){
                        group[x].push_back({i, i});
                } else{
                        group[x].back().se = i;
                }
        }
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int t[N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

void upd_t(int x, int y)
{
        while(x < N){
                add(t[x], y);
                x += x & -x;
        }
}

int get_t(int x)
{
        int res = 0;
        while(x > 0){
                add(res, t[x]);
                x -= x & -x;
        }
        return res;
}

void upd(int tl, int tr, int y)
{
        upd_t(tl, y);
        upd_t(tr + 1, - y);
}

int get(int g)
{
        return get_t(g);
}

int get_u(int x, int l)
{
        for(int i = 0; i < 20; i++){
                if(l & (1 << i)){
                        x = f[x][i];
                }
        }
        return x;
}

int D[N];

void make(int x)
{
        if(D[x] == 0){
                return;
        }
        for(auto p: group[x]){
                int l = v[x][p.fi], r = v[x][p.se];
                upd(tin[l], tout[r], 1ll * D[x] * s[l] % mod);
        }
        D[x] = 0;
}

void rebuild(vector < pair < int, int > > v)
{
        for(auto p: v){
                add(D[p.fi], p.se);
        }
        for(auto p: v){
                make(p.fi);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        trace(1, 1);
        dfs(1, 1);

        vector < pair < int, int > > to_add;
        int to_all = 0;
        int inv = pw(n, mod - 2);
        for(int i = 1; i <= q; i++){
                int t, x, d;
                cin >> t >> x;
                if(t == 1){
                        cin >> d;
                        to_add.push_back({x, d});
                        add(to_all, 1ll * n * d % mod);
                        int shit = - 1ll * (n - s[x]) * d % mod;
                        if(shit < 0){
                                shit += mod;
                        }
                        add(to_all, shit);
                        upd(tin[x], tout[x], shit);
                } else{
                        int res = to_all;
                        add(res, - get(tin[x]));
                        for(auto p: to_add){
                                if(isp(p.fi, x) == false || p.fi == x){
                                        continue;
                                }
                                add(res, - 1ll * s[get_u(x, dip[x] - dip[p.fi] - 1)] * p.se % mod);
                        }
                        //cout << res << "\n";
                        cout << 1ll * res * inv % mod << "\n";
                }
                if(to_add.size() % MAGIC == 0){
                        rebuild(to_add);
                        to_add.clear();
                }
        }
}