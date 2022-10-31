#include <bits/stdc++.h>

using namespace std;

int n, m, a[55][55][2], c[55][55];

void cant() {
    puts("Impossible");
    exit(0);
}

void check(int t) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i && a[i][j][t] <= a[i-1][j][t]) cant();
            if(j && a[i][j][t] <= a[i][j-1][t]) cant();
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int t = 0; t < 2; t++)
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j][t]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j][0] > a[i][j][1])
                swap(a[i][j][0], a[i][j][1]);

    check(0);
    check(1);

    puts("Possible");
    return 0;
}