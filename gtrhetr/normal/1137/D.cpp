#include<bits/stdc++.h>
using namespace std;

int from[10];
char s[1010][1010];

int main()
{
	while (233)
	{
		fflush(stdout);
		printf("next ");
		for (int i=0;i<9;i++) printf("%d ",i);
		puts("");
		fflush(stdout);
		int k;scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%s",s[i]+1);
		fflush(stdout);
		printf("next ");
		for (int i=0;i<5;i++) printf("%d ",i);
		puts("");
		fflush(stdout);
		scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%s",s[i]+1);
		fflush(stdout);
		for (int i=1;i<=k;i++)
		{
			int len=strlen(s[i]+1);
			for (int j=1;j<=len;j++) from[s[i][j]-'0']=i;
		}
		if (from[0]==from[5]) break;
	}
	while (233)
	{
		printf("next ");
		for (int i=0;i<10;i++) printf("%d ",i);
		puts("");
		fflush(stdout);
		int k;scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%s",s[i]+1);
		fflush(stdout);
		if (k==1) break;
	}
	puts("done");
	fflush(stdout);
	return 0;
}