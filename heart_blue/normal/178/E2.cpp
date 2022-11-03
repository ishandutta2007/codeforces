#include <stdio.h>
 
int a[2002][2002];
 
void dfs(int x, int y)
{
    if (a[x][y] == 0) return;
    
    a[x][y] = 0;
    
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y);
}
 
int main()
{
    int n, b = 0, c = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i + 1][j + 1]);
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                if (a[i][j + 1] == 0) {
                    b++;
                } else {
                    c++;
                }
                
                dfs(i, j);
            }
        }
    }
    
    printf("%d %d\n", b, c);
    
    return 0;
}