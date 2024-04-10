#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005
using namespace std;
const long long lim=(long long)1e10;
long long Q[N];
long long ans;
int l,r,tot;
void dfs(long long x)
{
	  if (x>lim) return;
	  Q[++Q[0]]=x;
	  dfs(x*10+4); dfs(x*10+7);
}
long long cal(int n)
{
	  int i;
	    long long ans=0;  
		for (i=1;i<=tot;++i) 
	   if (Q[i-1]<n) ans+=1ll*min(Q[i]-Q[i-1],n-Q[i-1])*Q[i];
	   return ans;
}
int main()
{
	dfs(4); dfs(7);
	scanf("%d%d",&l,&r);
	sort(Q+1,Q+Q[0]+1); tot=Q[0]; Q[0]=0;
	printf("%I64d\n",cal(r)-cal(l-1));
}