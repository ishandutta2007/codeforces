#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[8][8];
bool used[10000];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= 6; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= 6; i++){
                used[a[1][i]] = 1;
                if(n == 1){
                        continue;
                }
                for(int j = 1; j <= 6; j++){
                        used[a[2][j]] = 1;
                        used[a[2][j] * 10 + a[1][i]] = 1;
                        used[a[1][i] * 10 + a[2][j]] = 1;
                        if(n == 2){
                                continue;
                        }
                        for(int h = 1; h <= 6; h++){
                                used[a[3][h]] = 1;
                                used[a[2][j] * 10 + a[3][h]] = 1;
                                used[a[1][i] * 10 + a[3][h]] = 1;
                                used[a[3][h] * 10 + a[2][j]] = 1;
                                used[a[3][h] * 10 + a[1][i]] = 1;
                                used[a[1][i] * 100 + a[2][j] * 10 + a[3][h]] = 1;
                                used[a[1][i] * 100 + a[3][h] * 10 + a[2][j]] = 1;
                                used[a[2][j] * 100 + a[1][i] * 10 + a[3][h]] = 1;
                                used[a[2][j] * 100 + a[3][h] * 10 + a[1][i]] = 1;
                                used[a[3][h] * 100 + a[1][i] * 10 + a[2][j]] = 1;
                                used[a[3][h] * 100 + a[2][j] * 10 + a[1][i]] = 1;
                        }
                }
        }
        int ans = 0;
        while(used[ans + 1]){
                ans++;
        }
        cout << ans << "\n";
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