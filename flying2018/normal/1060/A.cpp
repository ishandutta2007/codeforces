#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char str[110];
	scanf("%s",str);
	int cnt=0;
	for(int i=0;i<n;i++)
	if(str[i]=='8') cnt++;
	int ans=0;
	for(int i=1;i<=cnt;i++)
		ans=max(ans,min(i,(n-i)/10));
	printf("%d",ans);
	return 0;
}