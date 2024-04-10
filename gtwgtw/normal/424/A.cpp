#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n,cnt;
char f[205];


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char x=getchar();
		while(x=='\n')x=getchar();
		if(x=='x')f[i]='x';else cnt++,f[i]='X';
	}
	if(cnt==n/2)
	{
		printf("0\n");
		for(int i=1;i<=n;i++)printf("%c",f[i]);
		return 0;
	}
	if(cnt<n/2)
	{
		int tt=0;
		for(int i=1;i<=n&&cnt!=n/2;i++)if(f[i]=='x')f[i]='X',tt++,cnt++;
		printf("%d\n",tt);
		for(int i=1;i<=n;i++)printf("%c",f[i]);
		return 0;
	}
	int tt=0;
	for(int i=1;i<=n&&cnt!=n/2;i++)if(f[i]=='X')f[i]='x',tt++,cnt--;
	printf("%d\n",tt);
	for(int i=1;i<=n;i++)printf("%c",f[i]);
	return 0;
}