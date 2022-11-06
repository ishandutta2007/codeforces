#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
char str[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str+1);
		int n=strlen(str+1);
		int ans=0;
		for(int i=1;i<=n-2;i++)
		if(str[i]=='t' && str[i+1]=='w' && str[i+2]=='o')
		{
			if(i!=n-2 && str[i+3]=='o') ans++,str[i+1]='*';
			else ans++,str[i+2]='*';
		}
		for(int i=n-2;i>=1;i--)
		if(str[i]=='o' && str[i+1]=='n' && str[i+2]=='e')
		{
			if(i!=1 && str[i-1]=='o') ans++,str[i+1]='*';
			else ans++,str[i]='*';
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		if(str[i]=='*') printf("%d ",i);
		puts("");
	}
	return 0;
}