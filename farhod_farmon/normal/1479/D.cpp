#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long M = (1ll << 30);
int my_rand()
{
        return rng();
}

int n, q;
int a[N];
int A[N], B[N], C[N];
int tl[N], tr[N], f[N];
int h[N];

int tim;
int tin[N];
int tout[N];
int ff[N][21];

vector < int > v[N], g[N], qu[N];

void dfs(int x, int p)
{
        ff[x][0] = p;
        for(int i = 1; i < 21; i++){
                ff[x][i] = ff[ff[x][i - 1]][i - 1];
        }

        tin[x] = ++tim;
        g[a[x]].push_back(x);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
        tout[x] = tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        } else if(isp(y, x)){
                return y;
        }
        for(int i = 20; i >= 0; i--){
                if(!isp(ff[x][i], y)){
                        x = ff[x][i];
                }
        }
        return ff[x][0];
}

int aa[N];
int t[N];
int cur[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] ^= y;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res ^= t[x];
                x -= x & -x;
        }
        return res;
}

void solve()
{
        for(int i = 1; i <= n + 1; i++){
                qu[i].clear();
                aa[i] = 0;
                t[i] = 0;
        }
        for(int i = 1, m; i <= q; i++){
                if(tl[i] != tr[i]){
                        m = (tl[i] + tr[i]) / 2;
                        cur[i] = 0;
                        qu[tl[i]].push_back(i);
                        qu[m + 1].push_back(i);
                }
        }
        //exit(0);
        for(int i = n; i >= 1; i--){
                for(int j: g[i]){
                        aa[j] = h[i];
                        upd(tin[j], h[i]);
                        upd(tout[j] + 1, h[i]);
                }
                for(int j: qu[i]){
                        cur[j] ^= get(A[j]);
                        cur[j] ^= get(B[j]);
                        cur[j] ^= aa[C[j]];
                }
        }
        for(int i = 1, m; i <= q; i++){
                if(tl[i] != tr[i]){
                        m = (tl[i] + tr[i]) / 2;
                        if(cur[i]){
                                tr[i] = m;
                        } else{
                                tl[i] = m + 1;
                        }
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++){
                scanf("%d", a + i);

                h[i] = my_rand();
        }
        for(int i = 1; i < n; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        for(int i = 1; i <= q; i++){
                scanf("%d%d%d%d", A + i, B + i, tl + i, f + i);
                tr[i] = n + 1;
                C[i] = lca(A[i], B[i]);

                A[i] = tin[A[i]];
                B[i] = tin[B[i]];
        }

        while(true){
                bool done = true;
                for(int i = 1; i <= q; i++){
                        if(tl[i] != tr[i]){
                                done = false;
                        }
                }
                if(done){
                        break;
                }
                solve();
        }
        for(int i = 1; i <= q; i++){
                if(tr[i] > f[i]){
                        printf("-1\n");
                } else{
                        printf("%d\n", tr[i]);
                }
        }
}