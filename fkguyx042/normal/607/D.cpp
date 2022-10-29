#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 200005

using namespace std;
const int Mo=(int)1e9+7;
vector<int>v[N];
int st[N],ed[N],tc;
int i,j,m,n,p,k,val[N],tot=1,size[N];
struct Node{int type,u,v;}Q[N];
struct Tre{int add[N*4],sum[N*4];
   int ask(int ll,int l,int r,int t)
   {
   	  if (l==r) return sum[t];
   	  if (ll<=mid) return 1ll*sum[t]*ask(ll,l,mid,ls)%Mo;
   	  else return 1ll*sum[t]*ask(ll,mid+1,r,rs)%Mo;
   }
   void modify(int ll,int rr,int c,int l,int r,int t)
   {
   	 if (ll<=l&&r<=rr) sum[t]=1ll*sum[t]*c%Mo;
   	 else
   	 {
   	 	  if (ll<=mid) modify(ll,rr,c,l,mid,ls);
   	 	  if (rr>mid)  modify(ll,rr,c,mid+1,r,rs);
   	 }
   }
   void down(int t)
   {
   	  if (add[t]==1) return;
   	  sum[ls]=1ll*sum[ls]*add[t]%Mo;
   	  add[ls]=1ll*add[ls]*add[t]%Mo;
   	  sum[rs]=1ll*sum[rs]*add[t]%Mo;
   	  add[rs]=1ll*add[rs]*add[t]%Mo;   	
	  add[t]=1;
   } 
   void upd(int ll,int c,int l,int r,int  t)
   {
   	   if (l==r) sum[t]=c;
   	   else 
   	   {
   	   	 down(t);
   	   	 if (ll<=mid) upd(ll,c,l,mid,ls);
   	   	 else upd(ll,c,mid+1,r,rs);
   	   	 sum[t]=(sum[ls]+sum[rs])%Mo;
   	   }
   }
   void Modify(int ll,int rr,int c,int l,int r,int t)
   {
   	    if (ll<=l&&r<=rr)
   	    {
   	    	  add[t]=(1ll*add[t]*c)%Mo;
   	    	   sum[t]=1ll*sum[t]*c%Mo;
   	    }
   	    else 
   	    {
   	    	  down(t);
   	    	  if (ll<=mid) Modify(ll,rr,c,l,mid,ls);
   	    	  if (rr>mid)  Modify(ll,rr,c,mid+1,r,rs);
   	    	  sum[t]=(sum[ls]+sum[rs])%Mo;
   	    }
   }
   int Ask(int ll,int rr,int l,int r,int t)
   {
   	  if (ll<=l&&r<=rr) return sum[t];
   	  else 
   	  {
   	  	   down(t);
   	  	   int Sum=0;
   	  	   if (ll<=mid) (Sum+=Ask(ll,rr,l,mid,ls))%=Mo;
   	  	   if (rr>mid)  (Sum+=Ask(ll,rr,mid+1,r,rs))%=Mo;
   	  	   return Sum;
   	  }
   }
 }tree,Tree;
inline int read()
{
	 int x; char c;
	 while (c=getchar(),c<'0'||c>'9');
	 x=c-'0';
	 while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	 return x;
}
void jia(int &x,int y)
{
	 x+=y;
	 if (x>=Mo) x-=Mo;
}
void build(int l,int r,int t)
{
	 tree.add[t]=1;
	 Tree.sum[t]=1;
	 if (l==r) return;
	 build(l,mid,ls); build(mid+1,r,rs);
}
void dfs(int x)
{
	 int i;
	 st[x]=++tc;
	 for (i=0;i<(int)v[x].size();++i) dfs(v[x][i]);
	 ed[x]=tc;
}
int power(int x,int y)
{
	 int sum=1;
	 for (;y;y>>=1)
	 {
	 	 if (y&1)
	 	 sum=1ll*sum*x%Mo;
	 	 x=1ll*x*x%Mo;
	 }
	 return sum;
}
int main()
{
	 scanf("%d%d",&val[1],&n);
	 for (i=1;i<=n;++i)
	 { 
	    Q[i].type=read();
	    if (Q[i].type==1)
	    {
	    	 Q[i].u=read(); Q[i].v=++tot; val[Q[i].v]=read();
	    	 v[Q[i].u].push_back(Q[i].v);
	    }
	    else Q[i].u=read();
    }
    for (i=1;i<=tot;++i) size[i]=1;
    build(1,tot,1);
    dfs(1);
    tree.upd(1,val[1],1,tot,1); 
    for (i=1;i<=n;++i)
      if (Q[i].type==1)
      {
      	    int sum=Tree.ask(st[Q[i].v],1,tot,1);
      	    tree.upd(st[Q[i].v],1ll*sum*val[Q[i].v]%Mo,1,tot,1);
      	    size[Q[i].u]++; int Sum=1ll*size[Q[i].u]*power(size[Q[i].u]-1,Mo-2)%Mo;
      	    Tree.modify(st[Q[i].u],ed[Q[i].u],Sum,1,tot,1);
      	    tree.Modify(st[Q[i].u],ed[Q[i].u],Sum,1,tot,1);
      }
      else 
      {
      	 int Sum=tree.Ask(st[Q[i].u],ed[Q[i].u],1,tot,1);
      	 printf("%d\n",1ll*Sum*
		 power(Tree.ask(st[Q[i].u],1,tot,1),Mo-2)%Mo*size[Q[i].u]%Mo);
	  } 
}