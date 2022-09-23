#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int m;
char a[N][N];
bool used[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool A[N];
bool B[N];
bool fuck[N][N];

void dfs(int x, int y)
{
        if(used[x][y] || a[x][y] != '#'){
                return;
        }
        used[x][y] = 1;
        for(int i = 0; i < 4; i++){
                dfs(x + dx[i], y + dy[i]);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(a[i][j] == '#'){
                                A[i] = true;
                                B[j] = true;
                        }
                        if(!used[i][j] && a[i][j] == '#'){
                                dfs(i, j);
                                res += 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(!A[i] && !B[j]){
                                fuck[i][j] = 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <=m; j++){
                        if(fuck[i][j]){
                                A[i] = true;
                                B[j] = true;
                        }
                }
        }
        if(res > 0){
                for(int i = 1; i <= n; i++){
                        if(!A[i]){
                                res = -1;
                        }
                }
                for(int i = 1; i <= m; i++){
                        if(!B[i]){
                                res = -1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                int cnt = 0, last = 0;
                for(int j = 1, cur; j <= m + 1; j++){
                        cur = 0;
                        if(a[i][j] == '#'){
                                cur = 1;
                        }
                        if(cur != last){
                                cnt += 1;
                        }
                        last = cur;
                }
                if(cnt > 2){
                        res = -1;
                }
        }
        for(int i = 1; i <= m; i++){
                int cnt = 0, last = 0;
                for(int j = 1, cur; j <= n + 1; j++){
                        cur = 0;
                        if(a[j][i] == '#'){
                                cur = 1;
                        }
                        if(cur != last){
                                cnt += 1;
                        }
                        last = cur;
                }
                if(cnt > 2){
                        res = -1;
                }
        }
        cout << res << "\n";
}