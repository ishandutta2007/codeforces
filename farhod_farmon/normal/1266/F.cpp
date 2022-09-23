#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 500500;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n;
int d[N];
int u[N];
int diam;
int par[N];
vector < int > v[N];
 
void dfs(int x, int p)
{
        par[x] = p;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                d[x] = max(d[x], d[y] + 1);
        }
}
 
void trace(int x, int p, int up)
{
        u[x] = up;
        pair < int, int > f = {0, 0};
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                if(d[y] > d[f.fi]){
                        f.se = f.fi;
                        f.fi = y;
                } else if(d[y] > d[f.se]){
                        f.se = y;
                }
        }
        diam = max(diam, d[f.fi] + d[f.se]);
        diam = max(diam, d[x] + u[x]);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                int nu = up;
                if(f.fi == y){
                        nu = max(nu, d[f.se] + 1);
                } else{
                        nu = max(nu, d[f.fi] + 1);
                }
                trace(y, x, nu + 1);
        }
 
}
 
int K;
int in[N];
int A[N];
int B[N];
vector < pair < int, int > > D[N];
set < pair < int, int > > k0, k1;
 
vector < int > check_up[N];
vector < int > fail_up[N];
 
void get1(int x)
{
        k1.erase({A[x], x});
 
        if(!D[x].empty() && D[x].back().fi == K){
                while(!D[x].empty() && D[x].back().fi == K){
                        D[x].pop_back();
                }
                A[x] = D[x].size() + 1;
        } else{
                A[x] = D[x].size();
        }
 
        k1.insert({A[x], x});
}
 
void get0(int x)
{
        if(x == -1){
                return;
        }
        k0.erase({B[x], x});
 
        if(x == 1){
                B[x] = D[x].size();
        } else if((D[x].size() - (u[x] > K)) == 0){
                B[x] = -1;
        } else{
                B[x] = D[x].size() + D[par[x]].size() - 1;
                if(u[x] > K){
                        B[x] -= 1;
                }
        }
        if(D[x].size() > 0){
                B[x] = max(B[x], (int)D[x].size());
        }
        //cout << x << " " << K << " " << B[x] << "\n";
 
        k0.insert({B[x], x});
}
 
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
 
        ios_base::sync_with_stdio(0);
 
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
 
        d[0] = -1;
        dfs(1, 1);
        diam = d[1];
        trace(1, 1, 0);
 
 
        for(int i = 1; i <= n; i++){
                for(int j: v[i]){
                        if(par[i] == j){
                                continue;
                        }
 
                        D[i].push_back({d[j] + 1, j});
                }
                if(i > 1){
                        D[i].push_back({u[i], -1});
                }
                sort(D[i].begin(), D[i].end());
                reverse(D[i].begin(), D[i].end());
                D[i].push_back({0, -1});
 
                for(int j = 0; j < D[i].size(); j++){
                        if(j > 0 && D[i][j].fi == D[i][j - 1].fi){
                                continue;
                        }
                        check_up[D[i][j].fi].push_back(i);
                        if(j > 0 && D[i][j].fi + 1 != D[i][j - 1].fi){
                                fail_up[D[i][j].fi + 1].push_back(i);
                        }
                }
 
        }
        int res0, res1;
        for(; K <= n / 2; K++){
 
                res0 = res1 = 1;
                if(K * 2 <= diam){
                        res0 = 2;
                }
                if(K * 2 + 1 <= diam){
                        res1 = 2;
                }
 
                for(int x: check_up[K]){
                        get1(x);
                }
                for(int x: fail_up[K]){
                        get1(x);
                }
 
                if(k0.size() > 0){
                        res0 = max(res0, (--k0.end())->fi);
                }
                if(k1.size() > 0){
                        res1 = max(res1, (--k1.end())->fi);
                }
 
                if(K * 2 >= 1){
                        cout << res0 << " ";
                }
 
                if(K * 2 + 1 <= n){
                        cout << res1 << " ";
                }
 
                for(int x: check_up[K]){
                        get0(x);
                        for(auto y: D[x]){
                                get0(y.se);
                        }
                }
        }
}