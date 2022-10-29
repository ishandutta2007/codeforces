#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
int main(){  
    int i, j, x, y, a, b, ans = 0;  
    scanf("%d%d%d%d",&x,&y,&a,&b);  
      
    for(i = a; i <= x; i++)  
    for(j = b; j < i && j <= y; j++)  
        ans++;  
  
    printf("%d\n",ans);  
    for(i = a; i <= x; i++)  
    for(j = b; j < i && j <= y; j++)  
        printf("%d %d\n",i, j);  
  
    return 0;  
}