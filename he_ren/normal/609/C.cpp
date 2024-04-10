#include<cstdio>
const int MAXN = 1e5 + 5;

inline int max(int a,int b){ return a>b? a: b;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), sum+=a[i];
	
	int sum2 = sum%n? sum/n+1: sum/n;
	sum/=n;
	
	int ans=0, ans2=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]<sum) ans+=sum-a[i];
		if(a[i]>sum2) ans2+=a[i]-sum2;
	}
	
	printf("%d",max(ans,ans2));
	return 0;
}