#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int n,ans[4]={0,0,0,0},f=0,s=0,t=0,i;
    scanf("%d",&n);
    int a[5000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ans[a[i]]++;
     }
    printf("%d\n",min(ans[3],min(ans[2],ans[1])));
    for(int j=0;j<min(ans[3],min(ans[2],ans[1]));j++)
    {
        for(int i=0;i<n;i++)
            if(a[i]==1)
        {
            a[i]=0;
            printf("%d ",i+1);
            break;
        }
        for(int i=0;i<n;i++)
            if(a[i]==2)
        {
            a[i]=0;
            printf("%d ",i+1);
            break;
        }
        for(int i=0;i<n;i++)
            if(a[i]==3)
        {
            a[i]=0;
        printf("%d\n",i+1);
        break;


        }


    }
    return 0;
}