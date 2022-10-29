#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int Tree[500001],i,j,m,n,p,k,ans,tot;
int Q[500001];
struct Node{int x,y,z;}a[500001];
inline bool cmp(Node a,Node b){ 
        if (a.x!=b.x) return a.x>b.x;
        if (a.y!=b.y) return a.y>b.y;
return a.z>b.z;
     }
int lowbit(int x) { return x&-x;}
int ask(int x)
{int sum=0; for (;x;x-=lowbit(x)) sum=max(sum,Tree[x]); return sum; }
void insert(int x,int y)
{ for (;x<=tot;x+=lowbit(x)) Tree[x]=max(Tree[x],y); }
int main()
{
     scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i].x);
 for (i=1;i<=n;i++) scanf("%d",&a[i].y),Q[++tot]=a[i].y;
 for (i=1;i<=n;i++) scanf("%d",&a[i].z);
 sort(Q+1,Q+tot+1);
 tot=unique(Q+1,Q+tot+1)-(Q+1);
 sort(a+1,a+n+1,cmp);
 for (i=1;i<=n;i=j)
 {   for (j=i;a[j].x==a[i].x&&j<=n;j++)
       if (ask(tot-(lower_bound(Q+1,Q+tot+1,a[j].y)-Q))>a[j].z)
         ans++;
     for (k=i;k<j;k++)
       insert(tot-(lower_bound(Q+1,Q+tot+1,a[k].y)-Q)+1,a[k].z);
}
printf("%d\n",ans);
}