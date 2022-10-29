#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 505
#define M 205
#define seed 23333

using namespace std;
int i,j,m,n,p,k,A[N*2],a[N],b[N],F[N][N],lastx[N][N],lasty[N][N],c[N*2],Q[N];
struct Node{int sum,x,y;}tree[N*2][N];
int lowbit(int x) { return x&-x; }
void insert(int z,int x,int y,int nu)
{
	  int j; int BB=x;
	  for (;x<=m;x+=lowbit(x))
	      for (j=y;j<=c[0];j+=lowbit(j))
             if (tree[x][j].sum<z)
             {
             	  tree[x][j].sum=z;
             	  tree[x][j].x=nu;
             	  tree[x][j].y=BB;
             }
}
Node ask(int x,int y)
{
	  int j;
	  Node z; z.sum=0; z.x=0; z.y=0;
	  for (;x;x-=lowbit(x))
	     for (j=y;j;j-=lowbit(j))
	       if(tree[x][j].sum>z.sum) z=tree[x][j];
	  return z;
}
int main()
{
	 scanf("%d",&n); for (i=1;i<=n;++i) scanf("%d",&a[i]),c[++c[0]]=a[i];
	 scanf("%d",&m); for (i=1;i<=m;++i) scanf("%d",&b[i]),c[++c[0]]=b[i];
	 sort(c+1,c+c[0]+1); c[0]=unique(c+1,c+c[0]+1)-(c+1);
	 for (i=1;i<=n;++i) a[i]=lower_bound(c+1,c+c[0]+1,a[i])-c;
	 for (i=1;i<=m;++i) b[i]=lower_bound(c+1,c+c[0]+1,b[i])-c;
	 for (i=1;i<=n;++i)
	{
		  if (i==2) 
		    i=2;
		   for (j=1;j<=m;++j)
		     if (a[i]==b[j])
		     {
		     	  Node x=ask(j-1,a[i]-1);
		     	  F[i][j]=x.sum+1;
		     	  lastx[i][j]=x.x;
		     	  lasty[i][j]=x.y;
		     	  insert(F[i][j],j,b[j],i);
		     }
	}
	 int idx=0,idy=0,ans=0;
	 for (i=1;i<=n;++i)
	   for (j=1;j<=m;++j)  
	       if (F[i][j]>ans)
	       {
	       	 ans=F[i][j];
	       	 idx=i;idy=j;
	       }
	 printf("%d\n",ans);
	  while (idx&&idy)
	{
		//  printf("%d ",c[a[idx]]);
		  Q[++Q[0]]=c[a[idx]];
		  int ax=lastx[idx][idy],ay=lasty[idx][idy];
		  idx=ax; idy=ay;
	}
	for (i=Q[0];i;--i) printf("%d ",Q[i]);
}