#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400200;
const int Q = 400200;

using namespace std;

int n;
int tim;
int dip[N];
int tin[N];
int tout[N];
int f[N][20];
vector < int > v[N];

void dfs(int x, int p)
{
        tin[x] = ++tim;
        f[x][0] = p;
        for(int i = 1; i < 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
        for(int y: v[x]){
                if(y == p) continue;
                dip[y] = dip[x] + 1;
                dfs(y, x);
        }
        tout[x] = ++tim;
}

bool isp(int x, int y){ return tin[x] <= tin[y] && tout[x] >= tout[y]; }

int lca(int x, int y)
{
        if(isp(x, y)) return x;
        if(isp(y, x)) return y;
        for(int i = 19; i >= 0; i--) if(!isp(f[x][i], y)) x = f[x][i];
        return f[x][0];
}

int V[N];
int s[N];
int a[N];
int id[N];
int inv[N];
int spec[N];


//int par[N];
//int len[N];
//int dp[N];
vector < pair < int, int > > g[N];

int get_len(int x, int y){return dip[x] + dip[y] - 2 * dip[lca(x, y)];}
void make(set < pair < pair < int, int >, int > > &S, int x)
{
        int i = a[x];
        for(auto p: g[x]){
                if(a[p.fi]){
                        continue;
                }
                S.insert({{(get_len(V[i], inv[p.fi]) - 1) / s[i] + 1, i}, p.fi});
        }
}

pair < int, int > T[N];
void upd_(int x, int y)
{
        while(x < N){
                T[x] = max(T[x], make_pair(tin[y], y));
                x += x & -x;
        }
}
void cler(int x)
{
        while(x < N){
                T[x] = {0, 0};
                x += x & -x;
        }
}
pair < int, int > get_(int x)
{
        pair < int, int > res = {0, 0};
        while(x > 0){
                res = max(res, T[x]);
                x -= x & -x;
        }
        return res;
}

void solve()
{
        int k, m;
        scanf("%d%d", &k, &m);
        vector < int > v;
        for(int i = 1; i <= k; i++){
                scanf("%d%d", V + i, s + i);
                v.push_back(V[i]);
        }
        for(int i = 1; i <= m; i++){
                scanf("%d", spec + i);
                v.push_back(spec[i]);
        }
        sort(v.begin(), v.end(), [&](int x, int y){return tin[x] < tin[y];});
        int len = v.size();
        for(int i = 1; i < len; i++){
                if(v[i] == v[i - 1]){
                        continue;
                }
                v.push_back(lca(v[i - 1], v[i]));
        }
        sort(v.begin(), v.end(), [&](int x, int y){return make_pair(tin[x], x) < make_pair(tin[y], y);});
        vector < int > nv = {v[0]};
        for(int i = 1; i < v.size(); i++) if(v[i] != v[i - 1]) nv.push_back(v[i]);
        v = nv;

        for(int i = 1; i <= v.size(); i++)g[i].clear();
        for(int i = 0, len; i < v.size(); i++){
                auto q = get_(N - tin[v[i]]);
                id[v[i]] = i + 1;
                inv[i + 1] = v[i];
                if(q.se > 0){
                        //par[i + 1] = id[q.se];
                        len = dip[v[i]] - dip[q.se];
                        g[id[q.se]].push_back({i + 1, len});
                        g[i + 1].push_back({id[q.se], len});
                }
                upd_(N - tout[v[i]], v[i]);
        }
        for(int i = 0; i < v.size(); i++){
                cler(N - tout[v[i]]);
        }
        for(int i = 1; i <= v.size(); i++) a[i] = 0;
        set < pair < pair < int, int >, int > > S;
        for(int i = 1; i <= k; i++){
                int x = V[i];
                a[id[x]] = i;
        }
        for(int i = 1; i <= k; i++){
                make(S, id[V[i]]);
        }
        //for(auto p: S){
        //        cout << p.fi.fi << " " << p.fi.se << " " << p.se << '\n';
        //}
        //exit(0);

        while(!S.empty()){
                auto shit = *S.begin();
                S.erase(S.begin());
                if(a[shit.se]){
                        continue;
                }
                a[shit.se] = shit.fi.se;
                make(S, shit.se);
        }
        for(int i = 1; i <= m; i++){
                printf("%d ", a[id[spec[i]]]);
        }
        printf("\n");
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d", &n);
        for(int i = 1, x , y; i < n; i++){
                scanf("%d%d", &x, &y);
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);

        int q;
        scanf("%d", &q);
        while(q--){
                solve();
        }
}