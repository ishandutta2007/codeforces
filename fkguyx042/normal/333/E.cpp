#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<cmath>
using namespace std;
bitset<3001>bit[3001];
int i,j,m,n,p,k,tot;
struct Node{int x,y,sum;}a[3001],Bian[4500001];
int sqr(int x) { return x*x;}
inline bool cmp(Node a,Node b) { return a.sum>b.sum; }
int dis(int x,int y)
{ return sqr(a[x].x-a[y].x)+sqr(a[x].y-a[y].y); }
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
  for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
      Bian[++tot].x=i,Bian[tot].y=j,Bian[tot].sum=dis(i,j);
  sort(Bian+1,Bian+tot+1,cmp);
  for (i=1;i<=tot;i++)
  {  int x=Bian[i].x;
     int y=Bian[i].y;
     if ((bit[x]&bit[y]).any())
     { printf("%.20lf\n",(double)sqrt((double)Bian[i].sum)/2.0);
       return 0;
     }
     bit[x][y]=bit[y][x]=1;
  }
}