#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2020;

using namespace std;

int n, K, d[N][1 << 14][2], mod = 1e9 + 7;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> K;
    d[0][0][0] = 1;
    K = K - 1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 0)
            x = 3;
        else
            x /= 2;
        for(int j = 0; j < (1 << 13); j++){
            for(int h = 0; h < 2; h++){
                if(!d[i - 1][j][h])
                    continue;
                for(int k = 0; k < 2; k++){
                    if(!((1 << k) & x))
                        continue;
                    int mask = j + (1 << k);
                    if(k == 1 && mask & 1)
                        mask = (1 << k);
                    int nh = h | ((mask & (1 << K)) > 0);
                    d[i][mask][nh] = (d[i][mask][nh] + d[i - 1][j][h]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << 13); i++)
        ans = (ans + d[n][i][1]) % mod;
    cout << ans << endl;
}