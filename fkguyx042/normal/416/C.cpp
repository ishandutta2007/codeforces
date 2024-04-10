#include<cstdio>
#include<algorithm>
using namespace std;
using namespace std;
struct node{int num;int big;int ss;}s[1001];
node a[1001];
int ans[1001];
int flag[1001];
int i,j,m,n,p,k,sum,ans1;
inline bool cmp(node a,node b)
  { if (a.num!=b.num) return a.num>b.num;
    return a.big<b.big;
}
inline bool cmp1(node a,node b)
  { return a.big<b.big;
}
int main()
 { scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d%d",&a[i].big,&a[i].num),a[i].ss=i;
    sort(a+1,a+n+1,cmp);
    scanf("%d",&k);
      for (i=1;i<=k;i++)
      scanf("%d",&s[i].big),s[i].ss=i;
 sort(s+1,s+k+1,cmp1);
 for (i=1;i<=n;i++)
   {   for (j=1;j<=k;j++)
         if (!flag[j]&&a[i].big<=s[j].big)
           {  flag[j]=1;
               sum+=a[i].num;
               ans[a[i].ss]=s[j].ss;
              break;
              }
              }
 for (i=1;i<=n;i++) 
   if (ans[i]>0) ans1++;       
  printf("%d %d\n",ans1,sum);
   for (i=1;i<=n;i++)
    if (ans[i]>0)
     printf("%d %d\n",i,ans[i]);
     return 0;
     
     }