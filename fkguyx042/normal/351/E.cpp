#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans=0,x,sum,tot;
int b[2001],a[2001],Q[4002];
int Tree[4002];
int lowbit(int x) {return x&-x; }
int ask(int x)
{ int sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
void insert(int x) { for (;x<=tot;x+=lowbit(x)) Tree[x]++; }
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]); 
 int f=1;
 while (f)
 { f=0;
    for (i=1;i<=n;i++)
     { sum=0;  for (j=1;j<i;j++)
               {if (a[j]>a[i]&&a[j]<=-a[i]) sum++;
                if (a[i]>=a[j]&&a[j]>-a[i]) sum--;
               }
               for (j=i+1;j<=n;j++)
               { if (a[j]<a[i]&&a[j]>=-a[i]) sum++;
                 if (a[j]>=a[i]&&a[j]<-a[i]) sum--;
               }
          if (sum>0) a[i]=-a[i],f=1;
}
}
for (i=1;i<=n;i++)
  for (j=1;j<i;j++)
   if (a[j]>a[i]) ans++;
   printf("%d\n",ans);
}