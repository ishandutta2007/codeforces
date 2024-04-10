#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int a[N];
int L[N];
int id[N];
int nxt[N];
int f[N][20];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i <= n; i++){
                id[i] = m + 1;
                if(i == n){
                        nxt[a[i]] = a[1];
                } else{
                        nxt[a[i]] = a[i + 1];
                }
        }
        for(int i = 1; i <= m; i++){
                cin >> a[i];
        }

        for(int i = 0; i < 20; i++){
                f[m + 1][i] = m + 1;
        }
        for(int i = m; i >= 1; i--){
                f[i][0] = id[nxt[a[i]]];
                id[a[i]] = i;
                for(int j = 1; j < 20; j++){
                        f[i][j] = f[f[i][j - 1]][j - 1];
                }
                a[i] = i;
                for(int j = 0; j < 20; j++){
                        if((n - 1) & (1 << j)){
                                a[i] = f[a[i]][j];
                        }
                }
        }
        for(int i = 1; i <= m; i++){
                f[i][0] = a[i];
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= m; j++){
                        if(j + (1 << i) - 1 > m){
                                continue;
                        }
                        f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
                }
        }
        for(int i = 1; i <= q; i++){
                int l, r, g;
                cin >> l >> r;
                g = L[r - l + 1];
                cout << (min(f[l][g], f[r - (1 << g) + 1][g]) <= r);
        }
}