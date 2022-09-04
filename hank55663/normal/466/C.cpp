#include<stdio.h>
typedef long long LL;
main()
{
    LL n,sum[500001],a,ans,b=0,i,total=0;
    scanf("%I64d",&n);
    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        sum[i]=sum[i-1]+a;
        } 
    if(sum[n]%3!=0)
    printf("0\n");
    else 
    {
        
        ans=sum[n]/3;
        for(i=1;i<n;i++)
        {
            if(sum[i]==ans*2&&i!=1)
            total+=b;
            if(sum[i]==ans)
            b++;
        }
        printf("%I64d\n",total);
    }
    return 0;
}