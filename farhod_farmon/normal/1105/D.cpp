#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int s[N];
int p[10];
int res[10];
int d[N][N];
char c[N][N];
vector < pair < int, int > > v[10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= k; i++){
                cin >> s[i];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        if(c[i][j] != '.' && c[i][j] != '#'){
                                v[c[i][j] - '0'].push_back({i, j});
                        }
                }
        }
        queue < pair < int, int > > q;
        while(true){
                bool ok = false;
                for(int i = 1; i <= k; i++){
                        if(p[i] == v[i].size()){
                                continue;
                        }
                        ok = true;
                        while(p[i] < v[i].size()){
                                d[v[i][p[i]].fi][v[i][p[i]].se] = 0;
                                q.push(v[i][p[i]]);
                                p[i] += 1;
                        }
                        while(!q.empty()){
                                int x = q.front().fi, y = q.front().se;
                                q.pop();
                                if(d[x][y] == s[i]){
                                        continue;
                                }
                                for(int j = 0; j < 4; j++){
                                        int nx = x + dx[j], ny = y + dy[j];
                                        if(c[nx][ny] != '.'){
                                                continue;
                                        }
                                        d[nx][ny] = d[x][y] + 1;
                                        c[nx][ny] = c[x][y];
                                        q.push({nx, ny});
                                        v[i].push_back({nx, ny});
                                }
                        }
                }
                if(!ok){
                        break;
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] != '.' && c[i][j] != '#'){
                                res[c[i][j] - '0'] += 1;
                        }
                }
        }
        for(int i = 1; i <= k; i++){
                cout << res[i] << " ";
        }
}