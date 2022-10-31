#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,m;	
char s[N];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	if (s[i]!=s[i-1]) ans++;
	ans=1LL*ans*n*(m-1);
	for (int i=1,j=1;i<n;i++)
	{
		if (s[i+1]==s[i]) continue;
		if (j<=i)
		{
			j=i+1;
			while (s[j+1]==s[j-1]) j++;
		}
		ans-=j-i;
	}
	printf("%I64d\n",ans);
	return 0;
}