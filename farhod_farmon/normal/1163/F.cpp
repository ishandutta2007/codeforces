#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int q;
int a[N];
int b[N];
int w[N];
int L[N];
int R[N];
long long d1[N];
long long d2[N];
long long t[4 * N];
vector < int > v[N];

void djk(int x, long long d[])
{
        for(int i = 1; i <= n; i++){
                d[i] = 1e18;
        }
        set < pair < long long, int > > s;
        s.insert({0, x});
        d[x] = 0;
        while(!s.empty()){
                x = s.begin()->se;
                s.erase(s.begin());
                for(int i: v[x]){
                        int y = a[i] ^ b[i] ^ x;
                        if(d[x] + w[i] < d[y]){
                                s.erase({d[y], y});
                                d[y] = d[x] + w[i];
                                s.insert({d[y], y});
                        }
                }
        }
}

bool used[N];
bool e[N];

void dfs(int x, int res, int tp)
{
        if(used[x]){
                return;
        }
        if(tp == 1){
                L[x] = res;
        } else{
                R[x] = res;
        }
        used[x] = true;
        for(int i: v[x]){
                if(e[i]){
                        continue;
                }
                int y = a[i] ^ b[i] ^ x;
                if(d1[x] + w[i] != d1[y] && tp == 1){
                        continue;
                }
                if(d2[x] + w[i] != d2[y] && tp == 2){
                        continue;
                }
                dfs(y, res, tp);
        }
}

int pos[N];

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        }
        assert(l <= tl && tr <= r);
        if(l == tl && r == tr){
                t[x] = min(t[x], y);
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
}

long long get(int x, int l, int r, int g)
{
        assert(l <= r);
        if(l == r){
                return t[x];
        }
        int m = (l + r) / 2;
        if(g <= m){
                return min(t[x], get(x * 2, l, m, g));
        } else{
                return min(t[x], get(x * 2 + 1, m + 1, r, g));
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= m; i++){
                int x, y;
                scanf("%d%d%d", &x, &y, &w[i]);
                a[i] = x;
                b[i] = y;
                v[x].push_back(i);
                v[y].push_back(i);
        }
        djk(1, d1);
        djk(n, d2);
        vector < int > g;
        int x = 1;
        while(x != n){
                g.push_back(x);
                bool good = false;
                for(int i: v[x]){
                        int y = a[i] ^ b[i] ^ x;
                        if(d2[y] + w[i] == d2[x]){
                                pos[i] = g.size();
                                e[i] = true;
                                good = true;
                                x = y;
                                break;
                        }
                }
                if(!good){
                        assert(0);
                }
                assert((int)g.size() < n);
        }
        g.push_back(n);
        for(int i = 0; i < g.size(); i++){
                dfs(g[i], i, 1);
        }
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        for(int i = (int)g.size() - 1; i >= 0; i--){
                dfs(g[i], i, 2);
        }
        for(int i = 1; i < 4 * N; i++){
                t[i] = 1e18;
        }
        for(int i = 1; i <= m; i++){
                int x = a[i], y = b[i];
                if(e[i]){
                        continue;
                }
                if(L[x] < R[y]){
                        upd(1, 1, g.size() - 1, L[x] + 1, R[y], d1[x] + d2[y] + w[i]);
                }
                swap(x, y);
                if(L[x] < R[y]){
                        upd(1, 1, g.size() - 1, L[x] + 1, R[y], d1[x] + d2[y] + w[i]);
                }
        }
        for(int i = 1; i <= q; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                long long res = 1e18;
                if(!e[x]){
                        res = d1[n];
                        res = min(res, d1[a[x]] + d2[b[x]] + y);
                        res = min(res, d1[b[x]] + d2[a[x]] + y);
                } else if(y <= w[x]){
                        res = d1[n] - w[x] + y;
                } else{
                        res = min(res, d1[a[x]] + d2[b[x]] + y);
                        res = min(res, d1[b[x]] + d2[a[x]] + y);
                        res = min(res, get(1, 1, g.size() - 1, pos[x]));
                }
                printf("%lld\n", res);
        }
}