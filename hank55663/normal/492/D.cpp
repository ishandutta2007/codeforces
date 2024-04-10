#include<stdio.h>
#include<algorithm>
using namespace std; 
int gcd(int a,int b)
{
    if(a%b!=0)
    return gcd(b,a%b);
    return b;
}
main()
{
    int n,x,y,destroy;
    bool a[2000000];
    scanf("%d %d %d",&n,&x,&y);
    long long int ax=x,ay=y;
    destroy=(x+y)/gcd(x,y);
    for(int i=0;i<destroy-1;i++)
    {
        if(ax>ay)
        {
            a[i]=1;
            ay+=y;
        }
        else
        {
            a[i]=0;
            ax+=x;
        }
    }
    for(int i=0;i<n;i++)
    {
        int monster;
        scanf("%d",&monster);
        if(x==y)
        printf("Both\n");
        else
        {
        monster%=destroy;
        if(monster==0||monster==destroy-1)
        printf("Both\n");
        else if(a[monster-1])
        {
            printf("Vanya\n");
        }
        else
        printf("Vova\n");
        }
    }
    
    
    return 0;
}