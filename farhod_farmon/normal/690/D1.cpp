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

int n, m, cnt;
bool used[101][101];
char c[101][101];

void dfs(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || c[x][y] == '.' || used[x][y])
        return;
    used[x][y] = true;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i * j == 0){
                dfs(x + i, y + j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] != '.' && used[i][j] == 0){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}