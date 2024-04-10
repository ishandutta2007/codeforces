#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int ed,before;}s[100001];
int A[3001][3001];
int B[3001][3001];
int i,j,m,n,p,k,sum,x,y,l,r;
long long ans;
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=m;i++)
  { scanf("%d%d",&x,&y);
    A[x][++A[x][0]]=y;
    B[y][++B[y][0]]=x;
  }
  for (i=1;i<=n;i++)
  sort(A[i]+1,A[i]+A[i][0]+1),sort(B[i]+1,B[i]+B[i][0]+1);
  for (i=1;i<=n;i++)
   for (j=1;j<=n;j++)
    if (i!=j)
   {   l=r=1; sum=0;
       while (l<=A[i][0]&&r<=B[j][0])
      {    if (A[i][l]==B[j][r]) l++,r++,sum++;
           else if (A[i][l]<B[j][r]) l++;
           else r++;
      }
      ans+=sum*(sum-1)/2ll;
   }
  printf("%I64d\n",ans);
  //for (;;);
}