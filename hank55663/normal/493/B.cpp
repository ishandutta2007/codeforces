#include<stdio.h>
using namespace std;
main()
{
    long long int n,i,l1=0,l2=0,point[2]={0,0},last,num[2]={0,0},a[2][1000000];
    scanf("%I64d",&n);
    for(i=0;i<n;i++) 
    {
        long long int p;
        scanf("%I64d",&p);
        if(p>0)
        {
            point[0]+=p;
            last=0;
            num[0]++;
            a[0][l1]=p;
            l1++;
        }
        else
        {
            point[1]-=p;
            last=1;
            num[1]++;
            a[1][l2]=-p;
            l2++;
        }
    }
    if(point[0]>point[1])
    printf("first\n");
    else if(point[0]<point[1])
    printf("second\n");
    else 
    {
        int ok=0;
        for(i=0;i<l1&&i<l2;i++)
        {
            if(a[0][i]>a[1][i])
            {
                printf("first\n");
                ok=1;
                break;
                }
            if(a[0][i]<a[1][i])
            {
                printf("second\n");
                ok=1;
                break;
            }
        }
        if(!ok)
        {
        
        if(l1==l2)
        {
            if(last)
                printf("second\n");
            else 
                printf("first\n");
        }
        else if(l1>l2)
        printf("first\n");
        else 
        printf("second\n");
        }
    }
    return 0;
}