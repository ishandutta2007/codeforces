#include <stdio.h>

#define w1 while(1)
#define sint(n) scanf("%d",&n)
#define pint(n) printf("%d\n",n)
#define For(n) for(i=1;i<=n;i++)
#define For0(n) for(i=0;i<n;i++)
#define fill(n,m) memset(n,m,sizeof(n))

long long gcd (long long a, long long b)
{
 long long rem;
 if (b == 0)
  return a;
 
 while (1)
 {
   rem = a%b;
   if (rem==0)
     break;
   a=b;
   b=rem;
 }
 return b;
}

int main()
{
    long long i,n,m1,m2,m3,a,b,c,l,r,j,k;
    int ok=-1;
    scanf("%lld %lld",&l,&r);
    for(i=l;i<=r;i++)
    {
                     for(j=i+1;j<=r;j++)
                     {
                                        m1 = gcd(i,j);
                                        if(m1 != 1)/*printf("%lld %lld %lld\n\n",i,j,m1)*/;
                                        else {
                                             for(k=j+1;k<=r;k++)
                                              {
                                                     m2 = gcd(j,k);
                                                     if(m2==1)
                                                     {
                                                        m3=gcd(i,k);
                                                        if(m3!=1){
                                                              ok=1;
                                                              a = i;
                                                              b = j;
                                                              c = k;
                                                              i=r+1;
                                                              j=r+1;
                                                              l=r+1;
                                                        }
                                                     }      
                                              }
                                             }
                     }
    }
    if(ok==-1) puts("-1");
    else printf("%lld %lld %lld\n",a,b,c);
    return 0;
}