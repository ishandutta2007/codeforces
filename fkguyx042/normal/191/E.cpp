#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,tot;
long long l,r,k,mid,a[100005],Tree[100005],Q[100005];
int lowbit(int x) { return x&-x;}
void insert(int x) 
{  for (;x<=tot;x+=lowbit(x)) Tree[x]++; }
long long ask(int x)
{  long long sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
inline bool check(long long x)
{  memset(Tree,0,sizeof(Tree));
   long long ans=0; int i,j,R;
   insert(lower_bound(Q+1,Q+tot+1,0)-Q);
   for (i=1;i<=n;i++)
   {   R=upper_bound(Q+1,Q+tot+1,a[i]-x)-Q;
       --R;
       ans+=ask(R);
       insert(lower_bound(Q+1,Q+tot+1,a[i])-Q);
   }
 if (ans>=k) return true;
 return false;
}
int main()
{ scanf("%d%I64d",&n,&k); 
  for (i=1;i<=n;i++) { 
       scanf("%I64d",&a[i]);
       if (a[i]<0) l+=a[i];
       else r+=a[i];
       a[i]+=a[i-1];
}
r++;
for (i=1;i<=n;i++) Q[i]=a[i]; tot=n; Q[++tot]=0;
sort(Q+1,Q+tot+1); tot=unique(Q+1,Q+tot+1)-(Q+1);
mid=1ll<<60ll;
for (;(l+r)/2ll!=mid;)
{  mid=(l+r)/2ll;
   if (check(mid)) l=mid;
   else r=mid;
}
printf("%I64d\n",l);
}