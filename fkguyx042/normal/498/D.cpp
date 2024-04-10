#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,ans,a[100001],x,y,flag;
char c;
struct Node{int sum[60];}Tre[400005];
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr)  
  {  ans+=Tre[t].sum[ans%60];
  }
  else { if (ll<=mid) ask(ll,rr,l,mid,ls);
         if (rr>mid) ask(ll,rr,mid+1,r,rs);
       }
}
void update(int ll,int l,int r,int t)
{ if (l==r) { int i;
  for (i=0;i<60;++i) if (i%a[l]==0) Tre[t].sum[i]=2;
  else Tre[t].sum[i]=1;
  }
  else { if (ll<=mid) update(ll,l,mid,ls);
         else update(ll,mid+1,r,rs);
         int i;
         for (i=0;i<60;i++)
          Tre[t].sum[i]=Tre[ls].sum[i]+Tre[rs].sum[(i+Tre[ls].sum[i])%60];
         }
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for (i=1;i<=n;i++) update(i,1,n,1);
  for (i=1;i<=m;i++)
{ while (c=getchar(),c!='A'&&c!='C');
  if (c=='C')
  {  scanf("%d%d",&x,&y);
     a[x]=y;
     update(x,1,n,1);
  }
  else {
         ans=0;  flag=0;
         scanf("%d%d",&x,&y); y--;
         ask(x,y,1,n,1);
         printf("%d\n",ans);
       }
}
}