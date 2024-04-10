#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=1,ans=1,k=0;
	for (int i=2;i<=n;i++)
	if (s[i]!=s[i-1])
	{
		cnt=1;
		ans++;
	} else cnt++;
	printf("%d\n",min(ans+2,n));
	return 0;
}