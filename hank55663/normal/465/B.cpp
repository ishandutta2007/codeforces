#include<stdio.h>
main()
{
    int n,ans=0,start=0;
    scanf("%d",&n);
    int a[10000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0&&start&&i!=0&&i<n-1&&a[i+1]==1)
        ans++;
        else if(a[i]==1)
        {
        ans++;
        start=1;
        }
    }
    printf("%d",ans);
    return 0;
}