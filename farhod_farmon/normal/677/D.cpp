#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

vector < pair < int, int > > v[90009];
int d[303][303], n, m, p;

void bfs(int x)
{
    queue < pair < int, int > > q;
    int dd[303][303];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dd[i][j] = 1e9;
    vector < pair < int, pair < int, int > > > gg;
    for(int i = 0; i < v[x].size(); i++)
        gg.pb({d[v[x][i].fi][v[x][i].se], v[x][i]});
    sort(gg.begin(), gg.end());
    int j = 1;
    q.push(gg[0].se);
    dd[gg[0].se.fi][gg[0].se.se] = gg[0].fi;
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        while(j < gg.size() && gg[j].fi <= dd[a.fi][a.se]){
            q.push(gg[j].se);
            dd[gg[j].se.fi][gg[j].se.se] = gg[j].fi;
            j++;
        }
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i * j != 0)
                    continue;
                if(dd[a.fi + i][a.se + j] != 1e9 || a.fi + i < 1 || a.fi + i > n || a.se + j < 1 || a.se + j > m)
                    continue;
                dd[a.fi + i][a.se + j] = dd[a.fi][a.se] + 1;
                q.push({a.fi + i, a.se + j});
            }
        }
    }
    for(int i = 0; i < v[x + 1].size(); i++)
        d[v[x + 1][i].fi][v[x + 1][i].se] = dd[v[x + 1][i].fi][v[x + 1][i].se];
}

int main()
{
    int i, j, h, x, y;
    sc("%d%d%d", &n, &m, &p);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            sc("%d", &x);
            v[x].pb({i, j});
            if(x == 1)
                d[i][j] = i + j - 2;
            else
                d[i][j] = 1e9;
        }
    }
    for(i = 1; i < p; i++){
        if(v[i].size() * v[i + 1].size() > n * m)
            bfs(i);
        else{
            for(j = 0; j < v[i].size(); j++){
                auto f = v[i][j];
                for(h = 0; h < v[i + 1].size(); h++){
                    auto f1 = v[i + 1][h];
                    d[f1.fi][f1.se] = min(d[f1.fi][f1.se], d[f.fi][f.se] + abs(f.fi - f1.fi) + abs(f.se - f1.se));
                }
            }
        }
    }
    auto f = v[p][0];
    pr("%d", d[f.fi][f.se]);
}