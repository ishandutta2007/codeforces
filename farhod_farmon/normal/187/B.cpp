#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 66;

using namespace std;

int n, m, r;
int t[N][N][N];
int d[N][N][N];

void solve()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int h = 0; h < N; h++)
                d[i][j][h] = 1e9;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)
            for(int h = 1; h <= n; h++)
                for(int k = 1; k <= n; k++)
                    t[i][h][k] = min(t[i][h][k], t[i][h][j] + t[i][j][k]);
        for(int j = 1; j <= n; j++)
            for(int h = 1; h <= n; h++)
                d[0][j][h] = min(d[0][j][h], t[i][j][h]);
    }
    for(int j = 1; j <= n; j++)
        for(int h = 1; h <= n; h++)
            for(int k = 1; k <= n; k++)
                for(int l = 1; l <= n; l++)
                    d[j][k][l] = min(d[j][k][l], d[j - 1][k][h] + d[0][h][l]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d%d", &n, &m, &r);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            for(int h = 1; h <= n; h++)
                sc("%d", &t[i][j][h]);
    solve();
    for(int i = 1; i <= r; i++){
        int a, b, c, ans = 1e9;
        sc("%d%d%d", &a, &b, &c);
        c = min(c, n);
        for(int j = 0; j <= c; j++)
            ans = min(ans, d[j][a][b]);
        pr("%d\n", ans);
    }
}