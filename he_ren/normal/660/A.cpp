#include<cstdio>
const int MAXN = 1e3 + 5;

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=1; i<n; ++i)
		if(gcd(a[i],a[i+1])>1) ++ans;
	
	printf("%d\n",ans);
	for(int i=1; i<n; ++i)
	{
		printf("%d ",a[i]);
		if(gcd(a[i],a[i+1])>1) printf("1 ");
	}
	printf("%d",a[n]);
	return 0;
}