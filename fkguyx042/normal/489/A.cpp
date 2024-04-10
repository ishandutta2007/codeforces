#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int A[3001][2];
int B[3001],a[3001];
int id[3001];
bool cmp(int A,int B) { return a[A]<a[B]; }
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i;
  sort(id+1,id+n+1,cmp);
  for (i=1;i<=n;i++)
  id[i]=a[id[i]];
  for (i=1;i<=n;i++)
   if (id[i]!=a[i]) 
     for (j=i+1;j<=n;j++)
      if (a[j]==id[i])
     {  ++ans; A[ans][0]=i-1;
        A[ans][1]=j-1;
        swap(a[i],a[j]);
        break;
     }
   printf("%d\n",ans);
  for (i=1;i<=ans;i++) printf("%d %d\n",A[i][0],A[i][1]);
}