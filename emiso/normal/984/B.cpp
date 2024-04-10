#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[102], a[102][102];

int c(int x, int y) {
    int ret = 0;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(i != 0 || j != 0)
                ret += (a[x+i][y+j] == '*');
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    int f = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.') f &= (c(i, j) == 0);
            else if(a[i][j] != '*') f &= (c(i, j) == (a[i][j] - '0'));
        }
    }

    printf("%s\n", f ? "YES" : "NO");
    return 0;
}