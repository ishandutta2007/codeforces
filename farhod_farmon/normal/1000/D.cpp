#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int d[N];
int c[N][N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i < N; i++){
                for(int j = 0; j <= i; j++){
                        if(j == 0 || i == j){
                                c[i][j] = 1;
                        }
                        else{
                                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                                if(c[i][j] >= mod){
                                        c[i][j] -= mod;
                                }
                        }
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                if(a[i] < 1){
                        continue;
                }
                d[i] = 1;
                for(int j = 1; j < i; j++){
                        if(a[j] < 1){
                                continue;
                        }
                        int col = i - j - 1;
                        if(a[j] <= col){
                                d[i] += 1ll * d[j] * c[col][a[j]] % mod;
                                if(d[i] >= mod){
                                        d[i] -= mod;
                                }
                        }
                }
                int col = n - i;
                if(a[i] <= col){
                        ans += 1ll * d[i] * c[col][a[i]] % mod;
                        if(ans >= mod){
                                ans -= mod;
                        }
                }
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