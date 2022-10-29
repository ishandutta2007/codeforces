#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y,r,tot,k1;
int sum[100001],Type[100001],A[100001],Id[100001],id[100001],fox[100001],type,Now[100001],Ans[100001],te[100001];
long long a[100001];
struct Node{long long x,y,type,id;}Qus[100001];
struct Bian{int edx,edy,before;}s[100001];
void add(int x,int y,int z)
{ s[++k1].edx=y; s[k1].edy=z; s[k1].before=fox[x]; fox[x]=k1; }
bool cmp(int a,int b) { return sum[a]>sum[b]; }
bool Cmp(int a,int b) { return te[a]<te[b]; }
bool Rmp(Node a,Node b) { return 1.0*a.x*b.y>1.0*b.x*a.y; }
int main()
{ scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
  for (i=1;i<=m;i++)
{ scanf("%d",&type);
  te[i]=type;
  if (type==1)
{ scanf("%d%d",&x,&y);
  if (y>A[x]) A[x]=y,Id[x]=i;
}
else if (type==2) 
{ scanf("%d%d",&x,&y); 
  add(x,y,i);
}
else if (type==3)
{ scanf("%d%d",&x,&y);
  Qus[++r].x=y;
  Qus[r].y=1;
  Qus[r].type=3;
  Qus[r].id=i;
}
}
for (i=1;i<=n;i++)
{  tot=0;
  for (j=fox[i];j;j=s[j].before)
  sum[++tot]=s[j].edx,id[tot]=s[j].edy,Type[tot]=2;
  if (A[i]>a[i]) sum[++tot]=A[i]-a[i],id[tot]=Id[i],Type[tot]=1;
  for (j=1;j<=tot;j++) Now[j]=j;
  sort(Now+1,Now+tot+1,cmp);
  for (j=1;j<=tot;j++)
  Qus[++r].y=a[i],Qus[r].x=a[i]+sum[Now[j]],Qus[r].type=Type[Now[j]],a[i]+=sum[Now[j]],Qus[r].id=id[Now[j]];
}
sort(Qus+1,Qus+r+1,Rmp);
k=min(r,k);
for (i=1;i<=k;i++) Ans[i]=Qus[i].id;
sort(Ans+1,Ans+k+1,Cmp);
printf("%d\n",k);
for (i=1;i<=k;i++) printf("%d ",Ans[i]);
}