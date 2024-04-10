#include<stdio.h>
#include<algorithm>
#include<math.h>
main()
{
    int n;
    scanf("%d",&n);
    if(n%2==0)
    printf("4 %d\n",n-4);
    else
    printf("9 %d\n",n-9);
    return 0;
}