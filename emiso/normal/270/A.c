#include <stdio.h>

int main()
{
    int a,n;
    scanf("%d",&n);
    while(n--) {
               scanf("%d",&a);
               if(360%(180-a)==0) puts("YES");
               else puts("NO");
    }
    return 0;
}