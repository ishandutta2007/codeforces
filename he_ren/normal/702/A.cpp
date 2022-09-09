#include<cstdio>
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int ans=0;
	for(int i=1,now=0; i<=n; ++i)
	{
		if(a[i]>a[i-1]) ++now;
		else now=1;
		chk_max(ans,now);
	}
	printf("%d",ans);
	return 0;
}