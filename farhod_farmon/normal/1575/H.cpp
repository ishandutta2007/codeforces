#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 505;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int p[N];
int f[N][2];
int d[N][N];
int d2[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                a[i] = c - '0';
        }
        for(int i = 0; i < m; i++){
                char c;
                cin >> c;
                b[i] = c - '0';
        }

        for(int i = 1; i < m; i++){
                p[i] = p[i - 1];
                while(p[i] > 0 && b[p[i]] != b[i]){
                        p[i] = p[p[i] - 1];
                }
                if(b[p[i]] == b[i]){
                        p[i] += 1;
                }
        }
        for(int i = 0; i < m; i++){
                for(int x = 0; x < 2; x++){
                        if(i > 0 && x != b[i]){
                                f[i][x] = f[p[i - 1]][x];
                        } else{
                                f[i][x] = i + (x == b[i]);
                        }
                }
        }

        f[m][0] = f[p[m - 1]][0];
        f[m][1] = f[p[m - 1]][1];

        int inf = 1e9;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        d[i][j] = d2[i][j] = inf;
                }
        }
        d[0][0] = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j <= m; j++){
                        for(int h = 0; h <= n; h++){
                                for(int x = 0; x < 2; x++){
                                        d2[f[j][x]][(f[j][x] == m) + h] = min(d2[f[j][x]][(f[j][x] == m) + h],
                                                                                  d[j][h] + (x ^ a[i]));
                                }
                        }
                }
                for(int j = 0; j < N; j++){
                        for(int h = 0; h < N; h++){
                                d[j][h] = d2[j][h];
                                d2[j][h] = inf;
                        }
                }
        }

        for(int i = 0; i <= n - m + 1; i++){
                int res = inf;
                for(int j = 0; j < m + 1; j++){
                        res = min(res, d[j][i]);
                }
                if(res == inf){
                        res = -1;
                }
                cout << res << " ";
        }
}