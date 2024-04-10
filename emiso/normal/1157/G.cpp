#include <bits/stdc++.h>

using namespace std;

int n, m, a[202][202], row[202], col[202], tmp[202][202];

void try_this(int ignore) {
    int edge = 0, flag;

    for(int i = 0; i < n; i++) {
        if(i == ignore) continue;

        flag = -1;
        for(int j = 0; j < m; j++) {
            int x = a[i][j] ^ col[j];
            if(x == 0) {
                if(flag == -1) flag = 0;
                else if(flag == 2) flag = 4;
                else if(flag == 1) flag = 3;
            } else {
                if(flag == -1) flag = 1;
                else if(flag == 0) flag = 2;
                else if(flag == 3) flag = 4;
            }
        }

        if(flag == 4) return;
        row[i] = ((flag & 1) ^ edge);
        if(flag == 2 || flag == 3) {
            if(edge) return;
            edge = 1;
        }
    }

    puts("YES");
    for(int i = 0; i < n; i++) printf("%d", row[i]); puts("");
    for(int j = 0; j < m; j++) printf("%d", col[j]); puts("");
    exit(0);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    if(n == 1) {
        puts("YES\n0");
        for(int j = 0; j < m; j++)
            printf("%d", a[0][j]);
        puts("");
        return 0;
    }

    for(int j = 0; j < m; j++) col[j] = (a[0][j] == 1);
    row[0] = 0;
    try_this(0);

    for(int j = 0; j < m; j++) col[j] = (a[0][j] == 0);
    row[0] = 1;
    try_this(0);

    for(int j = 0; j < m; j++) col[j] = (a[n-1][j] == 0);
    row[n-1] = 0;
    try_this(n-1);

    for(int j = 0; j < m; j++) col[j] = (a[n-1][j] == 1);
    row[n-1] = 1;
    try_this(n-1);

    puts("NO");
    return 0;
}