#include<cstdio>
#include<cstring>
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	for(int i=2; i<=n; ++i)
	{
		if(s[i]==s[i-1])
		{
			while((s[i]==s[i-1] || s[i]==s[i+1]) && s[i]<'z') ++s[i];
			while((s[i]==s[i-1] || s[i]==s[i+1]) && s[i]>'a') --s[i];
		}
	}
	printf("%s",s+1);
	return 0;
}