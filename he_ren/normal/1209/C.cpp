#include<cstdio>
const int MAXN = 2e5 + 5;

int n;
char s[MAXN];
int a[MAXN],c[MAXN];

bool chk(int k)
{
	for(int i=1; i<=n; ++i) c[i]=0;
	
	int lst=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]<k)
		{
			if(a[i]<lst) return 0;
			c[i]=1;
			lst=a[i];
		}
	}
	for(int i=n; i>=1; --i)
	{
		if(c[i]) break;
		if(a[i]==k) c[i]=1;
	}
	
	for(int i=1; i<=n; ++i)
	{
		if(!c[i])
		{
			if(a[i]<lst) return 0;
			c[i]=2;
			lst=a[i];
		}
	}
	return 1;
}

void solve(void)
{
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'0';
	
	for(int k=0; k<=9; ++k)
		if(chk(k))
		{
			for(int i=1; i<=n; ++i) printf("%d",c[i]);
			putchar('\n');
			return;
		}
	printf("-\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}