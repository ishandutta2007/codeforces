// Codeforces Beta Round #69
// Problem D -- Domino Carpet
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1111;
const int MOD = 1000000007;

int n, m, horCnt[N], verCnt[N];
char map[N][N];
bool hor[N][N], ver[N][N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 4 * n + 1; ++ i) {
        scanf("%s", map[i]);
    }
    memset(hor, 0, sizeof(hor));
    memset(ver, 0, sizeof(ver));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            hor[i + 1][j + 1] = ver[i + 1][j + 1] = true;
            if ((map[4 * i + 1][4 * j + 1] == 'O') xor 
                    (map[4 * i + 1][4 * j + 3] == 'O')) {
                if (map[4 * i + 1][4 * j + 1] == 'O') {
                    ver[i + 1][j + 1] = false;
                } else { 
                    hor[i + 1][j + 1] = false;
                }
            }
            if ((map[4 * i + 1][4 * j + 2] == 'O') xor
                    (map[4 * i + 2][4 * j + 1] == 'O')) {
                if (map[4 * i + 1][4 * j + 2] == 'O') {
                    ver[i + 1][j + 1] = false;
                } else {
                    hor[i + 1][j + 1] = false;
                }
            }
        }
    }     
    horCnt[0] = 1;
    for (int j = 1; j <= m; ++ j) {
        horCnt[j] = 0;
        bool found = false;
        for (int i = 1; i <= n; ++ i) {
            found |= not ver[i][j];
        }
        if (not found and (n & 1) == 0) {
            horCnt[j] = horCnt[j - 1];
        }
        if (j > 1) {
            verCnt[0] = 1;
            for (int i = 1; i <= n; ++ i) {
                verCnt[i] = 0;
                if (hor[i][j - 1] and hor[i][j]) {
                    verCnt[i] = verCnt[i - 1];
                }
                if (i > 1 and ver[i][j - 1] and ver[i][j] 
                        and ver[i - 1][j - 1] and ver[i - 1][j]) {
                    verCnt[i] = (verCnt[i] + verCnt[i - 2]) % MOD;
                }
            }
            bool found = false;
            for (int i = 1; i <= n; ++ i) {
                found |= not ver[i][j];
                found |= not ver[i][j - 1]; 
            }
            if (not found and (n & 1) == 0) {
                verCnt[n] -= 1;
            }
            horCnt[j] = (horCnt[j] + (long long)horCnt[j - 2] * verCnt[n]) % MOD;
        }
    }
    printf("%d\n", horCnt[m]);
    return 0;
}