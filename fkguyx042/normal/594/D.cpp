#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls Tree[t].l
#define rs Tree[t].r
#define Ls Tree[t1].l
#define Rs Tree[t1].r
#define mid ((l+r)>>1)
#include<vector>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,root[200005],tot,Q,sum[200005],inv[200005],x,y,ans;
int Ni[1000005],Rev[1000005],Last[1000005];
vector<int>v[200005];
struct Node{int sum,l,r,id;}Tree[10000005];
int a[200005];
void up(Node &x,Node y,Node z)
{
      x.sum=1ll*(!y.sum?1:y.sum)*(!z.sum?1:z.sum)%Mo;
}
int power(int x,int y)
{
      int sum=1;
      for (;y;y>>=1)
    {
          if (y&1) sum=1ll*x*sum%Mo;
          x=1ll*x*x%Mo;
    }
    return sum;
}
void update(int ll,int c,int l,int r,int t,int t1)
{ 
     if (l==r) 
     {
                if (!Tree[t].sum) Tree[t].sum=c;
                else Tree[t].sum=1ll*Tree[t].sum*c%Mo;
     }
     else
     {
            if (ll<=mid)
            {
                          if (Tree[ls].id!=i) 
                          { 
                                             ls=++tot;
                                             Tree[ls]=Tree[Ls];
                                             Tree[ls].id=i;
                          }
                                             update(ll,c,l,mid,ls,Ls);
            }
            else
            {
                          if (Tree[rs].id!=i)
                          {
                                              rs=++tot;
                                              Tree[rs]=Tree[Rs];
                                              Tree[rs].id=i;
                          }
                                               update(ll,c,mid+1,r,rs,Rs);
            }
           up(Tree[t],Tree[ls],Tree[rs]);
      }
}
void pre()
{
       for (i=1;i<=n;++i) scanf("%d",&a[i]);
       sum[1]=a[1];
       inv[0]=1;
       for (i=2;i<=n;++i) sum[i]=1ll*sum[i-1]*a[i]%Mo;
       for (i=1;i<=n;++i) inv[i]=power(sum[i],Mo-2); 
       for (i=1;i<=n;++i)
       {
         for (j=2;j*j<=a[i];++j)
            if (a[i]%j==0)
            {
                  v[i].push_back(j);
                  while (!(a[i]%j)) a[i]/=j;
            }
            if (a[i]>1) v[i].push_back(a[i]);
       }
        for (i=n;i;--i)
       {
           root[i]=++tot;
           Tree[root[i]]=Tree[root[i+1]];
           for (j=0;j<v[i].size();++j)
           {
               p=v[i][j];
               if (Last[p]) 
               {  
                   if (!Rev[p]) Rev[p]=1ll*p*power(p-1,Mo-2)%Mo;
                   update(Last[p],Rev[p],1,n,root[i],root[i+1]);
               }
               Last[p]=i;
               if (!Ni[p]) Ni[p]=1ll*(p-1)*power(p,Mo-2)%Mo;
               update(i,Ni[p],1,n,root[i],root[i+1]);
           }
      }
}
void ask(int ll,int rr,int l,int r,int t)
{
        if (!t) return;
        if (ll<=l&&r<=rr) ans=1ll*ans*(!Tree[t].sum?1:Tree[t].sum)%Mo;
        else
        {
              if (ll<=mid) ask(ll,rr,l,mid,ls);
              if (rr>mid)  ask(ll,rr,mid+1,r,rs);
        }
}
int main()
{
     scanf("%d",&n);    
     pre();
     scanf("%d",&Q);
     for (;Q--;)
    {
          scanf("%d%d",&x,&y);
          ans=1;
          ask(x,y,1,n,root[x]);
          ans=1ll*ans*sum[y]%Mo*inv[x-1]%Mo;
          printf("%d\n",ans);
    }
}