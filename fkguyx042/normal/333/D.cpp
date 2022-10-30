#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Max;
int a[1001][1001],f[1001][1001],St[1000001];
bool check(int x)
{  int sum=0,i,j,I;
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++) { sum=0;
     for (j=1;j<=m;j++)
        if (a[i][j]>=x) 
         St[++sum]=j;
     for (I=1;I<sum;I++)
       for (j=I+1;j<=sum;j++) 
         if (f[St[I]][St[j]]) return true;
          else f[St[I]][St[j]]=1;
          }
       return false;
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
     scanf("%d",&a[i][j]),Max=max(Max,a[i][j]);
    int l=0,r=Max+1,mid=0;
    for (;(l+r)>>1!=mid;)
     { mid=(l+r)>>1;
       if (check(mid)) l=mid; else r=mid;
     }
  printf("%d\n",l);
}