#include <stdio.h>

int n,m,x,possible[1010][1010],flag=0;

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&x);
        if(n <= m) {
            possible[x%m][i+1] = 1;
            for(int j=0;j<m;j++) {
                if(possible[j][i]) {
                        possible[j][i+1] = 1;
                        possible[(j+x)%m][i+1] = 1;
                }
            }
        }
    }
    if(n<=m) printf("%s\n",(possible[0][n+1])?"YES":"NO");
    else printf("YES\n");
    return 0;
}