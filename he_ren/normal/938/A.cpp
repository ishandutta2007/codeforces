#include<cstdio>
const int MAXN = 100 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	bool flag=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
		{
			if(flag) continue;
			flag=1;
		}
		else flag=0;
		putchar(s[i]);
	}
	return 0;
}