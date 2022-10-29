#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int Tree[100001],a[100001];
int lowbit(int x) { return x&-x; }
void insert(int x,int c)
{ for (;x<=n;x+=lowbit(x)) Tree[x]=max(Tree[x],c); }
int ask(int x) { int sum=0; for (;x;x-=lowbit(x)) sum=max(sum,Tree[x]);  return sum; }
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
  {   scanf("%d",&p);
      k=ask(p-1)+1; 
	  ans=max(ans,k);
	  insert(p,k);
}
printf("%d\n",ans);
}