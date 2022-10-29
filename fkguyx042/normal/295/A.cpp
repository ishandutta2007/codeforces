#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long tree[400001];
long long a[400001];
long long i,j,m,n,p,k,x,y,ans;
struct node{long long l,r,num;}ques[100001];
long long tree1[400001];
int lowbit(int x)
 { return x&-x;}
void add(int x,int c)
 { for (;x<=m;x+=lowbit(x)) tree[x]+=c; }
void update(int x,long long c)
 { for (;x<=n;x+=lowbit(x)) tree1[x]+=c;}
long long ask(int x)
 { long long ans=0;
   for (;x;x-=lowbit(x)) ans+=tree[x]; 
   return ans;}
 long long ask1(int x)
   { long long ans=0;
    for (;x;x-=lowbit(x)) ans+=tree1[x]; 
    return ans;
}
int main()
 {scanf("%I64d%I64d%I64d",&n,&m,&k);
  for (i=1;i<=n;i++)
   scanf("%I64d",&a[i]);
 for (i=1;i<=m;i++)
  scanf("%d%d%d",&ques[i].l,&ques[i].r,&ques[i].num); 
 for (i=1;i<=k;i++)
  {scanf("%d%d",&x,&y);
     add(x,1);
     add(y+1,-1);
}
  for (i=1;i<=m;i++)
   {  ans=(long long)ask(i);
      if (ans>0)
       { update(ques[i].l,(long long)ques[i].num*ans);
         update(ques[i].r+1,-(long long)ques[i].num*ans);
         }
         }
for (i=1;i<=n-1;i++)
 printf("%I64d ",a[i]+ask1(i));
 printf("%I64d\n",a[n]+ask1(n));
 return 0;
}