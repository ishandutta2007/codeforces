#include <stdio.h>

int main()
{
    int n,k,i,a,ak=-1,count=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
                    scanf("%d",&a);
                    if(i==k) ak=a;
                    if(a>0 && (i<=k || a==ak)) count++;
    }
    printf("%d\n",count);
    return 0;
}