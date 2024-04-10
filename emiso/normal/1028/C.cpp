#include <bits/stdc++.h>

using namespace std;
#define MN 140000

int n, p[MN][4], A, B, C, D, a[MN][4][2];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);
    }

    a[0][0][0] = INT_MIN, a[0][2][0] = INT_MAX, a[0][1][0] = INT_MIN, a[0][3][0] = INT_MAX;
    a[n+1][0][1] = INT_MIN, a[n+1][2][1] = INT_MAX, a[n+1][1][1] = INT_MIN, a[n+1][3][1] = INT_MAX;

    for(int i = 1; i <= n; i++)
        for(int c = 0; c < 4; c++) {
            a[i][c][0] = (c < 2) ? max(a[i-1][c][0], p[i][c]) : min(a[i-1][c][0], p[i][c]);
            a[n-i+1][c][1] = (c < 2) ? max(a[n-i+2][c][1], p[n-i+1][c]) : min(a[n-i+2][c][1], p[n-i+1][c]);
        }

    for(int i = 1; i <= n; i++) {
        A = max(a[i-1][0][0], a[i+1][0][1]);
        B = max(a[i-1][1][0], a[i+1][1][1]);
        C = min(a[i-1][2][0], a[i+1][2][1]);
        D = min(a[i-1][3][0], a[i+1][3][1]);
        if(A <= C && B <= D) {
            printf("%d %d\n", A, B);
            return 0;
        }
    }

    return 0;
}