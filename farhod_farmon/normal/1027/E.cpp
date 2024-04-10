#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long Q = 10100;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int d[N][N];

void solve()
{
        cin >> n >> k;
        d[0][0] = 1;
        for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                        d[i][j] = d[i - 1][j];
                }
                d[i][i] = (d[i][i] + 1) % mod;
                for(int j = 2; j <= i; j++){
                        for(int h = 0; h < n; h++){
                                int nh = max(h, i - j + 1);
                                d[i][nh] = (d[i][nh] + d[j - 2][h]) % mod;
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if((i + 1) * (j + 1) < k){
                                ans = (ans + 1ll * d[n - 1][i] * d[n - 1][j] % mod) % mod;
                        }
                }
        }
        cout << (ans + ans) % mod << "\n";
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