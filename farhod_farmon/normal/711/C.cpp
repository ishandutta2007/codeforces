#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

lli n, m, k;
lli d[N][N][N];
lli c[N][N];
lli a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(int h = 0; h <= m; h++)
                d[i][j][h] = 1e14;
    for(int i = 1; i <= m; i++){
        if(a[1] != 0 && a[1] != i)
            continue;
        d[1][1][i] = 0;
        if(a[1] == 0)
            d[1][1][i] = c[1][i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int h = 1; h <= m; h++){
                if(a[i] != 0 && a[i] != h)
                    continue;
                d[i][j][h] = d[i - 1][j][h];
                for(int k = 1; k <= m; k++){
                    if(k == h)
                        continue;
                    d[i][j][h] = min(d[i][j][h], d[i - 1][j - 1][k]);
                }
                if(a[i] == 0)
                    d[i][j][h] = d[i][j][h] + c[i][h];
            }
        }
    }
    lli ans = 1e14;
    for(int i = 1; i <= m; i++)
        ans = min(ans, d[n][k][i]);
    if(ans >= 1e14)
        ans = -1;
    cout << ans << endl;
}