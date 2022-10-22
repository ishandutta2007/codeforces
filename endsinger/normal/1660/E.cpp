#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,a[N],m,c;
char s[N][N];
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		a[i]=0;
	m=c=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='1')
			{
				c++;
				a[(i-j+n)%n]++;
			}
		}
	}
	for(int i=0;i<=n;i++)
		m=max(m,a[i]);
	printf("%d\n",c-m+n-m);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}