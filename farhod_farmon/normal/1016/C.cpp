#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
long long a[N];
long long b[N];
long long f[N];
long long c[2][N];

void solve()
{
        cin >> n;
        for(int i = 0; i < 2; i++){
                for(int j = 1; j <= n; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = n; i >= 1; i--){
                a[i] = a[i + 1] + i * c[0][i];
                a[i] = a[i] + (n + n - i + 1) * c[1][i];
                b[i] = b[i + 1] + i * c[1][i];
                b[i] = b[i] + (n + n - i + 1) * c[0][i];
                f[i] = f[i + 1] + c[0][i] + c[1][i];
        }
        long long ans = a[1] - f[1], s = 0, g = 0;
        for(int i = 1; i <= n; i++){
                s += g * c[1 - i % 2][i]; g++;
                s += g * c[i % 2][i]; g++;
                ans = max(ans, s + (2 * i - i - 1) * f[i + 1] + (i % 2 ? b[i + 1] : a[i + 1]));
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}