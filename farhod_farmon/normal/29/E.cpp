#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

int n, m;
int d[N][N];
pair < int, int > p[N][N];
vector < int > v[N], a, b;
vector < pair < int, int > > g;
bool used[N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = 1e9;
    d[1][n] = 0;
    g.pb({1, n});
    for(int i = 0; i < g.size(); i++){
        int x = g[i].fi,
            y = g[i].se;
        if(d[n][1] != 1e9)
            break;
        for(int j = 0; j < v[x].size(); j++){
            if(used[v[x][j]][y])
                continue;
            used[v[x][j]][y] = true;
            for(int h = 0; h < v[y].size(); h++){
                int nx = v[x][j],
                    ny = v[y][h];
                if(nx == ny || d[nx][ny] != 1e9)
                    continue;
                d[nx][ny] = d[x][y] + 1;
                p[nx][ny] = {x, y};
                g.pb({nx, ny});
            }
        }
    }
    if(d[n][1] == 1e9){
        cout << -1 << endl;
        return 0;
    }
    pair < int, int > ans = {n, 1};
    for(int i = 1; i <= d[n][1] + 1; i++){
        a.pb(ans.fi);
        b.pb(ans.se);
        ans = p[ans.fi][ans.se];
    }
    cout << d[n][1] << endl;
    for(int i = d[n][1]; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;
    for(int i = d[n][1]; i >= 0; i--)
        cout << b[i] << " ";
    cout << endl;

}