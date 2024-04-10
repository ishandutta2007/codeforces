#include <stdio.h>

int main() {
    int a,b,count=0,i;
    scanf("%d %d",&a,&b);
    if(a!=b) {
        for(i=1;i*i<a-b;i++) {
              if((a-b)%i == 0) {
                         if(i > b) count++;
                         if((a-b)/i > b) count++;
              }  
        }
        if(i*i == a-b && i>b) count++;
        printf("%d\n",count);
    }
    else printf("infinity\n");
    return 0;
}