#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int s[2000010];
int main()
{
	scanf("%d%d",&n,&k);
	int m=1000000000;
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		m=min(m,x);
		s[x]++;
	}
	for (int i=1;i<=1000000+k;i++) s[i]+=s[i-1];
	if (m<=k+1)
	{
		printf("%d\n",m);
		return 0;
	}
	int res=0;
	for (int ans=k+1;ans<=1000000;ans++)
	{
		int cnt=0;
		for (int i=ans;i<=1000000;i+=ans)
			cnt+=s[i+k]-s[i-1];
		if (cnt==n) res=ans;
	}
	printf("%d\n",res);
	return 0;
}