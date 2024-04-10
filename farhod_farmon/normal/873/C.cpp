#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
int k;
int a[N][N];

int f(int x, int y)
{
        int cnt = 0;
        for(int i = 0; i < min(k, n - y + 1); i++){
                cnt += a[y + i][x];
        }
        return cnt;
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        int ans = 0, cnt = 0;
        for(int i = 1; i <= m; i++){
                int c = 0;
                int mx = 0, mc = 0;
                for(int j = 1; j <= n; j++){
                        if(a[j][i] == 0){
                                continue;
                        }
                        int g = f(i, j);
                        if(g > mx){
                                mx = g;
                                mc = c;
                        }
                        c++;
                }
                ans += mx;
                cnt += mc;
        }
        cout << ans << " " << cnt << "\n";
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