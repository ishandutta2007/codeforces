#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2010;
const long long Q = 10100;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int d[N][4];
int f[N][4];
int c[4][4];

void solve()
{
        c[0][1] = 1;
        c[0][2] = 1;
        c[0][3] = 1;
        c[1][2] = 2;
        c[2][1] = 2;
        c[3][0] = 1;
        c[3][1] = 1;
        c[3][2] = 1;
        cin >> n >> k;
        d[1][0] = d[2][1] = d[2][2] = d[1][3] = 1;
        for(int i = 2; i <= n; i++){
                for(int j = 1; j <= k; j++){
                        for(int h1 = 0; h1 < 4; h1++){
                                for(int h2 = 0; h2 < 4; h2++){
                                        f[j + c[h1][h2]][h2] += d[j][h1];
                                        if(f[j + c[h1][h2]][h2] >= mod){
                                                f[j + c[h1][h2]][h2] -= mod;
                                        }
                                }
                        }
                }
                for(int j = 1; j <= k; j++){
                        for(int h = 0; h < 4; h++){
                                d[j][h] = f[j][h];
                                f[j][h] = 0;
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i < 4; i++){
                ans += d[k][i];
                if(ans >= mod){
                        ans -= mod;
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}