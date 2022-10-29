#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,tot;
long long a[1000001],ans,Case[20001],prime[20001];
long long gcd(long long x,long long y){ return y==0?x:gcd(y,x%y); }
void Check(long long x)
{ long long i,tot=0,sum=0;
  memset(Case,0,sizeof(Case));
   for (i=1;i*i<=x;i++)
    if (x%i==0) 
    {  prime[++tot]=x/i;
      if (x/i!=i) prime[++tot]=i;
    }
   sort(prime+1,prime+tot+1);
   for (i=1;i<=n;i++)
     Case[lower_bound(prime+1,prime+tot+1,gcd(x,a[i]))-prime]++;
   for (i=1;i<=tot;i++)
    {  sum=0;
       for (j=i;j<=tot;j++)
         if (prime[j]%prime[i]==0)
            sum+=Case[j];
        if (ans<prime[i]&&sum>=(n+1)/2) ans=prime[i];
   }
}
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
 for (i=1;i<=10;i++)
   Check(a[1ll*rand()*rand()%n+1]);
   Check(15);
 printf("%I64d\n",ans);
}