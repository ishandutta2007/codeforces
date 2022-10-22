#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,l;
char s[MAXN];

int main()
{
	scanf("%d",&l);
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n%l==0)
	{
		bool check=true,same=true;
		for(int i=2;i<=n/l;++i)
		{
			int sp=(i-1)*l,cnt=0;
			for(int j=sp+1;j<=sp+l;++j)
			{
				if(s[j]>s[j-sp])
				{
					check=false;
					break;
				}
				if(s[j]<s[j-sp])
				{
					break;
				}
				++cnt;
			}
			same=same && (cnt==l);
		}
		if(!check || same)
		{
			++s[l];
			int now=l;
			while(s[now]>'9')
			{
				s[now]='0';
				++s[--now];
			}
			if(now==0)
			{	
				int cnt=n/l+1;
				for(int i=1;i<=cnt;++i)
				{
					printf("1");
					for(int j=1;j<l;++j)printf("0");
				}
			}
			else
			{
				for(int i=1;i<=n/l;++i)
				{
					for(int j=1;j<=l;++j)
						printf("%c",s[j]);
				}
			}
		}
		else
		{
			for(int i=1;i<=n/l;++i)
			{
				for(int j=1;j<=l;++j)
					printf("%c",s[j]);
			}
		}
	}
	else
	{
		int cnt=n/l+1;
		for(int i=1;i<=cnt;++i)
		{
			printf("1");
			for(int j=1;j<l;++j)printf("0");
		}
	}
}