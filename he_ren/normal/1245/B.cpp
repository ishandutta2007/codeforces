#include<cstdio>
#include<cstring>
const int MAXN = 100 + 5;

inline int min(int a,int b){ return a<b? a: b;}

int n,a,b,c;
char s[MAXN],t[MAXN];

void solve(void)
{
	scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
	
	memset(t,0,sizeof(t));
	int cnt=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='R' && b) t[i]='P', --b, ++cnt;
		if(s[i]=='P' && c) t[i]='S', --c, ++cnt;
		if(s[i]=='S' && a) t[i]='R', --a, ++cnt;
	}
	if(cnt < ((n+1)>>1))
	{
		printf("NO\n");
		return;
	}
	for(int i=1; i<=n; ++i) if(!t[i])
	{
		if(a) t[i]='R', --a;
		else if(b) t[i]='P', --b;
		else t[i]='S', --c;
	}
	printf("YES\n%s\n",t+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}