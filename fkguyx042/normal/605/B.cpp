#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,k,L[N],tot,x[N],y[N],now;
struct Node{int dis,type,id;}A[N];
inline bool cmp(Node a,Node b) { 
  if (a.dis!=b.dis) return a.dis<b.dis;
  return a.type>b.type;
}
int main()
{
	 scanf("%d%d",&n,&m); tot=1; now=2;
	 for (i=1;i<=m;++i) scanf("%d%d",&A[i].dis,&A[i].type),A[i].id=i;
	 sort(A+1,A+m+1,cmp);
	 for (i=1;i<=n;++i) L[i]=i-2;
	 for (i=1;i<=m;++i)
	   if (A[i].type)
	   {
	   	  ++tot;
	   	  x[A[i].id]=tot-1;
	   	  y[A[i].id]=tot;
	   }
	   else 
	   {
	   	   while (now<=tot&&!L[now]) ++now;
	   	   if (now>tot) { printf("-1\n"); return 0; }
	   	   x[A[i].id]=now; y[A[i].id]=L[now]; --L[now];
	   }
	  for (i=1;i<=m;++i) printf("%d %d\n",x[i],y[i]);
}