#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1010;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int c[N][N];

int make(int x, int y, int g)
{
        if(c[x][y] && c[x][y] != g){
                return 0;
        }
        c[x][y] = g;
        return 1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int res = 1;

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 1; j <= a[i]; j++){
                        res &= make(i, j, 1);
                }
                res &= make(i, a[i] + 1, 2);
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
                for(int j = 1; j <= b[i]; j++){
                        res &= make(j, i, 1);
                }
                res &= make(b[i] + 1, i, 2);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(!c[i][j]){
                                res += res;
                                if(res >= mod){
                                        res -= mod;
                                }
                        }
                }
        }
        cout << res << "\n";
}