#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
long long i,j,m,n,p,k,l,r,d,ans,Ans;
long long Tree[400001];
long long b[100001],a[100001],tot,f[100001],Q[100001];
void update(int ll,int l,int r,int t)
{ if (l==r) Tree[t]=max(Tree[t],ans+1);
  else {  if (ll<=mid) update(ll,l,mid,ls);
          else update(ll,mid+1,r,rs);
      Tree[t]=max(Tree[ls],Tree[rs]);
      }
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr) ans=max(ans,Tree[t]);
  else { if(ll<=mid) ask(ll,rr,l,mid,ls);
         if (rr>mid) ask(ll,rr,mid+1,r,rs);
  }
}   
int main()
{ scanf("%I64d%I64d",&n,&d);
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]),b[i]=a[i];
  sort(b+1,b+n+1);
  tot=unique(b+1,b+n+1)-(b+1);
  for (i=1;i<=n;i++)
  {  l=lower_bound(b+1,b+tot+1,a[i]-d)-b;
     if (b[l]!=a[i]-d) l--;
     r=lower_bound(b+1,b+tot+1,a[i]+d)-b;
     ans=0;
     if (b[1]<=a[i]-d)
     ask(1,l,1,tot,1);
     if (b[tot]>=a[i]+d)
     ask(r,tot,1,tot,1);
     Ans=max(Ans,ans+1);
     f[i]=ans+1;
     update(lower_bound(b+1,b+tot+1,a[i])-b,1,tot,1);
  }
  printf("%I64d\n",Ans);
  for (i=n;i;i--)
    if (f[i]==Ans)
    {   Q[++Q[0]]=i; 
        for (j=i-1,p=a[i];j;j--)
          if (f[j]==Ans-1&&abs(p-a[j])>=d) 
            { Q[++Q[0]]=j; Ans--; p=a[j]; }
            break;
}
for(i=Q[0];i;i--) printf("%I64d ",Q[i]);
}