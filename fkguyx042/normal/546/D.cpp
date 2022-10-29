#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 5000005
const long long inf=(long long)1e15;
const int Mo=(int)1e9+7;
int n,i,m,k,j,tot;
long long sum[N],vis[N],prime[N];
void pre()
{
	  for (i=2;i<N;++i)
	  {
	  	   if (!vis[i])
	  	   {
	  	   	   sum[i]=1;
	  	   	   prime[++tot]=i;
	  	   }
	  	   for (j=1;i*prime[j]<N&&j<=tot;++j)
	  	   {
	  	   	       sum[i*prime[j]]=sum[i]+1; vis[i*prime[j]]=1;
	  	   	       if (i%prime[j]==0) break;
	  	   }
	  }
	  for (i=1;i<N;++i) sum[i]+=sum[i-1];
}
int main()
{
	 pre();
	 scanf("%d",&n);
	 for (;n--;)
	 {
	 	 scanf("%d%d",&i,&j);
	      printf("%d\n",sum[i]-sum[j]);
	 }
}