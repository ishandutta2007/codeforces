#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 20200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int p;
int a[N];
int f[N][110];
int d[55][N];

void solve()
{
        cin >> n >> k >> p;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] %= p;
                int cnt = 0;
                for(int j = i; j >= 1; j--){
                        cnt += a[j];
                        if(cnt >= p){
                                cnt -= p;
                        }
                        if(!f[i][cnt]){
                                f[i][cnt] = j;
                        }
                }
                d[1][i] = (d[1][i - 1] + a[i]) % p;
        }
        for(int i = 2; i <= k; i++){
                for(int j = 1; j <= n; j++){
                        for(int k = 0; k < p; k++){
                                if(f[j][k]){
                                        d[i][j] = max(d[i][j], d[i - 1][f[j][k] - 1] + k);
                                }
                        }
                }
        }
        cout << d[k][n] << "\n";
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