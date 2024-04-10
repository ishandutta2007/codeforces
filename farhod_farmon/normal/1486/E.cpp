#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int inf = 2e9;

int n;
int m;
int d[N][51];
vector < pair < int, int > > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }
        for(int i = 1; i <= n; i++){
                for(int j = 0; j <= 50; j++){
                        d[i][j] = inf;
                }
        }
        d[1][0] = 0;
        set < pair < int, pair < int, int > > > S;
        S.insert({0, {1, 0}});
        while(!S.empty()){
                int x = S.begin()->se.fi;
                int g = S.begin()->se.se;
                S.erase(S.begin());
                int ng, cost;
                for(auto p: v[x]){
                        if(g == 0){
                                ng = p.se;
                                cost = d[x][g];
                        } else{
                                ng = 0;
                                cost = d[x][g] + (g + p.se) * (g + p.se);
                        }

                        if(cost < d[p.fi][ng]){
                                S.erase({d[p.fi][ng], {p.fi, ng}});
                                d[p.fi][ng] = cost;
                                S.insert({d[p.fi][ng], {p.fi, ng}});
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                if(d[i][0] == inf){
                        cout << -1 << " ";
                } else{
                        cout << d[i][0] << " ";
                }
        }
}