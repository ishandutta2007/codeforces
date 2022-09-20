#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;

int n;
int tim;
int tin[N];
int tout[N];
int dip[N];
int s[N];
int f[N][19];
vector < int > v[N];

void dfs(int x, int p)
{
        f[x][0] = p;
        for(int i = 1; i < 19; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }

        tin[x] = ++tim;
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dip[y] = dip[x] + 1;
                dfs(y, x);
                s[x] += s[y];
        }
        tout[x] = tim;
}

bool isp(int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        } else if(isp(y, x)){
                return y;
        }
        for(int i = 18; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

int jump(int x, int g)
{
        for(int i = 0; i < 19; i++){
                if(g & (1 << i)){
                        x = f[x][i];
                }
        }
        return x;
}

bool isin(int x, int y, int p, int c)
{
        if(isp(p, c) && (isp(c, x) || isp(c, y))){
                return true;
        }
        return false;
}

long long sq(int x)
{
        return 1ll * x * (x - 1) / 2;
}

long long get(int x, int y, int p)
{
        if(dip[x] > dip[y]){
                swap(x, y);
        }

        long long res = 0;
        if(isp(x, y)){
                if(x == y){
                        res = sq(n - s[x]);
                        for(int y: v[x]){
                                if(isp(x, y)){
                                        res += sq(s[y]);
                                }
                        }
                        res = sq(n) - res;
                } else{
                        res = 1ll * s[y] * (n - s[jump(y, dip[y] - dip[x] - 1)]);
                }
        } else{
                assert(!isp(y, x));
                res = 1ll * s[x] * s[y];
        }

        return res;
}

long long res[N];

void solve()
{
        cin >> n;

        tim = 0;
        for(int i = 0; i <= n; i++){
                v[i].clear();
                res[i] = 0;
        }

        for(int i = 0; i < n - 1; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        dfs(0, 0);

        int X = 0, Y = 0, P = 0;
        res[0] = sq(n);
        res[1] = get(X, Y, P);
        vector<pair<int, int>> can;
        for(int i = 1; i < n; i++){
                int px = lca(X, i);
                int py = lca(Y, i);
                if(isin(Y, X, P, i)){

                } else if(isin(X, i, px, Y)){
                        Y = i;
                        P = px;
                } else if(isin(Y, i, py, X)){
                        X = i;
                        P = py;
                } else{
                        break;
                }
                res[i + 1] = get(X, Y, P);
        }
        res[n + 1] = 0;

        for(int i = 0; i <= n; i++){
                cout << res[i] - res[i + 1] << " ";
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}