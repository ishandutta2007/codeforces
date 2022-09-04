#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long int max(long long int a,long long int b)
{
    if(a>b)
    return a;
    else
    return b;
}
main()
{
    long long int n,a,b,i,min[3];
    while(scanf("%I64d %I64d %I64d",&n,&a,&b)!=EOF)
    {
        if(a*b/n>=6)
        printf("%I64d\n%I64d %I64d\n",a*b,a,b);
        else if(a<=6&&b<=n)
        printf("%I64d\n6 %I64d\n",6*n,n);
        else if(b<=6&&a<=n)
        printf("%I64d\n%I64d 6\n",6*n,n);
        else
        {
            min[0]=1e10;
            for(i=b;i<=(long long int)sqrt(ceil(6.0*n))&&(long long int)ceil(6.0*n/i)>=a;i++)
            if(min[0]>i*(long long int)ceil(6.0*n/i))
            {
                
                min[0]=i*(long long int)ceil(6.0*n/i);
                min[1]=(long long int)ceil(6.0*n/i);
                min[2]=i;
                if(min[0]==6*n)
                break;
            }
            if(min[0]!=6*n)
            for(i=a;i<=(long long int)sqrt(ceil(6.0*n))&&(long long int)ceil(6.0*n/i)>=b;i++)
            if(min[0]>i*(long long int)ceil(6.0*n/i))
            {
                
                min[0]=i*(long long int)ceil(6.0*n/i);
                min[2]=(long long int)ceil(6.0*n/i);
                min[1]=i;
                if(min[0]==6*n)
                break;
            }
            printf("%I64d\n%I64d %I64d\n",min[0],min[1],min[2]);
        }
        
    } 
    return 0;
}