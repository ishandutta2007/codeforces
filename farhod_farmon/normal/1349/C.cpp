#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int m;
int Q;
int d[N][N];
char c[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> Q;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        d[i][j] = -1;
                }
        }
        queue < pair < int, int > > q;
        for(int i = 1; i <= n; i++){
                for(int j = 1, x, y, h, good; j <= m; j++){
                        good = 0;
                        for(h = 0; h < 4; h++){
                                x = i + dx[h];
                                y = j + dy[h];
                                if(c[x][y] == c[i][j]){
                                        good = 1;
                                }
                        }
                        if(good){
                                d[i][j] = 0;
                                q.push({i, j});
                        }
                }
        }
        while(!q.empty()){
                int x = q.front().fi;
                int y = q.front().se;
                q.pop();
                for(int i = 0, nx, ny; i < 4; i++){
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if(d[nx][ny] == -1){
                                d[nx][ny] = d[x][y] + 1;
                                q.push({nx, ny});
                        }
                }
        }
        for(int i = 1; i <= Q; i++){
                int x, y;
                long long t;
                cin >> x >> y >> t;
                if((d[x][y] > t || d[x][y] == -1) || (t - d[x][y]) % 2 == 0){
                        cout << c[x][y] - '0' << "\n";
                } else{
                        cout << '1' - c[x][y] << "\n";
                }
        }
}