#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXN];
int sum[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + (s[i]=='0');
	if(sum[n]==n){ printf("0\n"); return;}
	
	int ans=sum[n];
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; ++j)
			if(sum[i-1]==i-1 && sum[n]-sum[j]==n-j)
			{
				chk_min(ans, sum[j]-sum[i-1]);
			}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}