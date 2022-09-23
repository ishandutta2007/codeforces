#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int inf = 1e9;
int n, m;
int f[N][2];
bool used[N];
double res[N];
vector < int > G;
vector < pair < int, int > > v[N];

void dfs(int x, int A, int B)
{
        if(used[x]){
                if(f[x][A] != inf && f[x][A] != B){
                        cout << "NO" << "\n";
                        exit(0);
                }
                f[x][A] = B;
                return;
        }
        f[x][A] = B;
        G.push_back(x);
        used[x] = true;
        for(auto y: v[x]){
                dfs(y.fi, A ^ 1, y.se - B);
        }
}

void solve(int x)
{
        G.clear();
        dfs(x, 0, 0);
        double X = inf;
        bool shit = false;
        for(int x: G){
                if(f[x][0] != inf && f[x][1] != inf){
                        X = (f[x][1] - f[x][0]) / 2.0;
                        shit = true;
                }
        }
        if(shit){
                for(int x: G){
                        if(f[x][0] != inf && f[x][1] != inf){
                                if(fabs(X * 2 + f[x][0] - f[x][1]) > 1e-9){
                                        cout << "NO" << "\n";
                                        exit(0);
                                }
                        }
                        if(f[x][0] != inf){
                                res[x] = X + f[x][0];
                        } else{
                                res[x] = - X + f[x][1];
                        }
                }
                return;
        }
        double l = -3e5, r = 3e5;
        for(int it = 0; it < 100; it++){
                double h1 = (l * 2 + r) / 3;
                double h2 = (l + 2 * r) / 3;
                double c1 = 0, c2 = 0;
                for(int x: G){
                        if(f[x][0] != inf){
                                c1 += fabs(h1 + f[x][0]);
                                c2 += fabs(h2 + f[x][0]);
                        } else{
                                c1 += fabs(- h1 + f[x][1]);
                                c2 += fabs(- h2 + f[x][1]);
                        }
                }
                if(c1 < c2){
                        r = h2;
                } else{
                        l = h1;
                }
        }
        X = (l + r) / 2;
        for(int x: G){
                if(f[x][0] != inf){
                        res[x] = X + f[x][0];
                } else{
                        res[x] = - X + f[x][1];
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                f[i][0] = f[i][1] = inf;
        }
        for(int i = 1; i <= m; i++){
                int x, y, c;
                cin >> x >> y >> c;
                v[x].push_back({y, c});
                v[y].push_back({x, c});
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        solve(i);
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << fixed << setprecision(9) << res[i] << " ";
        }
}