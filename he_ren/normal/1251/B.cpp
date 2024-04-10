#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 50 + 5;
const int MAXL = 50 + 5;

int a[MAXN];
char s[MAXL];

void solve(void)
{
	int n;
	scanf("%d",&n);
	int c0=0,c1=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		a[i]=l;
		for(int i=1; i<=l; ++i)
		{
			if(s[i]=='0') ++c0;
			else ++c1;
		}
	}
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
	{
		int mid = a[i]>>1;
		if(c0 >= mid*2)
		{
			c0-=mid*2;
			continue;
		}
		mid -= c0/2;
		c0&=1;
		if(c1 >= mid*2)
		{
			c1-=mid*2;
			continue;
		}
		else
		{
			printf("%d\n",i-1);
			return;
		}
	}
	printf("%d\n",n);
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}