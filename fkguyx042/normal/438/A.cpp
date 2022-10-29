#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int fox[1001];
int i,j,m,n,p,k,k1,b[1001],ans;
int sum[1001];
struct node{int ed,before;}s[10001];
int num[1001],vis[1001];
struct node19{int sum,num;}a[1001];
inline int cmp(node19 a,node19 b)
{ return a.sum>b.sum;}
void add(int p1,int p2)
 {s[++k1].ed=p2; s[k1].before=fox[p1]; fox[p1]=k1; }
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
   scanf("%d",&a[i].sum),a[i].num=i,b[i]=a[i].sum;
  sort(a+1,a+n+1,cmp);
for (i=1;i<=m;i++)
{ scanf("%d%d",&p,&k);
  add(p,k);
  add(k,p);
}
for (i=1;i<=n;i++)
 { vis[a[i].num]=1;
 for (j=fox[a[i].num];j;j=s[j].before)
 if (!vis[s[j].ed]) ans+=b[s[j].ed];
}
printf("%d\n",ans);
}