#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 18 + 5;

int n,m;
char a[MAXN],b[MAXN],ans[MAXN];
int t[10 + 5];

bool can(int pos)
{
	if(pos>n) return 1;
	for(int i=0; i<=9; ++i)
	{
		for(int j=1; j<=t[i]; ++j)
		{
			if(b[pos]-'0' > i) return 1;
			if(b[pos]-'0' < i) return 0;
			++pos;
			if(pos>n) return 1;
		}
	}
	return 1;
}

int main(void)
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1); m=strlen(b+1);
	
	sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
	if(m>n)
	{
		printf("%s",a+1);
		return 0;
	}
	
	for(int i=1; i<=n; ++i)
		++t[a[i]-'0'];
	bool flag=1;
	for(int i=1; i<=n; ++i)
	{
		for(char j = flag? b[i]: '9'; j>='0'; --j)
			if(t[j-'0'])
			{
				--t[j-'0'];
				if(flag && j==b[i] && !can(i+1))
				{
					++t[j-'0'];
					continue;
				}
				ans[i]=j;
				if(ans[i]<b[i]) flag=0;
				break;
			}
	}
	printf("%s",ans+1);
	return 0;
}