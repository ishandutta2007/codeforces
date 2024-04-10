#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long INF=(long long)1e16;
int i,j,m,n,p,k,q;
int v[100001],c[100001];
long long f[100001],Max[100001],ans;
int Mmax,Cmax,A,B;
void change(int x)
{  if (x==Mmax) return;
   if (Mmax==0||Max[x]>Max[Mmax])
   {   Cmax=Mmax;
       Mmax=x;
       return;
   }
   if (x==Cmax) return;
   if (Cmax==0||Max[x]>Max[Cmax]) { Cmax=x; return;}
}
int main()
{scanf("%d%d",&n,&q);
  for (i=1;i<=n;i++) scanf("%d",&v[i]);
  for (i=1;i<=n;i++) scanf("%d",&c[i]);
  for (;q--;)
 { scanf("%d%d",&A,&B);
   Mmax=Cmax=0;
     ans=0;
   for (i=1;i<=n;i++) Max[i]=-(long long)1e17;
   for (i=1;i<=n;i++)
   {  f[i]=1ll*v[i]*B;
      if (Max[c[i]]>-INF) f[i]=max(f[i],Max[c[i]]+1ll*v[i]*A);
      if (Mmax>0)
    {    if (Mmax==c[i])
          {     if (Cmax!=0) f[i]=max(f[i],Max[Cmax]+1ll*v[i]*B); 
          }
          else f[i]=max(f[i],Max[Mmax]+1ll*v[i]*B);
    }
      if (f[i]>Max[c[i]])
       {  Max[c[i]]=f[i];
           change(c[i]);
       }
    ans=max(ans,f[i]);
}
printf("%I64d\n",ans);
}
}