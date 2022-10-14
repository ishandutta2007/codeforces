// Codeforces Beta Round #55
// Problem D -- Changing a String
#include <cstdio>
#include <cstring>

#define N 1001

using namespace std;

int n, m, f[N][N];
char a[N], b[N];

int main()
{
    scanf("%s%s", a, b);
    n = strlen(a), m = strlen(b);
    f[0][0] = 0;
    for(int i = 1; i <= n; ++ i)
        f[i][0] = i;
    for(int j = 1; j <= m; ++ j)
        f[0][j] = j;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            f[i][j] = N;
            if(j && f[i][j - 1] + 1 < f[i][j]) // INSERT
                f[i][j] = f[i][j - 1] + 1;
            if(i && f[i - 1][j] + 1 < f[i][j]) // DELETE
                f[i][j] = f[i - 1][j] + 1;
            if(i && j && f[i - 1][j - 1] + 1 < f[i][j]) // REPLACE
                f[i][j] = f[i - 1][j - 1] + 1;
            if(i && j && a[i - 1] == b[j - 1] && f[i - 1][j - 1] < f[i][j])
                f[i][j] = f[i - 1][j - 1];
        }
    printf("%d\n", f[n][m]);        
    while(n > 0 || m > 0)
    {
        if(m && f[n][m - 1] + 1 == f[n][m])
        {
            printf("INSERT %d %c\n", n + 1, b[m - 1]);
            m --;
            continue;
        }
        if(n && f[n - 1][m] + 1 == f[n][m])
        {
            printf("DELETE %d\n", n);
            n --;
            continue;
        }
        if(n && m && f[n - 1][m - 1] + 1 == f[n][m])
        {
            printf("REPLACE %d %c\n", n, b[m - 1]);
            n --, m --;
            continue;
        }
        n --, m --;
    }
    return 0;
}