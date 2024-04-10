#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int q;
int c;
int d[11][111][111];

void solve()
{
        cin >> n >> q >> c;
        for(int i = 1; i <= n; i++){
                int x, y, s;
                cin >> x >> y >> s;
                d[s][x][y]++;
        }
        for(int h = 0; h <= c; h++){
                for(int i = 1; i <= 100; i++){
                        for(int j = 1; j <= 100; j++){
                                d[h][i][j] += d[h][i - 1][j] + d[h][i][j - 1] - d[h][i - 1][j - 1];
                        }
                }
        }
        for(int i = 1; i <= q; i++){
                int t, x1, y1, x2, y2, ans = 0;
                cin >> t >> x1 >> y1 >> x2 >> y2;
                for(int j = 0; j <= c; j++){
                        int nj = (j + t) % (c + 1);
                        ans += nj * (d[j][x2][y2] - d[j][x2][y1 - 1] - d[j][x1 - 1][y2] + d[j][x1 - 1][y1 - 1]);
                }
                cout << ans << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}