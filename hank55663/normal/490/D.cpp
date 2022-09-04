#include<stdio.h>
#include<string.h>
#include<math.h>
struct thing{
    int max,min;
    int i;
};
thing n;
main()
{
    int s[2][2],i,j,a[4][2],ans=0,k=0;
    for(i=0;i<4;i++)
    for(j=0;j<2;j++)
    a[i][j]=0;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++) 
    {
    scanf("%d",&s[i][j]);
    for(int k=2;k<4;k++)
    for(;s[i][j]%k==0;s[i][j]/=k,a[i*2+j][k-2]++);
    }
    if(s[0][0]*s[0][1]!=s[1][0]*s[1][1])
    printf("-1\n");
    else
    {
        if(a[0][1]+a[1][1]>a[2][1]+a[3][1])
        {
            n.max=a[0][1]+a[1][1];
            n.min=a[2][1]+a[3][1];
            n.i=0;
        }
        else
        {
            n.max=a[2][1]+a[3][1];
            n.min=a[0][1]+a[1][1];
            n.i=2;
        }
        ans=n.max-n.min;
        for(i=0;i<ans;i++)
        {
            if(i<a[n.i][1])
            {
                a[n.i][0]++;
                k++;
            }
            else
            a[n.i+1][0]++;
        }
        for(i=0;i<ans;i++)
        {
            if(a[n.i][1]>0)
            {
                a[n.i][1]--;
            }
            else
            a[n.i+1][1]--;
        }
        for(i=1;a[n.i][0]+a[n.i+1][0]>a[2-n.i][0]+a[3-n.i][0];i++,ans++)
        {
            if(k>0||a[n.i+1][0]<=0)
            {
                k--;
                a[n.i][0]--;
            }
            else 
            {
                a[n.i+1][0]--;
            }
        }
        for(i=0;a[n.i][0]+a[n.i+1][0]<a[2-n.i][0]+a[3-n.i][0];i++,ans++)
        {
            if(a[2-n.i][0]>0)
            a[2-n.i][0]--;
            else
            a[3-n.i][0]--;
        }
        printf("%d\n%d %d\n%d %d",ans,s[0][0]*(int)pow(2,a[0][0])*(int)pow(3,a[0][1]),s[0][1]*(int)pow(2,a[1][0])*(int)pow(3,a[1][1]),s[1][0]*(int)pow(2,a[2][0])*(int)pow(3,a[2][1]),s[1][1]*(int)pow(2,a[3][0])*(int)pow(3,a[3][1]));
    }
        
    
    return 0;
}