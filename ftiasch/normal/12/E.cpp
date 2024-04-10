// Codeforces Beta Round #12
// Problem E -- Start of the session
#include <cstdio>

using namespace std;

int n, a[1000][1000];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i != n - 1; ++ i)
    {
        for(int j = 0; j != n - 1; ++ j)
            a[i][j] = 1 + (i + j) % (n - 1);
        a[i][n - 1] = a[n - 1][i] = a[i][i];
        a[i][i] = 0;
    }
    for(int i = 0; i != n; ++ i)
    {
        printf("%d", a[i][0]);
        for(int j = 1; j != n; ++ j)
            printf(" %d", a[i][j]);
        printf("\n");
    }
    return 0;
}