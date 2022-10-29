#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,x,a[100001],tot,ed,l,r,size[331],ans;
int Que[331][50001];
int All[331][100001];
int ask(int l,int r,int K)
{ int i,ed=0,Ed=0,sum=0;
  for (i=1;i<=tot;i++)
   if (ed+size[i]<l) ed+=size[i]; else break;
  for (j=1;j<=tot;j++)
   if (Ed+size[j]<r) Ed+=size[j]; else break;
  if (i==j) {  for (k=l;k<=r;k++) if (Que[i][k-ed]==K) sum++; }
  else { for (k=i+1;k<j;k++) sum+=All[k][K];
         for (k=l-ed;k<=size[i];k++) if (Que[i][k]==K) sum++;
         for (k=Ed+1;k<=r;k++)  if (Que[j][k-Ed]==K) sum++;
    }
return sum;
}
void doit(int l,int r)
{  if (l==r) return;
   int i,j,ed=0,sum;
   for (i=1;i<=tot;i++) if (ed+size[i]<r) ed+=size[i]; else break;
   sum=Que[i][r-ed]; All[i][sum]--; size[i]--;
   for (j=r-ed;j<=size[i];j++) Que[i][j]=Que[i][j+1]; ed=0;
   for (i=1;i<=tot;i++) if (ed+size[i]<l) ed+=size[i]; else break;
   size[i]++; for (j=size[i];j>l-ed;j--) Que[i][j]=Que[i][j-1]; Que[i][l-ed]=sum; All[i][sum]++;
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  x=(int)sqrt(n);
  for (i=1;i<=n;i=ed+1)
  {    ed=min(n,i+x-1);
      size[++tot]=ed-i+1;
      for (j=i;j<=ed;j++)
        Que[tot][j-i+1]=a[j],All[tot][a[j]]++;
}
scanf("%d",&m);
  for (i=1;i<=m;i++)
  {  scanf("%d",&p);
     if (p==1)
     {   scanf("%d%d",&l,&r);
         l=(l+ans-1)%n+1; r=(r+ans-1)%n+1;
         if (l>r) swap(l,r);
         doit(l,r);
}
else { 
      scanf("%d%d%d",&l,&r,&k);
         l=(l+ans-1)%n+1; r=(r+ans-1)%n+1; k=(k+ans-1)%n+1; if (l>r) swap(l,r);
         printf("%d\n",ans=ask(l,r,k));
   }
}
}