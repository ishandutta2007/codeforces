#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int Mo=(int)1e9+7;
long long i,j,m,n,p,k,l,r,x,ans;
long long y[6],New[6][100001];
char c[2];
long long R[6][6],a[100001];
struct Node{long long dis[6],add;}Tree[400001];
void build_tree(int l,int r,int t)
{  Tree[t].add=-1;
   if (l==r) { Tree[t].dis[0]=a[l];
                 int i; for (i=1;i<=5;i++) Tree[t].dis[i]=1ll*Tree[t].dis[i-1]*l%Mo;
             }
     else {
     	     build_tree(l,mid,ls); build_tree(mid+1,r,rs);
     	     int i; for (i=0;i<=5;i++) Tree[t].dis[i]=(Tree[ls].dis[i]+Tree[rs].dis[i])%Mo;
          }
}
void down(int t,int l,int r)
{  if (Tree[t].add==-1) return;
   int i;
   for (i=0;i<=5;i++)
   Tree[ls].dis[i]=1ll*Tree[t].add*(New[i][mid]-New[i][l-1]+Mo)%Mo,Tree[rs].dis[i]=1ll*Tree[t].add*(New[i][r]-New[i][mid]+Mo)%Mo;
   Tree[ls].add=Tree[rs].add=Tree[t].add;
   Tree[t].add=-1;
}
void Change(int ll,int rr,int x,int l,int r,int t)
{ if (ll<=l&&r<=rr)
  {   Tree[t].add=x;
      int i;
      for (i=0;i<=5;i++)
      Tree[t].dis[i]=1ll*x*(New[i][r]-New[i][l-1]+Mo)%Mo;
  }
  else {    down(t,l,r);
         if (ll<=mid) Change(ll,rr,x,l,mid,ls);
         if (rr>mid)  Change(ll,rr,x,mid+1,r,rs);
         int i;
         for (i=0;i<=5;i++)  Tree[t].dis[i]=(Tree[ls].dis[i]+Tree[rs].dis[i])%Mo;
      }
}
void ask(int ll,int rr,int x,int l,int r,int t)
{ if (ll<=l&&r<=rr)
  { int i;
    for (i=0;i<=x;i++)
     (ans+=1ll*Tree[t].dis[i]*y[i]%Mo*R[x][i]%Mo),(ans+=Mo)%=Mo;
  }
  else {
  	down(t,l,r);
  	  if (ll<=mid) ask(ll,rr,x,l,mid,ls);
         if (rr>mid)  ask(ll,rr,x,mid+1,r,rs);
}
}
int main()
{
   scanf("%I64d%I64d",&n,&m);
    for (i=1;i<=n;i++)
    {  New[0][i]=1;
       for (j=1;j<=5;j++)
        New[j][i]=1ll*New[j-1][i]*i%Mo;
       for (j=0;j<=5;j++)
          (New[j][i]+=New[j][i-1])%=Mo;
    }
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
  build_tree(1,n,1);
  for (i=0;i<=5;i++)
  {  R[i][0]=R[i][i]=1;
      for (j=1;j<i;j++) R[i][j]=R[i-1][j]+R[i-1][j-1];
}
  for (;m--;)
  { scanf("%s",&c);
   if (c[0]=='=')
   { scanf("%I64d%I64d%I64d",&l,&r,&x);
     Change(l,r,x,1,n,1);
   }
   else {
   	  scanf("%I64d%I64d%I64d",&l,&r,&x); ans=0;
   	  y[x]=1;
   	  for (i=x-1;i>=0;i--) y[i]=1ll*y[i+1]*(-(l-1))%Mo;
   	  ask(l,r,x,1,n,1);
   	  printf("%I64d\n",(ans+Mo)%Mo);
   }
 }
}