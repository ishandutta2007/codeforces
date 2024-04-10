#include<cstdio>
#define MN 50
#define MM 1000
char s[MM+5][MN+5];
int u[256],UU[256],U[256];
int main()
{
	int n,m,i,j,cnt=0,ans=0;
	scanf("%d%s%d",&n,s[0]+1,&m);
	for(i=1;i<=n;++i)++u[s[0][i]];
	for(i=1;i<=m;++i)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=n;++j)
			if(s[0][j]=='*'){if(u[s[i][j]])break;}
			else if(s[0][j]!=s[i][j])break;
		if(j>n)
		{
			++cnt;
			for(j=1;j<=n;++j)if(s[0][j]=='*')
				if(UU[s[i][j]]!=i)UU[s[i][j]]=i,++U[s[i][j]];
		}
	}
	for(i='a';i<='z';++i)if(U[i]==cnt)++ans;
	printf("%d",ans);
}