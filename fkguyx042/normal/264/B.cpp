#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Node{int ed,before;}s[3000001];
int fox[100001],Max[100001],k1;
int f[100001],ans,a[100001];
int i,j,m,n,p,k;
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
void Do(int x)
{ int i,y=x;
   for (i=2;i<=(int)sqrt(x);i++)
     if (x%i==0)
     {   add(y,i);
        while (x%i==0) x/=i; }
    if (x>1) add(y,x);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=100000;i++)
    Do(i);
for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  { f[i]=1;
     for (j=fox[a[i]];j;j=s[j].before)
        f[i]=max(f[i],Max[s[j].ed]+1);
     for (j=fox[a[i]];j;j=s[j].before)
        Max[s[j].ed]=max(Max[s[j].ed],f[i]);
     ans=max(ans,f[i]);
  }
  printf("%d\n",ans);
}