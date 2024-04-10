#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
#include<cstring>
using namespace std;
int n,ans;
int a[623456];
char s[623456];
int main()
{
	// sum min
	// sum1+sum2=0,min1>=0,min2>=sum2
	scanf("%d",&n);
	int m=0;
	for (int i=1;i<=n;i++) 
	{
		scanf("%s",s);
		int len=strlen(s),u=0,v=0;
		for (int j=0;j<len;j++)
		{
			if (s[j]=='(') u++;else u--;
			v=min(u,v);
		}
		if (u>=0&&v<0) continue;
		if (u<=0&&v<u) continue;
	//	printf("%d %d\n",u,v);
		if (u>0)
		{
			if (a[u]<0) ans++,a[u]++;
			else a[u]++;
		}
		else if (u<0) 
		{
			u=-u;
			if (a[u]>0) ans++,a[u]--;
			else a[u]--;
		}
		else
		{
			if (a[u]>0) ans++,a[u]--;
			else a[u]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}