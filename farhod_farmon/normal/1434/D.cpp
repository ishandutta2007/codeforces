#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int tim;
int A[N];
int B[N];
int c[N];
int l[N];
int d[N];
int id[N];
int tin[N];
int tout[N];
int f[N][20];
vector < int > v[N];


void dfs(int x, int p)
{
        tin[x] = ++tim;
        f[x][0] = p;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        for(int i: v[x]){
                int y = A[i] ^ B[i] ^ x;
                if(y == p){
                        continue;
                }
                l[y] = l[x] + 1;
                d[y] = d[x] ^ c[i];
                dfs(y, x);
        }
        tout[x] = tim;

        id[tin[x]] = x;
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
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

int len(int x, int y)
{
        return l[x] + l[y] - 2 * l[lca(x, y)];
}

vector < pair < int, int > >  get(int x)
{
        vector < pair < int, int > > res;
        for(int i = 1; i <= n; i++){
                res.push_back({len(x, i), i});
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        return res;
}

int iv[N][3];
vector < pair < int, int > > g[3];
int fl[4 * N];
pair < int, int > f1[4 * N], f2[4 * N];

void app(int x)
{
        fl[x] ^= 1;
        swap(f1[x], f2[x]);
}

void push(int x)
{
        if(fl[x]){
                fl[x] = 0;
                app(x * 2);
                app(x * 2 + 1);
        }
}

int comb(int x)
{
        f1[x].fi = min(f1[x * 2].fi, f1[x * 2 + 1].fi);
        f1[x].se = min(f1[x * 2].se, f1[x * 2 + 1].se);
        f2[x].fi = min(f2[x * 2].fi, f2[x * 2 + 1].fi);
        f2[x].se = min(f2[x * 2].se, f2[x * 2 + 1].se);
}

void build(int x, int l, int r)
{
        f1[x] = f2[x] = {n, n};
        if(l == r){
                int a = id[l];
                if(d[a]){
                        f1[x] = {iv[a][1], iv[a][2]};
                } else{
                        f2[x] = {iv[a][1], iv[a][2]};
                }
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        comb(x);
}

void upd(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                app(x);
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x  * 2, l, m, tl, min(m, tr));
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        comb(x);
}

int get(int x, int l, int r, int y)
{
        if(l == r){
                return d[id[l]] ^ fl[x];
        }
        push(x);
        int m = (l + r) / 2;
        if(y <= m){
                return get(x * 2, l, m, y);
        } else{
                return get(x * 2 + 1, m + 1, r, y);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d", &n);
        for(int i = 1; i < n; i++){
                scanf("%d%d%d", A + i, B + i, c + i);

                v[A[i]].push_back(i);
                v[B[i]].push_back(i);
        }

        dfs(1, 1);

        g[0] = get(1);
        g[1] = get(g[0][0].se);
        g[2] = get(g[1][0].se);

        int X = g[0][0].se;
        int Y = g[1][0].se;

        for(int i = 1; i < 3; i++){
                for(int j = 0; j < n; j++){
                        iv[g[i][j].se][i] = j;
                }
                g[1].push_back({0, 0});
        }

        build(1, 1, n);

        int q;
        scanf("%d", &q);
        while(q--){
                int i;
                scanf("%d", &i);
                int x = A[i], y = B[i];
                if(l[x] < l[y]){
                        swap(x, y);
                }
                upd(1, 1, n, tin[x], tout[x]);

                int res = 0;
                //cout << f1[1].fi << " " << f1[1].se << " " << f2[1].fi << " " << f2[1].se << "\n";
                if(get(1, 1, n, tin[X])){
                        res = max(res, g[1][f1[1].fi].fi);
                } else{
                        res = max(res, g[1][f2[1].fi].fi);
                }
                if(get(1, 1, n, tin[Y])){
                        res = max(res, g[2][f1[1].se].fi);
                } else{
                        res = max(res, g[2][f2[1].se].fi);
                }

                printf("%d\n", res);
        }
}