#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int i,j,m,n,p,k;
long long ans;
int a[1001][1001];
struct Node{int x;};
priority_queue<Node>Q;
inline int operator <(Node a,Node b) { return a.x<b.x;}
long long row[1000001],col[1000001];
int main()
{  scanf("%d%d%d%d",&n,&m,&k,&p);
  for (i=1;i<=n;i++) for (j=1;j<=m;j++) scanf("%d",&a[i][j]);
  for (i=1;i<=n;i++) 
  {Node sum; sum.x=0;
    for (j=1;j<=m;j++) sum.x+=a[i][j];
    Q.push(sum);
  }
  for (i=1;i<=k;i++)
  { Node sum=Q.top();
    row[i]=row[i-1]+sum.x;
    Q.pop(); sum.x-=p*m; Q.push(sum); }
for (;!Q.empty();) Q.pop();
  for (i=1;i<=m;i++) 
  {Node sum; sum.x=0;
    for (j=1;j<=n;j++) sum.x+=a[j][i];
    Q.push(sum);
  }
  for (i=1;i<=k;i++)
  { Node sum=Q.top();
    col[i]=col[i-1]+sum.x;
    Q.pop(); sum.x-=p*n; Q.push(sum); }
ans=(long long)-1e15;
  for (i=0;i<=k;i++)
  ans=max(ans,row[i]+col[k-i]-1ll*p*i*(k-i));
printf("%I64d\n",ans);
}