#include<stdio.h>
main()
{
    int m,n,a[101][101],ans[101][101];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    ans[i][j]=1;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
        if(!a[i][j])
        {
            for(int k=0;k<m;k++)
            ans[k][j]=0;
            for(int k=0;k<n;k++)
            ans[i][k]=0;
        }
    }
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    if(a[i][j])
    {
        int ok=0;
        for(int k=0;k<m;k++)
        if(ans[k][j])
        {
            ok=1;
            break;
        }
        for(int k=0;k<n;k++)
        if(ans[i][k])
        {
            ok=1;
            break;
        }
        if(!ok)
        {
        printf("NO\n");
        return 0;
        }
    }
    printf("YES\n");
    for(int i=0;i<m;i++,printf("\n"))
    for(int j=0;j<n;j++)
    printf("%d ",ans[i][j]);
    return 0;
}