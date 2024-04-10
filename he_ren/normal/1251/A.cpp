#include<cstdio>
#include<cstring>
const int MAXN = 5e2 + 5;

bool can[30];
char s[MAXN];
void solve(void)
{
	memset(can,0,sizeof(can));
	
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	for(int i=1,j=1; j<=n; i=j)
	{
		while(j<=n && s[i]==s[j]) ++j;
		if((j-i)&1) can[s[i]-'a']=1;
	}
	for(int i=0; i<26; ++i)
		if(can[i]) putchar(i+'a');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}