#include<cstdio>
const int MAXN = 1e5 + 5;

char s[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1; i<=n; ++i)
	{
		int x=s[i]-'a', y='z'-s[i];
		if(x>=y)
		{
			if(x>=m)
			{
				s[i]-=m;
				printf("%s",s+1);
				return 0;
			}
			m-=x;
			s[i]='a';
		}
		else
		{
			if(y>=m)
			{
				s[i]+=m;
				printf("%s",s+1);
				return 0;
			}
			m-=y;
			s[i]='z';
		}
	}
	if(m) printf("-1");
	else printf("%s",s+1);
	return 0;
}