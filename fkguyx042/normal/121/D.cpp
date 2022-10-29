#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
#define M 1000005

using namespace std;
typedef long double lb;
const long long lim=(long long)2e18;
int i,j,m,n,p,Ql,Qr,ans;
long long l[N],r[N],Min,k,Q[M];
lb suml,sumr;
void dfs(long long x)
{
	  if (x>lim) return;
	  Q[++Q[0]]=x;
	  dfs(x*10+4); dfs(x*10+7);
}
int check(int x,int y)
{
	 if (Q[y]-Q[x]+1>Min) return 0;
	  while (Ql<=n&&l[Ql]<Q[x]) suml-=l[Ql],++Ql;
	  while (Qr<=n&&r[Qr]<Q[y]) sumr+=r[Qr],++Qr;
	  lb final=suml-(lb)(n-Ql+1)*(lb)Q[x]-sumr+(lb)(Qr-1)*(lb)Q[y];
	  if (final>k) return 0;
	  return 1;
}
int main()
{
	 scanf("%d%I64d",&n,&k); Min=lim;
	 for (i=1;i<=n;++i) scanf("%I64d%I64d",&l[i],&r[i]),Min=min(Min,r[i]-l[i]+1);
	 sort(l+1,l+n+1); sort(r+1,r+n+1);
	 for (i=1;i<=n;++i) suml+=l[i];
	 dfs(4); dfs(7);
	 sort(Q+1,Q+Q[0]+1);
	 int L=1; Ql=Qr=1;
	 for (i=1;i<=Q[0];++i)
	 {
	 	  L=max(L,i);
	 	   while (L<=Q[0]&&check(i,L)) ++L;
	 	   ans=max(ans,L-i);
	 	   if (ans==1)
	 	     ans=1;
	 }
	 printf("%d\n",ans);
}