#include<cstdio>
char s[100005],s1[100005];
int pos;
int main()
{
	int n;
	scanf("%d %s",&n,s+1);
	int num=(n-11)>>1;
	for(int i=1;i<=n&&num;++i)
	{
		if(s[i]=='8')
		{
			s[i]=0;
			--num;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i])
		{
			s1[++pos]=s[i];
		}
	}
	for(int i=1;i<=pos-10;++i)
	{
		if(s1[i]=='8')
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}