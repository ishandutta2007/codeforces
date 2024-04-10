#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n, m;
int a[N][N];
long long ans;
long long d[4][N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[0][i][j] = max(d[0][i - 1][j], d[0][i][j - 1]) + a[i][j];
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            d[1][i][j] = max(d[1][i + 1][j], d[1][i][j + 1]) + a[i][j];
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            d[2][i][j] = max(d[2][i + 1][j], d[2][i][j - 1]) + a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            d[3][i][j] = max(d[3][i - 1][j], d[3][i][j + 1]) + a[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 || j == 1 || i == n || j == m)
                continue;
            ans = max(ans, d[0][i - 1][j] + d[1][i + 1][j] + d[2][i][j - 1] + d[3][i][j + 1]);
            ans = max(ans, d[0][i][j - 1] + d[1][i][j + 1] + d[2][i + 1][j] + d[3][i - 1][j]);
        }
    }
    cout << ans << endl;
}