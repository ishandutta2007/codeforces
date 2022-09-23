#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int m;
int a[N][N];
char c[N][N];

int get(int x, int y, int dx)
{
        if(x < 1 || x > n) return 0;
        int res = 0;
        while(true){
                res += 1;
                if(c[x][y] != c[x + dx][y]){
                        break;
                }
                x += dx;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                }
        }
        for(int i = 2; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] == c[i - 1][j]){
                                continue;
                        }
                        a[i][j] = get(i, j, 1);
                        if(get(i - 1, j, -1) < a[i][j]){
                                a[i][j] = 0;
                        } else if(get(i + a[i][j], j, 1) < a[i][j]){
                                a[i][j] = 0;
                        }
                }
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1, cnt = 0; j <= m; j++){
                        if(a[i][j] == 0){
                                cnt = 0;
                                continue;
                        }
                        bool good = true;
                        good &= a[i][j] == a[i][j - 1];
                        good &= c[i][j] == c[i][j - 1];
                        good &= c[i - 1][j] == c[i - 1][j - 1];
                        good &= c[i + a[i][j]][j] == c[i + a[i][j]][j - 1];
                        if(good) cnt += 1;
                        else cnt = 1;
                        res += cnt;
                }
        }
        cout << res << "\n";
}