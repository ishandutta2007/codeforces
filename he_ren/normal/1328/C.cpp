#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e4 + 5;

char s[MAXN];
char a[MAXN],b[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	bool flag=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='0') a[i]=b[i]='0';
		if(s[i]=='1')
		{
			if(flag) a[i]='0', b[i]='1';
			else a[i]='1', b[i]='0', flag=1;
		}
		if(s[i]=='2')
		{
			if(flag) a[i]='0', b[i]='2';
			else a[i]=b[i]='1';
		}
	}
	a[n+1]=b[n+1]=0;
	printf("%s\n%s\n",a+1,b+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}