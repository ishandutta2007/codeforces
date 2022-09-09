#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];
int aa[MAXN*2], *a=aa+MAXN;

int main(void)
{
	memset(aa,-1,sizeof(aa));
	
	int n;
	scanf("%d%s",&n,s+1);
	
	int now=0,ans=0;
	a[0]=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='0') ++now;
		else --now;
		
		if(a[now]!=-1) chk_max(ans, i-a[now]);
		else a[now]=i;
	}
	printf("%d",ans);
	return 0;
}