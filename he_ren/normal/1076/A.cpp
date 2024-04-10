#include<cstdio>
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<n; ++i)
	{
		if(s[i]>s[i+1])
		{
			for(int j=1; j<i; ++j) putchar(s[j]);
			for(int j=i+1; j<=n; ++j) putchar(s[j]);
			return 0;
		}
	}
	s[n]=0;
	printf("%s",s+1);
	return 0;
}