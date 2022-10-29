#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 +7;
const int N = 11111;
const int w[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char s[5][N], c[5][N];
long long f[N][8], g[5][5][5][5];
int n;
int check(int i, int j, int p){
    if ((i > 3 || i < 1 || j < 1 || j > n) && (i + w[p][0] > 3 || i + w[p][0] < 1 || j + w[p][1] < 1 || j + w[p][1] > n)) return -1;
    if (c[i][j] != '.') return 0; c[i][j] = 'X';
    if (c[i + w[p][0]][j + w[p][1]] != '.') return 0; c[i + w[p][0]][j + w[p][1]] = 'X';
    return 1;
}

long long Solve(){
    memset(f, 0, sizeof(f));
    f[0][7] = 1;
    for (int i = 1; i <= n; i++){
        int t = 0;
        if (c[1][i] != '.') t += 1;
        if (c[2][i] != '.') t += 2;
        if (c[3][i] != '.') t += 4;
        f[i][t] += f[i - 1][7];
        if ((t & 1) == 0) f[i][t | 1] += f[i - 1][6];
        if ((t & 2) == 0) f[i][t | 2] += f[i - 1][5];
        if ((t & 3) == 0) f[i][t | 3] += f[i - 1][7] + f[i - 1][4];
        if ((t & 4) == 0) f[i][t | 4] += f[i - 1][3];
        if ((t & 5) == 0) f[i][t | 5] += f[i - 1][2];
        if ((t & 6) == 0) f[i][t | 6] += f[i - 1][1] + f[i - 1][7];
        if ((t & 7) == 0) f[i][t | 7] += f[i - 1][0] + f[i - 1][3] + f[i - 1][6];

        for (int j = 0; j <= 7; j++) f[i][j] %= MOD;
    }
    return f[n][7];
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++) scanf("%s", s[i] + 1);
    long long ans = 0;
    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= n; j++) if (s[i][j] == 'O')
    for (int p1 = 1; p1 <= 4; p1++)
    for (int p2 = 1; p2 <= 4; p2++)
    for (int p3 = 1; p3 <= 4; p3++)
    for (int p4 = 1; p4 <= 4; p4++){
        if ((p1 & 1) == 0 && (p2 & 1) && (p3 & 1) == 0 && (p4 & 1)) continue;
        memcpy(c, s, sizeof(s));
        int t, q1, q2, q3, q4;
        t = check(i - 1, j, p1);
        if (!t) continue;
        if (t == -1) q1 = 0; else q1 = p1;
        t = check(i, j + 1, p2);
        if (!t) continue;
        if (t == -1) q2 = 0; else q2 = p2;
        t = check(i + 1, j, p3);
        if (!t) continue;
        if (t == -1) q3 = 0; else q3 = p3;
        t = check(i, j - 1, p4);
        if (!t) continue;
        if (t == -1) q4 = 0; else q4 = p4;
        g[q1][q2][q3][q4] = Solve();
    }
    for (int p1 = 0; p1 <= 4; p1++)
    for (int p2 = 0; p2 <= 4; p2++)
    for (int p3 = 0; p3 <= 4; p3++)
    for (int p4 = 0; p4 <= 4; p4++){
        if (g[p1][p2][p3][p4] != 0){
        ans += g[p1][p2][p3][p4];
        }
    }
    cout << ans % MOD << endl;
}