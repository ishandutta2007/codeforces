#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,lcm;
int f[600001];
long long a,b;
int gcd(int x,int y) { return y==0?x:gcd(y,x%y); }
long long Goto(long long a,long long b)
{   int i;
    memset(f,60,sizeof(f));
    f[a]=0;
    for (i=a;i>b;i--)
    { f[i-1]=min(f[i-1],f[i]+1);
      for (j=2;j<=k;j++)
        if ((i-i%j)>=b)f[i-i%j]=min(f[i-i%j],f[i]+1); 
}
return f[b];
}
int main()
{ scanf("%I64d%I64d%d",&a,&b,&k);
  for (lcm=1,i=2;i<=k;i++)
   lcm=lcm*i/gcd(lcm,i);
  if (a/lcm==b/lcm) printf("%I64d\n",Goto(a%lcm,b%lcm));
  else printf("%I64d\n",1ll*Goto(lcm,0)*(a/lcm-b/lcm-1)+Goto(a%lcm,0)+Goto(lcm,b%lcm));
}