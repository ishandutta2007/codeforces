#include<bits/stdc++.h>
using namespace std;
char s[300005];
int n,pre[300005],suf[300005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		s[0]=s[1],s[n+1]=s[n];
		for(int i=1;i<=n;++i)
		{
			if(s[i]==s[i-1])	pre[i]=1;
			else	pre[i]=pre[i-1]+1;
		}
		for(int i=n;i;--i)
		{
			if(s[i]==s[i+1])	suf[i]=1;
			else	suf[i]=suf[i+1]+1;
		}
		for(int i=0;i<=n;++i)
		{
			if(!i)
			{
				if(s[1]=='L')	printf("1");
				else	printf("%d",suf[1]+1);
			}
			else if(i==n)
			{
				if(s[n]=='R')	printf("1");
				else	printf("%d",pre[n]+1);
			}
			else
			{
				int ans=1;
				if(s[i]=='L')	ans+=pre[i];
				if(s[i+1]=='R')	ans+=suf[i+1];
				printf("%d",ans);
			}
			putchar(' ');
		}
		puts("");
	}
	return 0;
}