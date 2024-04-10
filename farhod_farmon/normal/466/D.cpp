#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long MX = 1010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int d[N][N];

void solve()
{
        cin >> n >> k;
        d[0][0] = 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 0; j <= i; j++){
                        if(a[i] + j == k){
                                d[i][j] = (d[i][j] + d[i - 1][j]) % mod;
                                if(j > 0){
                                        d[i][j] = (d[i][j] + d[i - 1][j - 1]) % mod;
                                }
                        }
                        if(a[i] + j + 1 == k){
                                d[i][j] = (d[i][j] + d[i - 1][j]) % mod;
                                d[i][j] = (d[i][j] + 1ll * d[i - 1][j + 1] * (j + 1) % mod) % mod;
                                d[i][j] = (d[i][j] + 1ll * d[i - 1][j] * j % mod) % mod;
                        }
                }
        }
        cout << d[n][0] << endl;
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