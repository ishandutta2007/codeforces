#include<cstdio>
#define R(a,b) for(i=a;i<=b;i++)
long long i,a,b,c,n,x,C,M=1e9+7;
main()
{
    scanf("%d",&n);
    R(1,n)scanf("%d",&x),C+=x==1;
    a=b=c=1;
    R(2,C)c=(b+a*(i-1)%M)%M,a=b,b=c;
    R(C+1,n)c=c*i%M;
    printf("%d\n",c);
}