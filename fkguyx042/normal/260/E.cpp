#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
#define M 10000005

#define mid ((l+r)>>1)
#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r

using namespace std;
int i,j,m,n,p,k,tot,X[N],Y[N],x[N],y[N],root[N],a[5],id[10],vis[10],R[10];
struct Node{int x,y;}A[N];
struct Tre{int l,r,sum;}tree[M];
inline bool cmp(Node a,Node b)
{
	 if (a.x!=b.x) return a.x<b.x;
	 return a.y<b.y;
}
void update(int ll,int l,int r,int t,int t1)
{
	 if (l==r) tree[t].sum++;
	 else
	 {
	 	   if (ll<=mid)
	 	   {
	 	   	 ls=++tot;
	 	   	 tree[ls]=tree[Ls];
	 	   	 update(ll,l,mid,ls,Ls);
	 	   }
	 	   else 
	 	   {
	 	   	  rs=++tot;
	 	   	  tree[rs]=tree[Rs];
	 	   	  update(ll,mid+1,r,rs,Rs);
	 	   }
	 	   tree[t].sum=tree[ls].sum+tree[rs].sum;
	 }
}
bool get1()
{
	  int sum=R[id[1]]+R[id[2]]+R[id[3]];
	  int l=1,r=x[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (X[Mid]>=sum) r=Mid;
	  	 else l=Mid;
	  }
	  if (X[r]>sum) return 0; a[1]=r;
	  return 1;
}
bool get2()
{
	  int sum=R[id[1]]+R[id[2]]+R[id[3]]+R[id[4]]+R[id[5]]+R[id[6]];
	  int l=1,r=x[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (X[Mid]>=sum) r=Mid;
	  	 else l=Mid;
	  }
	  if (X[r]>sum) return 0; a[2]=r;
	  return 1;
}
bool get3()
{
	  int sum=R[id[1]]+R[id[4]]+R[id[7]];
	  int l=1,r=y[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (Y[Mid]>=sum) r=Mid;
	  	 else l=Mid;
	  }
	  if (Y[r]>sum) return 0; a[3]=r;
	  return 1;
}
bool get4()
{
	  int sum=R[id[1]]+R[id[4]]+R[id[7]]+R[id[2]]+R[id[8]]+R[id[5]];
	  int l=1,r=y[0]+1,Mid=0;
	  while ((l+r)>>1!=Mid)
	  {
	  	 Mid=(l+r)>>1;
	  	 if (Y[Mid]>=sum) r=Mid;
	  	 else l=Mid;
	  }
	  if (Y[r]>sum) return 0; a[4]=r;
	  return 1;
}
int ask(int ll,int rr,int l,int r,int t,int t1)
{
	 if (ll<=l&&r<=rr) return tree[t].sum-tree[t1].sum;
	 else 
	 {
	 	 int sum=0;
	 	 if (ll<=mid) sum+=ask(ll,rr,l,mid,ls,Ls);
	 	 if (rr>mid)  sum+=ask(ll,rr,mid+1,r,rs,Rs);
	 	 return sum;
	 }
}
void check()
{
/*	  if (R[id[1]]==1&&R[id[2]]==2&&R[id[3]]==2&&R[id[4]]==1&&R[id[5]]==2&&
	  R[id[6]]==2&&R[id[7]]==1&&R[id[8]]==3&&R[id[9]]==1)
	   a[1]=a[1];
*/
	  if (ask(1,a[3],1,y[0],root[a[1]],root[0])!=R[id[1]]||ask(1,a[3],1,y[0],root[a[2]],root[a[1]])!=R[id[4]]
	  ||ask(1,a[3],1,y[0],root[x[0]],root[a[2]])!=R[id[7]]||ask(a[3]+1,a[4],1,y[0],root[a[1]],0)!=R[id[2]]
	  ||ask(a[3]+1,a[4],1,y[0],root[a[2]],root[a[1]])!=R[id[5]]||ask(a[3]+1,a[4],1,y[0],root[x[0]],root[a[2]])!=R[id[8]]
      ||ask(a[4]+1,y[0],1,y[0],root[a[1]],0)!=R[id[3]]||ask(a[4]+1,y[0],1,y[0],root[a[2]],root[a[1]])!=R[id[6]])
      return;
      printf("%.10lf %.10lf\n%.10lf %.10lf\n",x[a[1]]+0.5,x[a[2]]+0.5,y[a[3]]+0.5,y[a[4]]+0.5);
      exit(0);
}
void dfs(int x)
{
	if (x>9) check();
	else 
	{
		if (x==4)  if (!get1()) return;
		if (x==7)  if (!get2()) return;
		if (x==8)  if (!get3()) return;
		if (x==9)  if (!get4()) return;
		int i;
		for (i=1;i<=9;++i)
		 if (!vis[i])
		 {
		 	 vis[i]=1; id[x]=i;
		 	 dfs(x+1);
		 	 vis[i]=0;
		 }
	}
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d%d",&A[i].x,&A[i].y),x[++x[0]]=A[i].x,y[++y[0]]=A[i].y;
	for (i=1;i<=9;++i) scanf("%d",&R[i]);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	x[0]=unique(x+1,x+n+1)-(x+1);
	y[0]=unique(y+1,y+n+1)-(y+1);
	for (i=1;i<=n;++i)
	A[i].x=lower_bound(x+1,x+x[0]+1,A[i].x)-x,
	A[i].y=lower_bound(y+1,y+y[0]+1,A[i].y)-y;
	sort(A+1,A+n+1,cmp);
	j=1;
	for (i=1;i<=x[0];++i)
	{
		 root[i]=++tot;
		 tree[tot]=tree[root[i-1]];
		 for (;j<=n&&A[j].x==i;++j)
		 {
		 	 int Root=++tot;
		 	 tree[Root]=tree[root[i]];
		 	 update(A[j].y,1,y[0],Root,root[i]);
		 	 root[i]=Root;
		 }
	}
	for (i=1;i<=n;++i) X[A[i].x]++,Y[A[i].y]++;
    for (i=1;i<=x[0];++i) X[i]+=X[i-1];
    for (i=1;i<=y[0];++i) Y[i]+=Y[i-1];
    dfs(1);
    printf("-1");
}