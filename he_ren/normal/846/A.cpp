#include<cstdio>
const int MAXN = 100 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0, cnt=0;
	for(int i=0; i<=n; ++i)
	{
		if(!a[i])
		{
			int cnt0=0;
			for(int j=i+1; j<=n; ++j)
				if(!a[j]) ++cnt0;
			chk_max(ans, n-cnt-cnt0);
		}
		else ++cnt;
	}
	printf("%d",ans);
	return 0;
}