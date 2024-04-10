#include<stdio.h>
#include<math.h>
main()
{
    int a,b,sum=0;
    scanf("%d %d",&a,&b);
    a-=b;
    for(int i=1;i<sqrt(a);i++)
    {
        if(a%i==0)
        {
            if(a/i>b)
            sum++;
            if(i>b)
            sum++;
        }
    }
    if(a==(int)sqrt(a)*(int)sqrt(a)&&sqrt(a)>b)
    sum++;
    if(a!=0)
    printf("%d\n",sum);
    else
    printf("infinity\n");
    return 0;
}