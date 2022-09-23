#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5005;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int d[N][N][2];

void solve()
{
        cin >> n;
        for(int i = 0; i <= n; i++){
                if(i > 0){
                        cin >> a[i];
                }
                for(int j = 1; j <= n; j++){
                        d[i][j][0] = d[i][j][1] = 1e9;
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= (i + 1) / 2; j++){
                        d[i][j][0] = min(d[i - 1][j][0], d[i - 1][j][1]);
                        int c1 = 0, c2 = 0;
                        if(i - 2 >= 0){
                                c1 += d[i - 2][j - 1][0];
                                c2 += d[i - 2][j - 1][1];
                        }
                        if(i > 1 && a[i - 1] >= a[i]) c1 += a[i - 1] - a[i] + 1;
                        if(i < n && a[i + 1] >= a[i]) c1 += a[i + 1] - a[i] + 1;
                        if(i < n && a[i + 1] >= a[i]) c2 += a[i + 1] - a[i] + 1;
                        if(i > 1 && min(a[i - 2] - 1, a[i - 1]) >= a[i]) c2 += min(a[i - 2] - 1, a[i - 1]) - a[i] + 1;
                        if(j == 1){
                                c2 = 1e9;
                        }
                        d[i][j][1] = min(c1, c2);
                }
        }
        for(int i = 1; i <= (n + 1) / 2; i++){
                cout << min(d[n][i][0], d[n][i][1]) << " ";
        }
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