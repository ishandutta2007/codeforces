#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
char a[N][N];

int go(int x, int y, int dx, int dy)
{
        int res = 0;
        while(a[x][y] == '*'){
                res += 1;
                x += dx;
                y += dy;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        int A = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        A += a[i][j] == '*';
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(a[i][j] == '.'){
                                continue;
                        }
                        int res = -3;
                        res += go(i, j, 0, 1);
                        res += go(i, j, 0, -1);
                        res += go(i, j, 1, 0);
                        res += go(i, j, -1, 0);
                        if(a[i + 1][j] != '*' || a[i][j + 1] != '*') continue;
                        if(a[i - 1][j] != '*' || a[i][j - 1] != '*') continue;
                        if(res == A){
                                cout << "YES" << "\n";
                                return 0;
                        }
                }
        }
        cout << "NO" << "\n";
}