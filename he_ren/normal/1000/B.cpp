#include<cstdio>
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],sum[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[++n]=m;
	
	for(int i=1; i<=n; ++i)
	{
		sum[i]=sum[i-1];
		if(i&1) sum[i] += a[i]-a[i-1];
	}
	
	int ans=sum[n];
	for(int i=0; i<n; ++i)
	{
		if(a[i]+1 == a[i+1]) continue;
		int res = sum[i] + a[i+1]-a[i]-1 + (m-a[i+1])-(sum[n]-sum[i+1]);
		chk_max(ans,res);
	}
	printf("%d",ans);
	return 0;
}