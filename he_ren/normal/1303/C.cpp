#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2e2 + 5;

char s[MAXN];
int a[MAXN];
int g[26+5][26+5],deg[26+5];
bool vis[26+5];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'a';
	
	memset(g,0,sizeof(g));
	for(int i=1; i<n; ++i)
		g[a[i]][a[i+1]]=g[a[i+1]][a[i]]=1;
	
	memset(deg,0,sizeof(deg));
	for(int i=0; i<26; ++i)
		for(int j=0; j<26; ++j)
			if(i!=j) deg[i] += g[i][j];
	
	for(int i=0; i<26; ++i)
		if(deg[i]>2)
		{
			printf("NO\n");
			return;
		}
	
	memset(vis,0,sizeof(vis));
	int u=-2;
	for(int i=0; i<26; ++i)
	{
		if(deg[i]==1)
		{
			u=i;
			break;
		}
		if(deg[i]==2) u=-1;
	}
	if(u==-1)
	{
		printf("NO\n");
		return;
	}
	
	printf("YES\n");
	if(u!=-2) while(1)
	{
		putchar(u+'a');
		vis[u]=1;
		bool flag=0;
		for(int i=0; i<26; ++i)
			if(g[u][i] && !vis[i])
			{
				u=i;
				flag=1;
				break;
			}
		if(!flag) break;
	}
	for(int i=0; i<26; ++i)
		if(!vis[i]) putchar(i+'a');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}