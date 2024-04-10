#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int q;
int tim;
int tin[N];
int tout[N];
int dip[N];
int u[N][21];
vector < int > v[N];

void dfs(int x, int p)
{
        tin[x] = ++tim;
        u[x][0] = p;
        for(int i = 1; i < 21; i++){
                u[x][i] = u[u[x][i - 1]][i - 1];
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dip[y] = dip[x] + 1;
                dfs(y, x);
        }
        tout[x] = tim;
}

int t[4 * N];
int d[4 * N];
int z[4 * N];

void comb(int x)
{
        t[x] = t[x * 2 + 1];
        d[x] = d[x * 2 + 1];
        if(d[x * 2] > d[x]){
                d[x] = d[x * 2];
                t[x] = t[x * 2];
        }
        else if(d[x * 2] == d[x]){
                t[x] += t[x * 2];
        }
}

void push(int x)
{
        if(z[x]){
                d[x * 2] += z[x];
                d[x * 2 + 1] += z[x];
                z[x * 2] += z[x];
                z[x * 2 + 1] += z[x];
                z[x] = 0;
        }
}

void build(int x, int l, int r)
{
        if(l == r){
                d[x] = 0;
                t[x] = 1;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = t[x * 2] + t[x * 2 + 1];
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                d[x] += g;
                z[x] += g;
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), g);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
        comb(x);
}

int get(int x, int dif)
{
        for(int i = 20; i >= 0; i--){
                if(dif & (1 << i)){
                        x = u[x][i];
                }
        }
        return x;
}

map < pair < int, int >, int > ff;

void solve()
{
        cin >> n >> q;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        build(1, 1, n);
        int all = 0;
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                if(x > y){
                        swap(x, y);
                }
                int g = ff[{x, y}];
                ff[{x, y}] ^= 1;
                if(g == 0){
                        g = 1;
                }
                else{
                        g = -1;
                }
                all += g;
                if(tin[x] <= tin[y] && tout[x] >= tout[y]){
                        int p = get(y, dip[y] - dip[x] - 1);
                        upd(1, 1, n, 1, n, g);
                        upd(1, 1, n, tin[p], tout[p], -g);
                        upd(1, 1, n, tin[y], tout[y], g);
                }
                else if(tin[y] <= tin[x] && tout[y] >= tout[x]){
                        int p = get(x, dip[x] - dip[y] - 1);
                        upd(1, 1, n, 1, n, g);
                        upd(1, 1, n, tin[p], tout[p], -g);
                        upd(1, 1, n, tin[x], tout[x], g);
                }
                else{
                        upd(1, 1, n, tin[x], tout[x], g);
                        upd(1, 1, n, tin[y], tout[y], g);
                }
                if(d[1] == all){
                        cout << t[1] << "\n";
                }
                else{
                        cout << 0 << "\n";
                }
        }

}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int test = 1;
        while(test--){
                solve();
        }
}