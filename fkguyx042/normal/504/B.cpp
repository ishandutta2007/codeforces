#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x;
int Tree[1000001],size[1000001];
int lowbit(int x) {return x&-x;}
void insert(int x)
{  for (;x<=n;x+=lowbit(x)) Tree[x]++; }
int ask(int x) 
{int sum=0; for (;x;x-=lowbit(x)) sum+=Tree[x]; return sum; }
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) 
  {  scanf("%d",&x); x++;
     size[n-i]=x-1-ask(x);
     insert(x);
  }
  memset(Tree,0,sizeof(Tree));
 for (i=1;i<=n;i++) 
  {  scanf("%d",&x); x++;
     size[n-i]+=x-1-ask(x);
     insert(x);
  }
 for (i=n;i;i--)  if (size[n-i]>=(n-i+1)) size[n-i+1]+=size[n-i]/(n-i+1),size[n-i]%=(n-i+1);
   memset(Tree,0,sizeof(Tree));
 for (i=1;i<=n;i++)
{   int l=1,r=n+1,mid=0;
  for (;(l+r)>>1!=mid;)
  {  mid=(l+r)>>1;
     if (mid-1-ask(mid)>=size[n-i]) r=mid; else l=mid;
  }
  printf("%d ",r-1);
  insert(r);
}
}