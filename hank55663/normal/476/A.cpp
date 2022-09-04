#include<stdio.h>
main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=(n+1)/2;i<=n;i++)
    {
        if(i%m==0)
        {printf("%d",i);
        return 0;}
    }
    printf("-1");
    return 0;
}