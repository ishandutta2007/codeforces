#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000500;

using namespace std;

int n, m, k;
int a[N];
int id[N];
bool bad[N];
vector < int > I[N], O[N], g[N];
bool used[N];
int col[N];

void dfs(int x, int col)
{
        if(used[x]){
                if(id[x] != col){
                        bad[a[x]] = true;
                }
                return;
        }
        used[x] = true;
        id[x] = col;
        for(int y: I[x]){
                dfs(y, col ^ 1);
        }
}

int cyc;
int shit[N];
vector < int > v[N];

void trace(int x, int col)
{
        if(shit[x]){
                if(shit[x] != col){
                        cyc = 1;
                }
                return;
        }
        shit[x] = col;
        for(int y: v[x]){
                trace(y, 3 - col);
        }
        trace(x ^ 1, 3 - col);
}

int solve(vector < pair < int, int > > &E)
{
        for(auto p: E){
                v[id[p.fi]].push_back(id[p.se]);
                v[id[p.se]].push_back(id[p.fi]);
        }
        cyc = 0;
        for(auto p: E){
                for(int x: {p.fi, p.se}){
                        if(!shit[id[x]]){
                                trace(id[x], 1);
                        }
                }
        }
        for(auto p: E){
                for(int x: {p.fi, p.se}){
                        shit[id[x]] = 0;
                        shit[id[x] ^ 1] = 0;
                        v[id[x]].clear();
                }
        }
        //cout << cyc << "\n";
        return cyc;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++){
                scanf("%d", &a[i]);

                g[a[i]].push_back(i);
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                if(a[x] == a[y]){
                        I[x].push_back(y);
                        I[y].push_back(x);
                } else{
                        O[x].push_back(y);
                        O[y].push_back(x);
                }
        }
        int G = 0;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                dfs(i, G);
                G += 2;
        }


        int cnt = 0;
        for(int i = 1; i <= k; i++){
                cnt += (!bad[i]);
        }
        long long res = 0;
        vector < pair < int, int > > E, E2;
        for(int i = 1; i <= k; i++){
                if(bad[i]){
                        continue;
                }
                res += cnt - 1;
                //cout << i << " " << res << " " << cnt << "\n";

                E.clear();
                for(int x: g[i]){
                        for(int y: O[x]){
                                if(bad[a[y]]){
                                        continue;
                                }
                                E.push_back({x, y});
                        }
                }
                sort(E.begin(), E.end(), [&](pair < int, int > x, pair < int, int > y){
                        return a[x.se] < a[y.se];
                });
                for(int j = 0; j < E.size(); j++){
                        E2.clear();
                        int h = j;
                        while(h < E.size() && a[E[h].se] == a[E[j].se]){
                                E2.push_back(E[h]);
                                h += 1;
                        }
                        j = h - 1;
                        res -= solve(E2);
                }
        }

        assert(res % 2 == 0);
        res /= 2;

        printf("%lld\n", res);
}