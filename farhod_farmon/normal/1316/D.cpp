#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
char res[N][N];
pair < int, int > a[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char c[4] = {'D', 'U', 'R', 'L'};

int in[N][N];
bool used[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d", &n);

        queue < pair < int, int > > q;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        scanf("%d%d", &a[i][j].fi, &a[i][j].se);

                        if(a[i][j].fi == i && a[i][j].se == j){
                                q.push({i, j});
                                res[i][j] = 'X';
                        }
                }
        }
        while(!q.empty()){
                int x = q.front().fi, y = q.front().se;
                q.pop();
                for(int i = 0; i < 4; i++){
                        int nx = x + dx[i], ny = y + dy[i];
                        if(a[nx][ny] == a[x][y] && !res[nx][ny]){
                                res[nx][ny] = c[i ^ 1];
                                q.push({nx, ny});
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(a[i][j].fi != -1 && !res[i][j]){
                                printf("INVALID\n");
                                return 0;
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(res[i][j] || a[i][j].fi != -1) continue;

                        for(int h = 0; h < 4; h++){
                                int x = i + dx[h], y = j + dy[h];
                                if(a[x][y].fi == -1){
                                        res[i][j] = c[h];
                                }
                        }
                        if(!res[i][j]){
                                printf("INVALID\n");
                                return 0;
                        }
                }
        }

        printf("VALID\n");
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        printf("%c", res[i][j]);
                }
                printf("\n");
        }

}