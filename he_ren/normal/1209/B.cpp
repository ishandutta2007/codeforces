#include<cstdio>
const int MAXN = 100 + 5;
const int MAXT = 1e4;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];
int a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	for(int i=1; i<=n; ++i) s[i]-='0';
	
	int ans=0;
	for(int j=0; j<=MAXT; ++j)
	{
		int cnt=0;
		for(int i=1; i<=n; ++i)
		{
			if(j<b[i]) cnt+=s[i];
			else
			{
				int t=(j-b[i])/a[i];
				cnt+=(t&1)^(s[i]^1);
			}
		}
		chk_max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}