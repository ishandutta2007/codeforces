#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 42;

using namespace std;

int n;
int m;
int q;
int a[N][N];
int s[N][N][N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        char c;
                        cin >> c;
                        a[i][j] = (c - '0') ^ 1;
                        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                }
        }
        for(int x = n; x >= 1; x--){
                for(int y = m; y >= 1; y--){
                        for(int i = x; i <= n; i++){
                                for(int j = y; j <= m; j++){
                                        for(int mask = 0; mask < (1 << 4); mask++){
                                                int sign = __builtin_popcount(mask) & 1;
                                                if(sign){
                                                        sign = 1;
                                                } else{
                                                        sign = -1;
                                                }
                                                s[x][y][i][j] += sign * s[x + ((mask >> 0) & 1)][y + ((mask >> 1) & 1)][i - ((mask >> 2) & 1)][j - ((mask >> 3) & 1)];
                                        }
                                        s[x][y][i][j] += ((a[i][j] - a[x - 1][j] - a[i][y - 1] + a[x - 1][y - 1]) == ((i - x + 1) * (j - y + 1)));
                                }
                        }
                }
        }
        for(int i = 1; i <= q; i++){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << s[x1][y1][x2][y2] << "\n";
        }
}