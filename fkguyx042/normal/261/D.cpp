#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int Tree[100005],a[100005],ans[100005];
int i,j,m,n,p,k,b,t;
int lowbit(int x) {return x&-x;}
int Ask(int x) { int sum=0; for (;x;x-=lowbit(x)) sum=max(sum,Tree[x]); return sum; }
void Change(int x,int y) { for (;x<=b;x+=lowbit(x)) Tree[x]=max(Tree[x],y); }
int Got()
{ memset(Tree,0,sizeof(Tree));
  memset(ans,0,sizeof(ans));
  int i,j,k;
   for (i=1;i<=t;i++)
     for (j=1;j<=n;j++)
       {  k=Ask(a[j]-1)+1;
         if (ans[a[j]]<k)
         {    ans[a[j]]=k;
              Change(a[j],k);
         }
    }
    return Ask(b);
}
int main()
{scanf("%d%d%d%d",&k,&n,&b,&t);
  for (;k--;)
  {   for (i=1;i<=n;i++) scanf("%d",&a[i]);
      if (t>=b)
      {  sort(a+1,a+n+1);
         printf("%d\n",unique(a+1,a+n+1)-(a+1));
         continue;
    }
    else printf("%d\n",Got());
  }
}