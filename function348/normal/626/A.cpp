#include<cstdio>
#include<iostream>
using namespace std;
int n,ans;
char s[1000];
int a[1000][1000];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	a[300][300]=1;
	int x=0,y=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='U') y++;
		if (s[i]=='D') y--;
		if (s[i]=='L') x--;
		if (s[i]=='R') x++;
		a[x+300][y+300]++;
	}
	for (int i=100;i<=500;i++)
	for (int j=100;j<=500;j++)
		ans+=a[i][j]*(a[i][j]-1)/2;
	cout<<ans<<endl;
	return 0;
}