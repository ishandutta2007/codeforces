#include<cstdio>
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],t[MAXN],s[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&t[i]);
	
	int sum=0;
	for(int i=1; i<=n; ++i)
	{
		s[i]=s[i-1];
		if(t[i]) sum+=a[i];
		else s[i]+=a[i];
	}
	
	int ans=sum;
	for(int i=1; i<=n-d+1; ++i)
		chk_max(ans, sum+s[i+d-1]-s[i-1]);
	printf("%d",ans);
	return 0;
}