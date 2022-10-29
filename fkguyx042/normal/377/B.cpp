#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct node{int bh;int cost;int ny;}b[100001],a[100001];
inline int operator <(node a,node b)
 { return a.cost>b.cost;}
inline bool cmp(node a,node b)
 { if (a.ny!=b.ny) return a.ny<b.ny;
    return a.cost<b.cost;
}
inline bool cmp1(node a,node b)
 {return a.ny<b.ny;}
inline bool cmp2(node a,node b)
 {return a.bh<b.bh;}
int i,j,m,n,p,k,pp,l,r,mid;
node x;
int q1[100001];
bool check(int mid)
 { int r1,ss;  r1=n;
        ss=0;  priority_queue<node>q;
      for (int pp=m;pp>0;pp-=mid)
       {   for (;r1&&b[r1].ny>=a[pp].ny;r1--)
           { x.bh=b[r1].bh;
             x.cost=b[r1].cost;
             q.push(x);
             }
           x=q.top();
           for (int i=pp;i>=max(1,pp-mid+1);i--)
           q1[i]=x.bh;
           ss+=x.cost;
            if (ss>k) return false;
           q.pop();
           }
 for (i=1;i<=m;i++)
   a[i].cost=q1[i];
   return true;
}
int main()
 { scanf("%d%d%d",&n,&m,&k);
   for (i=1;i<=m;i++)
    scanf("%d",&a[i].ny),a[i].bh=i;
   for (i=1;i<=n;i++)
     scanf("%d",&b[i].ny),b[i].bh=i;
   for (i=1;i<=n;i++)
    scanf("%d",&b[i].cost);
 sort(a+1,a+m+1,cmp1);
 sort(b+1,b+n+1,cmp);
 if (a[m].ny>b[n].ny) { printf("NO\n"); return 0;}
 for (i=n;i&&b[i].ny>=a[m].ny;i--);
   if (b[i+1].cost>k) {printf("NO\n"); return 0;}
 printf("YES\n");
 l=1;
 r=m+1;
 while ((mid!=(l+r)>>1))
   {  mid=(l+r)>>1;
     if (check(mid))
      r=mid; else l=mid;
      }
 sort(a+1,a+m+1,cmp2);
 for (i=1;i<=m-1;i++)
  printf("%d ",a[i].cost);
 printf("%d\n",a[m].cost);
 return 0;
}