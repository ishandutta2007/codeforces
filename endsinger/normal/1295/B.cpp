#include <cstdio>
#define N 100005
int T, n, x, s[N], ok, ans;
char tmp[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		ok=ans=0;
		scanf("%d%d%s", &n, &x, tmp);
		ok=x==0;
		for(int i=1; i<=n; ++i) s[i]=s[i-1]+(tmp[i-1]=='0'?1:-1), ok|=(s[i]==x);
		if(s[n]==0) { puts(ok?"-1":"0"); continue; }
		ans=x==0;
		for(int i=1; i<=n; ++i) ans+=((s[i]-x)%s[n]==0&&(s[i]-x)/s[n]<=0);
		printf("%d\n", ans);
	}
	return 0;
}