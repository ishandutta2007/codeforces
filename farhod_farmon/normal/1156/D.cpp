#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N][2];
long long res;
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                dfs(y.fi, x);
                if(y.se == 1){
                        d[x][1] += d[y.fi][1] + 1;
                } else{
                        d[x][0] += d[y.fi][0] + d[y.fi][1] + 1;
                }
        }
        res += d[x][0] + d[x][1];
}

void trace(int x, int p, int a, int b)
{
        res += a + b;
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                if(y.se == 1){
                        b += d[y.fi][1] + 1;
                } else{
                        a += d[y.fi][0] + d[y.fi][1] + 1;
                }
        }
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                if(y.se == 1){
                        b -= d[y.fi][1] + 1;
                } else{
                        a -= d[y.fi][0] + d[y.fi][1] + 1;
                }

                int na = a, nb = b;
                if(y.se == 1){
                        nb += 1;
                        na = 0;
                } else{
                        na += 1 + nb;
                        nb = 0;
                }

                trace(y.fi, x, na, nb);

                if(y.se == 1){
                        b += d[y.fi][1] + 1;
                } else{
                        a += d[y.fi][0] + d[y.fi][1] + 1;
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }

        dfs(1, 1);
        trace(1, 1, 0, 0);

        cout << res << "\n";
}