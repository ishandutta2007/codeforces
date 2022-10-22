#include<cstdio>
int n,k;
char s[500010];
int main()
{
	scanf("%d %d %s",&n,&k,s+1);
//	int tmp=n;
	for(int i=2;i<=n;++i)
	{
		if(s[i]>s[1])
		{
			n=i-1;
			break;
		}
	}
	int now=1,ls=1;
	for(int i=2;i<=n;++i)
	{
		if(s[1]==s[i])
		{
			int cur=i;
			while(s[now]==s[cur] && cur<n)	++now,++cur;
			if(s[now]>s[cur])	ls=i,i=cur;
			else if(s[now]==s[cur] && cur!=n)	continue;
			else
			{
				cur-=now;
				ls=cur;
				goto ff;
			}
			now=1;
		}
	}
	ls=n;
	ff:;
	for(int i=1;i<=k;++i)
	{
		int x=i%ls;
		if(x==0)	x=ls;
		putchar(s[x]);
	}
	return 0;
}