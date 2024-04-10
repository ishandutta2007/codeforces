#include<stdio.h>
#include<stdlib.h>
using namespace std;
main()
{
    int n,i,j=1;
    scanf("%d",&n);
    if(n>=47)
    {
        printf("YES\n");
        for(i=n;i>1;i-=2,j++)
        printf("%d - %d = 1\n",i,i-1);
        for(i=0;i<n-n/2-23-1;i++,j++)
        printf("1 * 1 = 1\n");
        for(i=1;i<24;i++,j++)
        printf("%d + 1 = %d\n",i,i+1);
    }
    else if(n>=7&&n%2==0)
    {
        printf("YES\n");
        for(i=n;i>8;i-=2)
            printf("%d - %d = 1\n",i,i-1);
        for(i=0;i<(n-8)/2;i++)
            printf("1 * 1 = 1\n");
            printf("8 * 7 = 56\n6 * 5 = 30\n3 - 4 = -1\n1 - 2 = -1\n30 - -1 = 31\n56 - 31 = 25\n25 + -1 = 24\n");
    }
    else if(n>=7&&n%2==1)
    {
        printf("YES\n");
        for(i=n;i>7;i-=2)
        printf("%d - %d = 1\n",i,i-1);
        for(i=0;i<(n-7)/2;i++)
            printf("1 * 1 = 1\n");
            printf("7 * 6 = 42\n5 * 4 = 20\n42 - 20 = 22\n22 + 3 = 25\n25 - 2 = 23\n23 + 1 = 24\n");

    }
    else if(n==6)
        {
            printf("YES\n6 + 4 = 10\n5 * 2 = 10\n10 + 3 = 13\n13 + 1 = 14\n14 + 10 = 24\n");
        }
    else if(n==5)
    {
        printf("YES\n5 * 3 = 15\n4 * 2 = 8\n15 + 1 = 16\n16 + 8 = 24\n");
    }
    else if(n==4)
    {
        printf("YES\n4 * 3 = 12\n2 * 1 = 2\n12 * 2 = 24\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}