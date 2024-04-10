#include <bits/stdc++.h>
using namespace std;
int matrix[1010][1010];
int n, m;
int a[1010], b[1010];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    memset(matrix, -1, sizeof matrix);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= a[i]; j++) {
            if(matrix[i][j] == 0) return puts("0"), 0;
            else matrix[i][j] = 1;
        }
        if(matrix[i][a[i] + 1] == 1) return puts("0"), 0;
        else matrix[i][a[i] + 1] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= b[i]; j++) {
            if(matrix[j][i] == 0) return puts("0"), 0;
            else matrix[j][i] = 1;
        }
        if(matrix[b[i] + 1][i] == 1) return puts("0"), 0;
        else matrix[b[i] + 1][i] = 0;
    }
    int ans = 1;
    const int mod = 1000000007;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(matrix[i][j] == -1) ans = ans * 2 % mod;
    return cout << ans << endl, 0;
}