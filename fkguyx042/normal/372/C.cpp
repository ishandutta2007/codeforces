#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define N 150005
#define M 305

using namespace std;
long long f[2][N];
int a[M],b[M],t[M],i,j,m,n,p,k,Q[N],now,last,L,R,d,l;
void del(long long x)
{
	  while (L<=R&&Q[L]<x) ++L;
}
void Ins(int x)
{
	 while (L<=R&&f[last][Q[R]]<=f[last][x]) --R;
	 Q[++R]=x;
}
void ins(long long x)
{
	  while (l<=n&&l<=x) Ins(l),++l;
}
int main()
{
	 scanf("%d%d%d",&n,&m,&d);
	 for (i=1;i<=m;++i) scanf("%d%d%d",&a[i],&b[i],&t[i]);
	 for (i=1;i<=m;++i)
	 {
	 	 now^=1; last=now^1;
	 	 l=1; L=1,R=0;
	 	 for (j=1;j<=n;++j)
	 	 {
	 	 	 del(j-1ll*(t[i]-t[i-1])*d);
	 	 	 ins(j+1ll*(t[i]-t[i-1])*d);
	 	 	 f[now][j]=f[last][Q[L]]+b[i]-abs(a[i]-j);
	 	 }
	 }
	 long long ans=(long long)-1e18;
	 for (i=1;i<=n;++i) ans=max(ans,f[now][i]);
	 cout<<ans<<endl;
}