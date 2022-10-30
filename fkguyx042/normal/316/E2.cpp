#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005

#define mid ((l+r)>>1)
#define ls  (t<<1)
#define rs  ((t<<1)|1)

const int Mo=(int)1e9;

struct Node
{
	  int mat[2][2];
	  int lenx,leny;
}B[N],C[N],tree[N*4],Ans;
int n,m,i,a[N],len[N*4],add[N*4];
int type,u,l,r,x;
inline Node operator +(Node a,Node b)
{
	  Node c=a;
	  int i,j;
	  for (i=0;i<a.lenx;++i)
	    for (j=0;j<a.leny;++j)
	      c.mat[i][j]=(a.mat[i][j]+b.mat[i][j])%Mo;
	  return c;
}
inline Node operator *(Node a,Node b)
{
	 Node c={0};
	 c.lenx=a.lenx; c.leny=b.leny;
	 int i,j,k;
	 for (k=0;k<a.leny;++k)
	  for (i=0;i<a.lenx;++i)
	    for (j=0;j<b.leny;++j)
	      (c.mat[i][j]+=1ll*a.mat[i][k]*b.mat[k][j]%Mo)%=Mo;
	 return c;
}
inline Node operator *(Node a,int b)
{
	  int i,j;
	  for (i=0;i<a.lenx;++i)
	    for (j=0;j<a.leny;++j)
	      a.mat[i][j]=1ll*a.mat[i][j]*b%Mo;
	  return a;
}
void change(int t,int c)
{
	Node A={0}; A.lenx=1;A.leny=2; A.mat[0][1]=c;
	tree[t]=tree[t]+(A*C[len[t]]);
	(add[t]+=c)%=Mo;
}
void down(int t)
{
	 if (!add[t]) return;
	 change(ls,add[t]); change(rs,add[t]);
	 add[t]=0;
}
void build_tree(int l,int r,int t)
{
	  len[t]=r-l+1;
	 if (l==r)
	 {
	 	 tree[t].lenx=1; tree[t].leny=2;
	 	 tree[t].mat[0][1]=a[l];
	 	 tree[t]=tree[t]*B[1];
	 }
	 else 
	 {
	 	  build_tree(l,mid,ls); build_tree(mid+1,r,rs);
	 	  tree[t]=tree[ls]+(tree[rs]*B[len[ls]]);
	 }
}
void update(int ll,int c,int l,int r,int t)
{
	 if (l==r) 
	 {
	 	 tree[t].mat[0][0]=0; tree[t].mat[0][1]=c;
	 	 tree[t]=tree[t]*B[1];
	 }
	 else 
	 {
	 	  down(t);
	 	  if (ll<=mid) update(ll,c,l,mid,ls);
	 	  else update(ll,c,mid+1,r,rs);
	 	  tree[t]=tree[ls]+(tree[rs]*B[len[ls]]);
	 }
}
void ask(int ll,int rr,int l,int r,int t)
{
	  if (ll<=l&&r<=rr) Ans=Ans+(tree[t]*B[l-ll]);
	  else 
	  {
	  	 down(t);
	  	 if (ll<=mid) ask(ll,rr,l,mid,ls);
	  	 if (rr>mid)  ask(ll,rr,mid+1,r,rs);
	  }
}
void modify(int ll,int rr,int c,int l,int r,int t)
{
	 if (ll<=l&&r<=rr) change(t,c);
	 else 
	 {
	 	down(t);
	 	if (ll<=mid) modify(ll,rr,c,l,mid,ls);
	 	if (rr>mid)  modify(ll,rr,c,mid+1,r,rs);
	 	tree[t]=tree[ls]+(tree[rs]*B[len[ls]]);
	 }
}
int main()
{
	  scanf("%d%d",&n,&m);
	  B[0].lenx=B[0].leny=2; B[0].mat[0][0]=1; B[0].mat[1][1]=1;
	  B[1].mat[0][1]=1; B[1].mat[1][1]=1;
	  B[1].mat[1][0]=1; B[1].lenx=B[1].leny=2;
	  for (i=2;i<=n;++i) B[i]=B[i-1]*B[1];
	  C[1]=B[1]; for (i=2;i<=n;++i) C[i]=B[i]+C[i-1];
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  build_tree(1,n,1); Ans.lenx=1;Ans.leny=2;
	  for (;m--;)
	  {
	  	 scanf("%d",&type);
	  	 if (type==1)
	  	 {
	  	 	  scanf("%d%d",&u,&x);
	  	 	  update(u,x,1,n,1);
	  	 }
	  	 else if (type==2)
	  	 {
	  	 	 scanf("%d%d",&l,&r);
	  	 	 memset(Ans.mat,0,sizeof(Ans.mat));
	  	 	 ask(l,r,1,n,1);
	  	 	 printf("%d\n",Ans.mat[0][0]);
	  	 }
	  	 else if (type==3)
	  	 {
	  	 	 scanf("%d%d%d",&l,&r,&x);
	  	 	 modify(l,r,x,1,n,1);
	  	 }
      }
}