#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{int before,ed;}l[200001],r[200001];
int LX[200001],RX[200001],L[200001],R[200001],a[200001],from[200001],k1,k2;
long long Tree[200001],Ans[200001];
int n,m,i,j;
int lowbit(int x) {return x&-x;}
void insert(int x) {for (;x<=n;x+=lowbit(x)) Tree[x]++;}
long long ask(int x){ int sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
void add(int p1,int p2) {l[++k1].ed=p2; l[k1].before=LX[p1]; LX[p1]=k1; }
void Add(int p1,int p2) {r[++k2].ed=p2; r[k2].before=RX[p1]; RX[p1]=k2; }
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),from[a[i]]=i;
  for (i=1;i<=m;i++) scanf("%d%d",&L[i],&R[i]),add(L[i],i),Add(R[i],i);
  for (i=1;i<=n;i++)
{   for (j=LX[i];j;j=l[j].before)
        Ans[l[j].ed]-=ask(R[l[j].ed])-ask(i-1);
    for (j=1;a[i]*j<=n;j++) insert(from[a[i]*j]);
    for (j=RX[i];j;j=r[j].before)
      Ans[r[j].ed]+=ask(i)-ask(L[r[j].ed]-1);
}
for (i=1;i<=m;i++)
printf("%I64d\n",Ans[i]);
}