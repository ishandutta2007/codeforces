#include <stdio.h>

int main()
{
    int W,Y;
    scanf("%d %d",&W,&Y);
    if(W<Y) W=Y;
    if(W==1) printf("1/1\n");
    else if(W==2) printf("5/6\n");
    else if(W==3) printf("2/3\n");
    else if(W==4) printf("1/2\n");
    else if(W==5) printf("1/3\n");
    else printf("1/6\n");
    return 0;
}