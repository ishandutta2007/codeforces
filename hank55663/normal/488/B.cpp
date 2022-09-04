#include<stdio.h>
#include<algorithm>
#include<time.h>
using namespace std;
main()
{
    int n,i;
    scanf("%d",&n);
    if(n==0)
    printf("YES\n1\n2\n2\n3\n");
    if(n==1)
    {
        int a;
        scanf("%d",&a);
        printf("YES\n%d\n%d\n%d",a,a*3,a*3);
    }
    else if(n==2)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b)
        swap(a,b);
        if(a*4-b>0)
        printf("YES\n%d\n%d",a*4-b,a*3);
        else
        printf("NO\n");
    }
    else if(n==3)
    {
        int a[3];
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        if(a[0]*3==a[2])
        printf("YES\n%d",a[0]+a[2]-a[1]);
        else if(a[1]+a[2]==a[0]*4)
        printf("YES\n%d",a[0]*3);
        else if((a[0]+a[1])*3==a[2]*4)
        printf("YES\n%d",a[2]/3);
        else
        printf("NO\n");
    }
    else if(n==4)
    {
        int a[4];
        for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
        sort(a,a+4);
        if(a[0]+a[3]==a[1]+a[2]&&a[1]+a[2]==2*(a[3]-a[0]))
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}