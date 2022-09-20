#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300300;

int n;
int tim;
int tin[N];
int tout[N];
int t[4 * N];
int f[N];
int res, cnt;
vector < int > v[N], g[N];

void dfs(int x)
{
        tin[x] = ++tim;
        for(int y: g[x]){
                dfs(y);
        }
        tout[x] = tim;
}

vector < pair < int, int > > bc;

void upd(int x, int g)
{
        while(x < N){
                f[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += f[x];
                x -= x & -x;
        }
        return res;
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] = y;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
}

int get(int x ,int l, int r, int g)
{
        if(t[x]){
                return t[x];
        }
        if(l == r){
                return 0;
        }
        int m = (l + r) / 2;
        if(g <= m){
                return get(x * 2, l, m, g);
        }
        return get(x * 2 + 1, m + 1, r, g);
}

void solve(int x)
{
        upd(tin[x], 1);

        int l = bc.size(), shit = 0;
        int z = get(1, 1, n, tin[x]);
        if(z > 0){
                upd(1, 1, n, tin[z], tout[z], 0);
                bc.push_back({z, z});
                cnt -= 1;
                shit -= 1;
        }
        if(get(tout[x]) == get(tin[x])){
                upd(1, 1, n, tin[x], tout[x], x);
                bc.push_back({x, 0});
                cnt += 1;
                shit += 1;
        }

        res = max(res, cnt);

        for(int y: v[x]){
                solve(y);
        }

        upd(tin[x], -1);
        while(bc.size() > l){
                int z = bc.back().fi;
                upd(1, 1, n, tin[z], tout[z], bc.back().se);
                bc.pop_back();
        }
        cnt -= shit;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                g[i].clear();
                f[i] = 0;
                tin[i] = tout[i] = 0;
        }
        tim = 0;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                g[x].push_back(i);
        }

        for(int i = 1; i <= 4 * n; i++){
                t[i] = 0;
        }

        res = cnt = 0;

        dfs(1);

        solve(1);

        cout << res << "\n";
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