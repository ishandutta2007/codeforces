#include<stdio.h>
typedef long long LL;
LL gcd(LL x,LL y)
{
    if(y==0) return x;
    return gcd(y, x%y);
}
main()
{
    LL a,b,i,j,k;
    scanf("%I64d %I64d",&a,&b);
    for(i=a;i<=b;i++)
    for(j=i+1;j<=b;j++)
    for(k=j+1;k<=b;k++)
    {
        if(gcd(i,j)==1&&gcd(j,k)==1&&gcd(i,k)!=1)
        {
        printf("%I64d %I64d %I64d\n",i,j,k);
        return 0;
        }
    }
    printf("-1\n");
    return 0;
}