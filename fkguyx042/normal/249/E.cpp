#include<cstdio>
#include<algorithm>
#include<cstring>
#define ld long double
#define ll long long
const long long Mo=(long long)1e10;
const long long Mo2=Mo*2ll;
const long long Mo6=Mo*6ll;
using namespace std;
long long i,j,m,n,p,k,ans,T;
int l,r,l1,r1;
int t;
ld X;
long long gcd(long long a,long long b)
{  if (!b) return a; return gcd(b,a%b);}
ld Three(ld x)
{  return x*(x+1.0)*(2.0*x+1.0)/6.0; }
ld ask(ld x,ld y)
 { if (x==y) return x*x*(1.0+x*x)/2.0;
   if (x==0.0||y==0.0) return 0.0;
   if (x<y) { ld sum=0; 
     sum+=x*x*(1.0+x*x)/2.0;
     sum+=(Three(y-1.0)-Three(x-1.0))*x+(1.0+x)*x/2.0*(y-x);
     return sum;
}
   ld sum=0;
   sum+=y*y*(1.0+y*y)/2.0;
   sum+=(Three(x)-Three(y))*y-(y-1.0)*y/2.0*(x-y);
   return sum;
}
long long Cheng(long long a,long long b)
{   long long A=b/100000,B=b%100000;
    return (a*A%Mo*100000%Mo+a*B%Mo)%Mo;
}
long long three(long long x)
{  if (!x) return 0;
   long long A=6,sum=1;
   sum=Cheng(sum,x/gcd(x,A)),A/=gcd(x,A);
   sum=Cheng(sum,(x+1)/gcd((x+1),A)),A/=gcd(x+1,A);
   sum=Cheng(sum,(2*x+1)/gcd(2*x+1,A));
   return sum%Mo;
}
long long Ask(long long x,long long y)
{  if (!x||!y) return 0; 
   if (x==y)
  {   if (x&1ll) return T=Cheng(x*x%Mo,(1+x*x)/2%Mo);
      else return T=Cheng(x*x/2%Mo,(1+x*x)%Mo);
  }
  else if (x<y)
  {    long long sum=0;
      if (x&1ll) sum=Cheng(x*x%Mo,(1+x*x)/2%Mo);
      else sum=Cheng(x*x/2%Mo,(1+x*x)%Mo);
     sum+=Cheng((three(y-1)-three(x-1)+Mo)%Mo,x);
     sum+=Cheng((x+1)*x/2%Mo,y-x);
    return T=sum%Mo;
  }
  else {
  	  long long sum=0;
  	    if (y&1ll) sum=Cheng(y*y%Mo,(1+y*y)/2%Mo);
      else sum=Cheng(y*y/2%Mo,(1+y*y)%Mo);
    sum+=Cheng((three(x)-three(y)+Mo)%Mo,y);
    sum-=Cheng((y-1)*y/2%Mo,x-y);
    while (sum<0) sum+=Mo;
    return T=sum%Mo;
}
}
int main()
{ scanf("%d",&t);
  for (;t--;)
{ scanf("%d%d%d%d",&l,&r,&l1,&r1);
  X=(ask((ld)l1,(ld)r1)-ask((ld)(l-1),(ld)r1)-ask((ld)l1,(ld)(r-1))+ask((ld)(l-1),(ld)(r-1))); 
  if (X>=1e10) printf("...");
  ans=Ask((ll)l1,(ll)r1)-Ask((ll)(l-1),(ll)r1)-Ask((ll)l1,(ll)(r-1))+Ask((ll)(l-1),(ll)(r-1));
  while (ans<0) ans+=Mo;
  ans%=Mo;
   if (X>=1e10) printf("%010I64d\n",ans); else 
   printf("%I64d\n",ans);
}
}