#include<iostream>
#include<cstdio>
using namespace std;
int t,a[3],b[3];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
        int ans=min(a[2],b[1])<<1;
        if(a[2]>b[1])
        {
            a[2]-=b[1];
            b[2]-=a[2];
            b[2]-=a[0];
            if(b[2]<=0)
                printf("%d\n",ans);
            else
                printf("%d\n",ans-(b[2]<<1));
        }
        else
        {
            b[1]-=a[2];
            a[1]-=b[1];
            a[1]-=b[0];
            if(a[1]<=0)
                printf("%d\n",ans);
            else
                printf("%d\n",ans-(a[1]<<1));
        }
    }
    return 0;
}