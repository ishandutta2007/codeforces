#include<stdio.h>
main()
{
    int n,num[100000];
    scanf("%d",&n);
    num[1]=1;
    for(int i=2;i<=n+1;i++)
    {
        int a;
    scanf("%d",&a);
    num[i]=num[i-1]+a;
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,max=n+1,min=1,mid;
        scanf("%d",&a);
        while(1)
        {
            mid=(max+min)/2;
            if(num[mid]>a)
            max=mid;
            else if(num[mid]<a)
            min=mid;
            if(num[mid]==a)
            break;
            if(max-1<=min)
            {
                mid=min;
                break;
            }
            
        }
        printf("%d\n",mid);
    }
    return 0;
}