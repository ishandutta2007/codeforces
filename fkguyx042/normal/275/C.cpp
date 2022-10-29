#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,tot,size[100001],belong[100001],a[100001],fox[100001],all,k1,f[100001],G[100001],ans,R[100001];
struct Node{int before,size;}s[100001];
void add(int x,int y) { s[++k1].size=y; s[k1].before=fox[x]; fox[x]=k1; }
int Do(int x)
{  int i,Kth=0,sum=0;
   for (i=fox[x];i;i=s[i].before) G[++Kth]=s[i].size,sum;
   for (i=Kth;i;i--)
   {  f[i]=G[i];
      if (i+2<=Kth) f[i]=max(f[i],f[i+2]+G[i]);
      if (i+3<=Kth) f[i]=max(f[i],f[i+3]+G[i]);
      sum=max(sum,f[i]);
   }
return sum;
}
int main()
{  scanf("%d%d",&n,&k);
  if (k==1) {printf("%d\n",n); return 0;}
   for (i=1;i<=n;i++)
     scanf("%d",&a[i]);
sort(a+1,a+n+1);
  for (i=1;i<=n;i++)
   if (a[i]!=a[i-1])
   { R[++tot]=a[i];
     size[tot]=1;
   } else size[tot]++;
  for (i=1;i<=n;i++)
   if (R[i]%k==0)
 {  int y=R[i]/k;
    int Rt=lower_bound(R+1,R+i+1,y)-R;
    if (R[Rt]==y) 
     { belong[i]=belong[Rt];
       add(belong[i],size[i]);
     }
     else belong[i]=++all,add(belong[i],size[i]);
} else belong[i]=++all,add(belong[i],size[i]);
for (i=1;i<=all;i++) ans+=Do(i);
printf("%d\n",ans);
}