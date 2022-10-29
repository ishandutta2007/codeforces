#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int True[100001],False[100001],size;
int a[100001],vis[100001],n,m,i;
int main()
{  scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
{ scanf("%d",&a[i]);
   if (a[i]>0)
{   True[a[i]]++;
    True[0]++;
}
else {
	   False[-a[i]]++;
	   False[0]++;
     }
}
for (i=1;i<=n;i++)
{  int sum=True[i]+(False[0]-False[i]);
   if (sum==m)
   { size++;
     vis[i]=1;
   }
}
for (i=1;i<=n;i++)
 if (size==1)
{  if (a[i]>0)
   if (vis[a[i]]) printf("Truth\n");
   else printf("Lie\n");
   if (a[i]<0)
   if (!vis[-a[i]]) printf("Truth\n");
   else printf("Lie\n");
} else 
 {   if (a[i]>0)
      if (!vis[a[i]]) printf("Lie\n");
      else printf("Not defined\n");
     if (a[i]<0)
       if (vis[-a[i]]) printf("Not defined\n");
       else printf("Truth\n");
}
}