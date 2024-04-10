#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[101],a[101];
int B[101];
int i,j,m,n,p,k,x,y;
void DoA()
{ int c[101],i;
   for (i=1;i<=n;i++) c[i]=a[A[i]];
   memcpy(a,c,sizeof(c));
}
void DoB()
{ int c[101],i;
  for (i=1;i<=n;i++) 
  c[A[i]]=a[i];
 memcpy(a,c,sizeof(c));
}
int Check()
{ int i;
  for (i=1;i<=n;i++) if (a[i]!=B[i]) return false;
  return true;
}
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&A[i]);
  for (i=1;i<=n;i++) scanf("%d",&B[i]);
  for (i=1;i<=n;i++) a[i]=i;
  for (x=0;!Check()&&x<=k;DoA(),x++);
    for (i=1;i<=n;i++) a[i]=i;
  for (y=0;!Check()&&y<=k;DoB(),y++);
  if ((k-x)&1&&(k-y)&1||(k>1&&x==1&&y==1)||!x) printf("NO\n");
  else 
printf("YES\n");
}