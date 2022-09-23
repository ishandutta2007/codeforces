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

const int N = 505;

using namespace std;

int d[N][N], n, k;
char c[N][N];
int us[N][N], f[N * N], f1[N * N];
bool used[N * N];
int l, ll[N * N];

void dfs(int x, int y, int g)
{
    if(x < 1 || y < 1 || x > n || y > n || c[x][y] == 'X' || us[x][y])
        return;
    us[x][y] = g;
    f[g]++;
    dfs(x - 1, y, g);
    dfs(x + 1, y, g);
    dfs(x, y - 1, g);
    dfs(x, y + 1, g);
}

void go(int x, int y)
{
    for(int i = 1; i <= k; i++)
        if(!used[us[x - i + 1][y + 1]])
            used[us[x - i + 1][y + 1]] = true,
            ll[++l] = us[x - i + 1][y + 1];
    for(int i = 1; i <= k; i++)
        if(!used[us[x + 1][y - i + 1]])
            used[us[x + 1][y - i + 1]] = true,
            ll[++l] = us[x + 1][y - i + 1];
    for(int i = 1; i <= k; i++)
        if(!used[us[x - i + 1][y - k]])
            used[us[x - i + 1][y - k]] = true,
            ll[++l] = us[x - i + 1][y - k];
    for(int i = 1; i <= k; i++)
        if(!used[us[x - k][y - i + 1]])
            used[us[x - k][y - i + 1]] = true,
            ll[++l] = us[x - k][y - i + 1];
}

void add(int x, int y)
{
    for(int i = 1; i <= k; i++)
        f1[us[x - i + 1][y]]++;
    f1[0] = 0;
}

void sub(int x, int y)
{
    for(int i = 1; i <= k; i++)
        f1[us[x - i + 1][y]]--;
    f1[0] = 0;
}

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    int g = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!us[i][j] && c[i][j] == '.')
                dfs(i, j, ++g);
    int ans = 0;
    for(int i = k; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j < k){
                add(i, j);
                continue;
            }
            add(i, j);
            l = 0;
            go(i, j);
            int cnt = 0;
            for(int h = 1; h <= l; h++){
                cnt += f[ll[h]] - f1[ll[h]];
                used[ll[h]] = false;
                //cout << ll[h] << " " << f[ll[h]] << " " << f1[ll[h]] << endl;
            }
            ans = max(ans, cnt);
            sub(i, j - k + 1);
            //cout << ans + k * k << endl;
            //if(j == 4)return 0;
        }
        for(int j = n - k + 2; j <= n; j++)
            sub(i, j);
    }
    cout << ans + k * k << endl;
}