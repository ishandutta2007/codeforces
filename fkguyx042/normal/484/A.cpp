#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long l,r,A,B,ans;
long long Go(long long x,long long y)
{ return x>>y&1; }
int main()
{ scanf("%d",&n);
  for (j=1;j<=n;j++)
  { scanf("%I64d%I64d",&l,&r); ans=0;
    r++;
    for (i=62;i>=0;i--)
     { A=Go(l,i); B=Go(r,i);
       if (A==B){ if (A) ans+=1ll<<i; }
       else{ ans+=(1ll<<i)-1; break; }
     }
     printf("%I64d\n",ans);
  }
}