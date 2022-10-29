#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,p1;
struct node{int l,r,sum;}bian[300001];
int fa[100001];
int value[100001],size[100001];
double ans;
inline bool cmp(node a,node b)
{ return a.sum>b.sum;}
int get(int x)
 { return fa[x]==x?x:fa[x]=get(fa[x]);}
int main()
{ scanf("%d%d",&n,&m);
 for (i=1;i<=n;i++)
  scanf("%d",&value[i]);
 for (i=1;i<=m;i++)
 { scanf("%d%d",&p,&p1);
   bian[i].l=p;
   bian[i].r=p1;
   bian[i].sum=min(value[p],value[p1]);
}
sort(bian+1,bian+m+1,cmp);
for (i=1;i<=n;i++) fa[i]=i,size[i]=1;
 for (i=1;i<=m;i++)
  { p=get(bian[i].l);
    p1=get(bian[i].r);
     if (p!=p1)
     { ans+=(double)size[p]*size[p1]*bian[i].sum/n/(n-1);
       size[p1]+=size[p];
       fa[p]=p1;
       }
}
printf("%.6lf\n",ans*2);
}