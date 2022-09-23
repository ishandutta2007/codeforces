#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 111;

using namespace std;

long long n, m, a[N], b[N];
long long d[N][N], c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        b[x] = 1;
    }
    int h = 1;
    for(int i = 1; i <= n; i++){
        if(b[i] == false)
            d[0][m + 1] += a[i];
        else
            c[h++] = a[i];
    }
    sort(c + 1, c + m + 1);
    for(int i = 0; i <= m; i++){
        for(int j = m + 1; j > i; j--){
            if(i == 0 && j == m + 1)
                continue;
            long long x = 0,
                      y = 0;
            if(i > 0)
                x = d[i - 1][j] + max(d[i - 1][j], c[i]);
            if(j < m + 1)
                y = d[i][j + 1] + max(d[i][j + 1], c[j]);
            d[i][j] = max(x, y);
        }
    }
    long long ans = 0;
    for(int i = 0; i <= m; i++)
        ans = max(ans, d[i][i + 1]);
    cout << ans << endl;
}