#include <stdio.h>

#define MOD 1000000007 

long long ex(long long a,long long b)
{
     long long res = 1;
     while(b)
     {
             if(b%2==1)
             {
                       res = ((res*a)%MOD);
             }
             b/=2;
             a = ((a*a)%MOD);
     }
     return res;
}

int main()
{
    long long n,s1,s2,s;
    scanf("%I64d",&n);
    if(n==0) printf("1\n");
    else {
    s1 = ex(2,n-1);
    s2 = ex(2,n);
    s = (s1 *((s2+1)%MOD))%MOD;
    
    printf("%I64d\n",s);
    }
    return 0;
}