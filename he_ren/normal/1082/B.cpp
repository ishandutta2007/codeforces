#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];
int a[MAXN],sum[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i)
		a[i] = (s[i]=='G');
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	bool flag=1;
	int ans=0;
	for(int i=1,j=1; i<=n; ++i)
	{
		while(j<=n && (a[j]||flag))
			if(!a[j++]) flag=0;
		
		int now=j-i;
		if(sum[i-1]+sum[n]-sum[j-1]==0 && !flag) --now;
		chk_max(ans,now);
		if(!a[i]) flag=1;
	}
	printf("%d",ans);
	return 0;
}