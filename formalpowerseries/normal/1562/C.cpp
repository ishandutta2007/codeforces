#include<bits/stdc++.h>
using namespace std;
char s[20005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int flag=0;
		for(int i=1;i<=n;++i)	if(s[i]=='0')	flag=1;
		if(!flag)
		{
			printf("%d %d %d %d\n",1,n/2,n-n/2+1,n);
			continue;
		}
		for(int i=1;i<=n/2;++i)
		{
			if(s[i]=='0')
			{
				printf("%d %d %d %d\n",i,n,i+1,n);
				goto ano;
			}
		}
		for(int i=n/2+1;i<=n;++i)
		{
			if(s[i]=='0')
			{
				printf("%d %d %d %d\n",1,i,1,i-1);
				goto ano;
			}
		}
		ano:;
	}
	return 0;
}