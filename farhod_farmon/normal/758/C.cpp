#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 500300;
const long long mod = 1e15 + 3;

using namespace std;

long long n;
long long m;
long long k;
long long x;
long long y;
long long a[110][110];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> m >> k >> x >> y;
    if(n == 1){
        for(int i = 1; i <= m; i++){
            a[1][i] = k / m;
            if(i <= k % m)
                a[1][i]++;
        }
    }
    else{
        long long g = k / ((n + n - 2) * m);
        k %= ((n + n - 2) * m);
        for(int j = 1; j <= m; j++)
            a[1][j] = a[n][j] = g;
        for(int i = 2; i < n; i++)
            for(int j = 1; j <= m; j++)
                a[i][j] = g + g;
        for(int i = 1; i <= n && k; i++)
            for(int j = 1; j <= m && k; j++, k--)
                a[i][j]++;
        for(int i = n - 1; i >= 1 && k; i--)
            for(int j = 1; j <= m && k; j++, k--)
                a[i][j]++;
    }
    long long mn = 1e18,
              mx = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            mn = min(mn, a[i][j]),
            mx = max(mx, a[i][j]);
    cout << mx << " " << mn << " " << a[x][y] << endl;
}