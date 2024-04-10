#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n	2005
#define For(i,a,b)	for(int i=a;i<=b;i++)

int		N,M,K,F[n];

int		Get(int u){
		if	(F[u]==u)	return	u;
		return	F[u]=Get(F[u]);
}
void	Merge(int u,int v){
		int fx=Get(u),fy=Get(v);
		if	(fx!=fy)	F[fx]=fy;
}

int		main(){
		scanf("%d%d%d",&N,&M,&K);
		For(i,1,N)	F[i]=i;

		For(i,1,N-K+1)	{
			int l=i,r=i+K-1;
			For(k,1,K/2)	Merge(l+k-1,r-k+1);
		}

		int Ans=1;
		For(i,1,N)	if	(Get(i)==i)	Ans=1ll*Ans*M%1000000007;
		printf("%d\n",Ans);
}