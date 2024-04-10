#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 202;
const long long MX = 1010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int d[N][N][MX];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        d[0][0][0] = 1;
        for(int i = 1; i <= n; i++){
                int dif = a[i] - a[i - 1];
                for(int j = 0; j < i; j++){
                        for(int h = 0; h <= k; h++){
                                if(h + j * dif <= k){
                                        d[i][j][h + j * dif] = (d[i][j][h + j * dif] + (1ll * (j + 1) * d[i - 1][j][h]) % mod) % mod;
                                        d[i][j + 1][h + j * dif] = (d[i][j + 1][h + j * dif], d[i - 1][j][h]) % mod;
                                        if(j > 0){
                                                d[i][j - 1][h + j * dif] = (d[i][j - 1][h + j * dif] + (1ll * j * d[i - 1][j][h]) % mod) % mod;
                                        }
                                }
                        }
                }
        }
        int ans = 0;
        for(int i = 0; i <= k; i++){
                ans = (ans + d[n][0][i]) % mod;
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}