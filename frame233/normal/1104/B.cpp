#include<cstdio>
#include<cstring>
char s[100005],st[100005];
int top;
int main()
{
	scanf("%s",s+1);
	int l=strlen(s+1),cnt=0;
	for(int i=1;i<=l;++i)
	{
		if(top&&st[top]==s[i])
		{
			--top,++cnt;
		}
		else
		{
			st[++top]=s[i];
		}
	}
	printf(cnt&1?"Yes\n":"No\n");
	return 0;
}