#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n;
int m;
int a[N][N];
int D[N][N];

int get(int x, int y)
{
        if(D[x][y] == x){
                return x;
        }
        return D[x][y] = get(D[x][y], y);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        scanf("%d", &a[i][j]);
                        D[i][j] = i;
                }
        }
        for(int i = 1; i <= m; i++){
                D[n + 1][i] = n + 1;
        }
        for(int i = 1; i <= q; i++){
                int x = 1, y;
                scanf("%d", &y);
                while(x <= n && y >= 1 && y <= m){
                        if(a[x][y] == 1){
                                a[x][y] = 2;
                                y += 1;
                        } else if(a[x][y] == 2){
                                D[x][y] = get(x + 1, y);
                                x += 1;
                        } else{
                                a[x][y] = 2;
                                y -= 1;
                        }
                        x = get(x, y);
                }
                printf("%d ", y);
        }
}