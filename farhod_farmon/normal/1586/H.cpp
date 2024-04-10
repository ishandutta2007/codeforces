#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;

using namespace std;

struct fenw
{
        int t[N];
        void upd(int x, int g)
        {
                while(x < N){
                        t[x] += g;
                        x += x & -x;
                }
        }
        int get(int x)
        {
                int res = 0;
                while(x > 0){
                        res += t[x];
                        x -= x & -x;
                }
                return res;
        }
};

int n;
int q;
int a[N], b[N];
int A[N], B[N];
pair<int, int> t2[N], t1[N];

int p[N];
int s[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

int tim;
int tin[N];
int tout[N];
int f[N][20];
fenw F;

void dfs_1(int x, int p)
{
        if(x == 0){
                return;
        }

        f[x][0] = p;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }

        tin[x] = ++tim;
        dfs_1(t2[x].fi, x);
        dfs_1(t2[x].se, x);
        tout[x] = tim;
}

int id[N];
vector<int> qu[N];
pair<int, int> res[N];
int tin_[N], tout_[N], inv[N];
unordered_map<int, vector<int>> pos;

void upd(int x, int g)
{
        F.upd(tin[x], g);
}

int get_sol(int x)
{
        int all = F.get(N - 1);
        for(int i = 19; i >= 0; i--){
                int y = f[x][i];
                if(F.get(tout[y]) - F.get(tin[y] - 1) < all){
                        x = f[x][i];
                }
        }
        if(F.get(tout[x]) - F.get(tin[x] - 1) < all){
                x = f[x][0];
        }
        return b[x];
}

void add(int x, int c, int g)
{
        if(!x){
                return;
        }
        //return;
        vector<int> &shit = pos[c];
        int l = lower_bound(shit.begin(), shit.end(), tin_[x]) - shit.begin();
        while(l < shit.size() && shit[l] <= tout_[x]){
                upd(inv[shit[l]], g);
                l += 1;
        }
}

void solve(int x, int ch = 0)
{
        tin_[x] = ++tim;
        inv[tim] = x;
        if(x <= n){
                pos[a[x]].push_back(tim);
        }

        int y1 = t1[x].fi, y2 = t1[x].se;
        if(y1){
                solve(y1, 1);
                solve(y2, 0);
        }
        tout_[x] = tim;

        if(a[x] == a[y1]){
                add(y1, a[x], 1);
        }
        if(a[x] != a[y2]){
                add(y2, a[y2], -1);
                add(y2, a[x], 1);
        }
        if(x <= n){
                upd(x, 1);
        }

        for(int i : qu[x]){
                res[i].se = get_sol(id[i]);
        }

        if(!ch){
                return;
        }
        if(x <= n){
                upd(x, -1);
        }
        add(y1, a[x], -1);
        add(y2, a[x], -1);
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
        }
        vector<pair<int, int>> C, D;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> A[i] >> B[i] >> x >> y;
                C.push_back({x, i});
                D.push_back({y, i});
        }

        sort(D.begin(), D.end());

        for(int i = 1; i < N; i++){
                p[i] = i;
                s[i] = 1;
        }
        int G = n;
        for(auto p : D){
                G += 1;
                int x = A[p.se], y = B[p.se];
                x = get(x);
                y = get(y);
                ::p[x] = G;
                ::p[y] = G;
                s[G] = s[x] + s[y];
                b[G] = p.fi;
                if(s[x] > s[y]){
                        t2[G] = {y, x};
                } else{
                        t2[G] = {x, y};
                }
        }
        dfs_1(G, G);

        for(int i = 0; i < q; i++){
                int v;
                cin >> v >> id[i];
                C.push_back({v, -i});
        }

        for(int i = 1; i < N; i++){
                p[i] = i;
                s[i] = 1;
        }

        int inf = 1e9;
        G = n;
        sort(C.rbegin(), C.rend());
        for(auto p : C){
                if(p.se > 0){
                        G += 1;
                        int x = A[p.se], y = B[p.se];
                        x = get(x);
                        y = get(y);
                        ::p[x] = G;
                        ::p[y] = G;
                        s[G] = s[x] + s[y];
                        a[G] = max(a[x], a[y]);
                        if(s[x] > s[y]){
                                t1[G] = {y, x};
                        } else{
                                t1[G] = {x, y};
                        }
                } else{
                        int x = id[-p.se];
                        x = get(x);
                        res[-p.se].fi = a[x];
                        if(x > n){
                                qu[x].push_back(-p.se);
                                res[-p.se].se = inf;
                        }
                }
        }

        tim = 0;
        solve(G);

        for(int i = 0; i < q; i++){
                cout << res[i].fi << " " << res[i].se << "\n";
        }
}