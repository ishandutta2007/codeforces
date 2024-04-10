#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
using namespace std;
int i,j,m,n,p,k,f[3*N],ans,Ans[N],Last[3*N],id[3*N],Sum[3*N];
struct Node{int l,r,d,val,id;}A[N];
inline bool cmp(Node a,Node b)
{
	  if (a.l+a.r+a.d!=b.l+b.r+b.d) return a.l+a.r+a.d<b.l+b.r+b.d;
	  return a.id<b.id;
}
int main()
{
	 scanf("%d",&n);
	 memset(f,-1,sizeof(f)); f[0]=0;
	 for (i=1;i<=n;++i) scanf("%d%d%d%d",&A[i].val,&A[i].d,&A[i].l,&A[i].r),A[i].id=i;
	 sort(A+1,A+n+1,cmp);
	 for (i=1;i<=n;i=j)
	 {
	 	  for (j=i;j<=n&&A[i].l+A[i].r+A[i].d==A[j].l+A[j].r+A[j].d;++j);
	 	  for (k=i;k<j;++k)
	 	  if (f[A[k].l]!=-1) 
	 	  {
	 	  	  Sum[A[k].id]=id[A[k].l];
	 	  	  if (f[A[k].l+A[k].d]<f[A[k].l]+A[k].val)
	 	  	  {
	 	  	  f[A[k].l+A[k].d]=f[A[k].l]+A[k].val;
	 	  	  Last[A[k].l+A[k].d]=A[k].l;
	 	  	  id[A[k].l+A[k].d]=A[k].id;
	 	      }
	 	  }
	 	  if (f[A[i].l+A[i].r+A[i].d]>ans)
	 	  {
	 	  	  ans=f[A[i].l+A[i].r+A[i].d]; Ans[0]=0;
	 	  	  for (k=id[A[i].l+A[i].r+A[i].d];k;k=Sum[k]) Ans[++Ans[0]]=k;
	 	  }
	 	  for (k=i;k<j;++k) f[A[k].l+A[k].d]=-1,Last[A[k].l+A[k].d]=0,id[A[k].l+A[k].d]=0; f[0]=0;
	 }
	 printf("%d\n",Ans[0]);
	 for (i=Ans[0];i;--i) printf("%d ",Ans[i]);
}