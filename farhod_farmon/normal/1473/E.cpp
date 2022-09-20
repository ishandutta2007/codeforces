#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
long long d[N][2][2];
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
        long long inf = 1e18;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 2; j++){
                        for(int h = 0; h < 2; h++){
                                d[i][j][h] = inf;
                        }
                }
        }
        d[1][0][0] = 0;
        set < pair < long long, int > > s;
        for(int x = 0; x < 2; x++){
                for(int y = 0; y < 2; y++){
                        for(int i = 1; i <= n; i++){
                                if(d[i][x][y] != inf){
                                        s.insert({d[i][x][y], i});
                                }
                                while(!s.empty()){
                                        int X = s.begin()->se;
                                        s.erase(s.begin());
                                        for(auto Y: v[X]){
                                                if(d[X][x][y] + Y.se < d[Y.fi][x][y]){
                                                        s.erase({d[Y.fi][x][y], Y.fi});
                                                        d[Y.fi][x][y] = d[X][x][y] + Y.se;
                                                        s.insert({d[Y.fi][x][y], Y.fi});
                                                }
                                                if(!x){
                                                        d[Y.fi][1][y] = min(d[Y.fi][1][y], d[X][x][y]);
                                                }
                                                if(!y){
                                                        d[Y.fi][x][1] = min(d[Y.fi][x][1], d[X][x][y] + Y.se * 2);
                                                }
                                                if(!x && !y){
                                                        d[Y.fi][1][1] = min(d[Y.fi][1][1], d[X][x][y] + Y.se);
                                                }
                                        }
                                }
                        }
                }
        }
        for(int i = 2; i <= n; i++){
                cout << d[i][1][1] << " ";
        }
}