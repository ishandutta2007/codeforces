#include<cstdio>
const int MAXN = 1e2 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int ans=n;
	for(int i=2; i<=n; i+=2)
	{
		int mid=i>>1;
		bool flag=1;
		for(int j=1; j<=mid; ++j)
			if(s[j]!=s[j+mid])
			{
				flag=0;
				break;
			}
		if(flag) chk_min(ans, n-i+mid+1);
	}
	printf("%d",ans);
	return 0;
}