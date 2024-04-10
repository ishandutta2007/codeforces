#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 5005
using namespace std;
int i,j,m,n,p,k,sum[N],ans=10000000,Sum[N],Sm[N];
int main()
{
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
	 scanf("%d",&n);
	 for (;n--;) scanf("%d",&p),sum[p]++;
	 for (i=N-2;i;--i) Sum[i]=sum[i]+Sum[i+1];
	 for (i=1;i<N;++i) Sm[i]=sum[i]+Sm[i-1];
	 for (i=1;i<N/2;++i) ans=min(ans,Sm[i-1]+Sum[i*2+1]);
	 printf("%d\n",ans);
}