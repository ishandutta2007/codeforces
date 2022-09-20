#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int q;
int a[N];
int s[N];
int tim;
int st[N];
int inv[N];
int tin[N];
int par[N];
int last[N];
int tout[N];
int f[N][18];
vector<int> v[N];

void dfs(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]) if(y != p){
                dfs(y, x);
                s[x] += s[y];
        }
}

void trace(int x, int p)
{
        tin[x] = ++tim;
        inv[tim] = x;

        f[x][0] = p;
        for(int i = 1; i < 18; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }

        if(!st[x]){
                st[x] = tin[x];
        }
        sort(v[x].begin(), v[x].end(), [&](int i, int j){return s[i] > s[j];});
        for(int y: v[x]) if(y != p){
                if(!last[x]){
                        st[y] = st[x];
                }
                par[y] = x;
                trace(y, x);
                if(!last[x]){
                        last[x] = last[y];
                }
        }
        if(!last[x]){
                last[x] = tin[x];
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
        for(int i = 17; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

long long t[N];

void upd(int x, int y)
{
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

long long get(int x)
{
        long long res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

long long get(int x, int p)
{
        long long res = 0;
        while(isp(p, x)){
                if(isp(p, inv[st[x]])){
                        res += get(tin[x]) - get(st[x] - 1);
                        x = par[inv[st[x]]];
                } else{
                        res += get(tin[x]) - get(tin[p] - 1);
                        break;
                }
        }
        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] = abs(a[i]);
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        trace(1, 1);
        for(int i = 1; i <= n; i++){
                upd(tin[i], a[i]);
        }
        for(int i = 1; i <= q; i++){
                int t, x, y;
                cin >> t >> x >> y;
                if(t == 1){
                        upd(tin[x], - a[x]);
                        a[x] = abs(y);
                        upd(tin[x], a[x]);
                } else{
                        int p = lca(x, y);
                        long long res = 0;

                        res += get(x, p) * 2 - a[x] - a[p];
                        res += get(y, p) * 2 - a[y] - a[p];

                        cout << res << "\n";
                }
        }
}