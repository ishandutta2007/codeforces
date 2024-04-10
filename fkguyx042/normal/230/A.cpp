#include<cstdio>
#include<algorithm>
using namespace std;
struct node{int l;int r;}a[10001];
int i,j,m,n,p,k,s;
inline bool cmp(node a,node b) { if (a.l!=b.l) return a.l<b.l; return a.r>b.r;}
int main()
 {scanf("%d%d",&s,&n);
   for (i=1;i<=n;i++)
    scanf("%d%d",&a[i].l,&a[i].r);
 sort(a+1,a+n+1,cmp);
  for (i=1;i<=n;i++)
   { if (s<=a[i].l) break;
     s+=a[i].r;
}
 if (i==n+1) printf("YES\n");else printf("NO\n");
 return 0;
}