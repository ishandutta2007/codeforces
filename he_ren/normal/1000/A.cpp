#include<cstdio>
#include<cstring>

char s[10];
int t[10][26];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		int l=strlen(s+1), c=s[l]-'A';
		++t[l][c];
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		int l=strlen(s+1), c=s[l]-'A';
		--t[l][c];
	}
	
	int ans=0;
	for(int i=1; i<=4; ++i)
		for(int j=0; j<26; ++j)
			if(t[i][j]>0) ans+=t[i][j];
	printf("%d",ans);
	return 0;
}